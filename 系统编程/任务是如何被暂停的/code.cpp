/*$PAGE*/
/*
*********************************************************************************************************
*                                            SUSPEND A TASK
*
* Description: This function is called to suspend a task.  The task can be the calling task if the
*              priority passed to OSTaskSuspend() is the priority of the calling task or OS_PRIO_SELF.
               调用此函数来挂起任务。
               如果传递给OSTaskSuspend()的优先级是调用任务或OS_PRIO_SELF的优先级，则该任务可以是调用任务。
*
* Arguments  : prio     is the priority of the task to suspend.  If you specify OS_PRIO_SELF, the
*                       calling task will suspend itself and rescheduling will occur.
*
* Returns    : OS_NO_ERR                if the requested task is suspended
*              OS_TASK_SUSPEND_IDLE     if you attempted to suspend the idle task which is not allowed.
*              OS_PRIO_INVALID          if the priority you specify is higher that the maximum allowed 
*                                       (i.e. >= OS_LOWEST_PRIO) or, you have not specified OS_PRIO_SELF.
*              OS_TASK_SUSPEND_PRIO     if the task to suspend does not exist
*
* Note       : You should use this function with great care.  If you suspend a task that is waiting for
*              an event (i.e. a message, a semaphore, a queue ...) you will prevent this task from
*              running when the event arrives.
*********************************************************************************************************
*/

#if OS_TASK_SUSPEND_EN
/*
    该方法返回类型INT8U的执行状态
    OS_TASK_SUSPEND_IDLE
    OS_PRIO_INVALID
    OS_TASK_SUSPEND_PRIO
    OS_NO_ERR，执行正确

    接受一个优先级下标，这个下标指向一个任务的地址
*/
INT8U OSTaskSuspend (INT8U prio) REENTRANT
{
    BOOLEAN   self;
    OS_TCB   DT_XDATA *ptcb;

    //不允许挂起空闲任务
    /*
        似乎OS_IDLE_PRIO是一个全局变量，随时都记录一个被挂起的任务，公共的全局资源可能要求有一定的锁来保证数据有效
    */
    if (prio == OS_IDLE_PRIO) {                                 /* Not allowed to suspend idle task    */
        return (OS_TASK_SUSPEND_IDLE);
    }
    //如果指定的优先级大于了最低优先级要求并且自身优先级？？
    if (prio >= OS_LOWEST_PRIO && prio != OS_PRIO_SELF) {       /* Task priority valid ?               */
        return (OS_PRIO_INVALID);
    }

    //开始操作敏感数据，关闭中断
    OS_ENTER_CRITICAL();
    if (prio == OS_PRIO_SELF) {                                 /* See if suspend SELF                 */
       //将当前的任务优先级赋值
        prio = OSTCBCur->OSTCBPrio;
        self = TRUE;
    } else if (prio == OSTCBCur->OSTCBPrio) {                   /* See if suspending self              */
        self = TRUE;
    } else {
        self = FALSE;                                           /* No suspending another task          */
    }

    //如果目标任务不存在则退出方法
    if ((ptcb = OSTCBPrioTbl[prio]) == (OS_TCB DT_XDATA *)0) {                /* Task to suspend must exist     */
        OS_EXIT_CRITICAL();
        return (OS_TASK_SUSPEND_PRIO);
    } else {
        if ((OSRdyTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX) == 0) {     /* Make task not ready            */
            OSRdyGrp &= ~ptcb->OSTCBBitY;
        }
        ptcb->OSTCBStat |= OS_STAT_SUSPEND;                          /* Status of task is 'SUSPENDED'  */
        OS_EXIT_CRITICAL();
        if (self == TRUE) {                                          /* Context switch only if SELF    */
            OSSched();
        }
        return (OS_NO_ERR);
    }
}
#endif