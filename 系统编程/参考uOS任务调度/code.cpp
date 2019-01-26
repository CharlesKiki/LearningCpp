/*$PAGE*/
/*
*********************************************************************************************************
*                                        CHANGE PRIORITY OF A TASK
*
* Description: This function allows you to change the priority of a task dynamically.  Note that the new
*              priority MUST be available.
*              动态的改变任务的优先级，并且新的任务必须是可用的。什么是available？？
* Arguments  : oldp     is the old priority 旧的优先级
*
*              newp     is the new priority  新的优先级
*
* Returns    : 
               返回值声明
               OS_NO_ERR        is the call was successful 如果调用某个方法是成功的
*              OS_PRIO_INVALID  if the priority you specify is higher that the maximum allowed 
*                               (i.e. >= OS_LOWEST_PRIO)无效的优先级请求？
*              OS_PRIO_EXIST    if the new priority already exist. 如果新的优先级是已经存在的
*              OS_PRIO_ERR      there is no task with the specified OLD priority (i.e. the OLD task does
*                               not exist.如果要执行优先级改变的任务是不存在的
*********************************************************************************************************
*/

//注意，这是一个宏
#if OS_TASK_CHANGE_PRIO_EN
/*
	Arguments：接受两个参数，新的优先级，旧的优先级
	Commit：这个方法不接受一个指定的任务的话，怎么改变这个任务的优先级？

*/
INT8U OSTaskChangePrio (INT8U oldprio, INT8U newprio) REENTRANT
{
    /*
        commit:对变量初始化
        进程管理模块结构体
        x,y和任务的准备状态有关
    */
    OS_TCB   DT_XDATA *ptcb;
    OS_EVENT DT_XDATA *pevent;
    INT8U     x;
    INT8U     y;
    INT8U     bitx;
    INT8U     bity;

    //某种优先级的对比
    if ((oldprio >= OS_LOWEST_PRIO && oldprio != OS_PRIO_SELF)  || 
         newprio >= OS_LOWEST_PRIO) {
        return (OS_PRIO_INVALID);   //第一个返回状态
    }

    /*
        进入临界段，保护代码不受中断打断。
    */
    OS_ENTER_CRITICAL();

    //针对进程控制头结构体进行优先级的修改
    /*
        OSTCBPrioTbl[newprio]，这个数组以优先级为顺序保存了对各任务的访问指针
        新的优先级必须不存在，这意味着如果一个指定的优先级已经被赋予一个任务了，那么不能增加新的优先级
    */
    if (OSTCBPrioTbl[newprio] != (OS_TCB DT_XDATA *)0) {                 /* New priority must not already exist */
        OS_EXIT_CRITICAL();
        return (OS_PRIO_EXIST); //第二个返回状态
    } else {
        //似乎是保存进程上下文？？保留入口以防他人进入
        OSTCBPrioTbl[newprio] = (OS_TCB DT_XDATA *)1;                    /* Reserve the entry to prevent others */
        OS_EXIT_CRITICAL();
        //和中断有关 
        y    = newprio >> 3;                                    /* Precompute to reduce INT. latency   */
        bity = OSMapTbl[y];
        x    = newprio & 0x07;
        bitx = OSMapTbl[x];
        //再次调用进程进入临界区函数
        OS_ENTER_CRITICAL();

        if (oldprio == OS_PRIO_SELF) {                          /* See if changing self                */
            oldprio = OSTCBCur->OSTCBPrio;                      /* Yes, get priority                   */
        }

        //多重if嵌套
        /*
            要改变的任务必须存在
        */
        if ((ptcb = OSTCBPrioTbl[oldprio]) != (OS_TCB DT_XDATA *)0) {    /* Task to change must exist           */
            /*
                去除旧的PCB Process Control Block??，一个任务可能在请求更换优先级的同时被清除出内存？
                清除旧的优先级的方法就是将原来的下标(优先级)置零
            */
            OSTCBPrioTbl[oldprio] = (OS_TCB DT_XDATA *)0;                /* Remove TCB from old priority        */
            //任务存在一个是否ready的状态，这种状态似乎是靠一个bite控制的
            if (OSRdyTbl[ptcb->OSTCBY] & ptcb->OSTCBBitX) {     /* If task is ready make it not ready  */
                if ((OSRdyTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX) == 0) {
                    OSRdyGrp &= ~ptcb->OSTCBBitY;
                }
                OSRdyGrp    |= bity;                            /* Make new priority ready to run      */
                OSRdyTbl[y] |= bitx;
            } else {
                if ((pevent = ptcb->OSTCBEventPtr) != (OS_EVENT DT_XDATA *)0) { /* Remove from event wait list  */
                    if ((pevent->OSEventTbl[ptcb->OSTCBY] &= ~ptcb->OSTCBBitX) == 0) {
                        pevent->OSEventGrp &= ~ptcb->OSTCBBitY;
                    }
                    pevent->OSEventGrp    |= bity;              /* Add new priority to wait list 等待队列       */
                    pevent->OSEventTbl[y] |= bitx;
                }
            }

            //将新的任务控制块存入优先级数组中
            OSTCBPrioTbl[newprio] = ptcb;                       /* Place pointer to TCB @ new priority */
            ptcb->OSTCBPrio       = newprio;                    /* Set new task priority               */
            ptcb->OSTCBY          = y;
            ptcb->OSTCBX          = x;
            ptcb->OSTCBBitY       = bity;
            ptcb->OSTCBBitX       = bitx;
            //退出临界区
            OS_EXIT_CRITICAL();
            OSSched();                                          /* Run highest priority task ready     */
            return (OS_NO_ERR); //第三个返回状态
        } else {
            //如果要操作的任务不存在
            OSTCBPrioTbl[newprio] = (OS_TCB DT_XDATA *)0;                /* Release the reserved prio.          */
            OS_EXIT_CRITICAL();
            return (OS_PRIO_ERR);   //第四个返回状态                               /* Task to change didn't exist         */
        }
    }
}
#endif