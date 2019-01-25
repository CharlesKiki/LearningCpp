/*$PAGE*/
/*
*********************************************************************************************************
*                                        CHANGE PRIORITY OF A TASK
*
* Description: This function allows you to change the priority of a task dynamically.  Note that the new
*              priority MUST be available.
*
* Arguments  : oldp     is the old priority
*
*              newp     is the new priority
*
* Returns    : OS_NO_ERR        is the call was successful
*              OS_PRIO_INVALID  if the priority you specify is higher that the maximum allowed 
*                               (i.e. >= OS_LOWEST_PRIO)
*              OS_PRIO_EXIST    if the new priority already exist.
*              OS_PRIO_ERR      there is no task with the specified OLD priority (i.e. the OLD task does
*                               not exist.
*********************************************************************************************************
*/

#if OS_TASK_CHANGE_PRIO_EN
/*
	Arguments：接受两个参数，新的优先级，旧的优先级
	Commit：这个方法不接受一个指定的任务的话，怎么改变这个任务的优先级？

*/
INT8U OSTaskChangePrio (INT8U oldprio, INT8U newprio) REENTRANT
{
    OS_TCB   DT_XDATA *ptcb;
    OS_EVENT DT_XDATA *pevent;
    INT8U     x;
    INT8U     y;
    INT8U     bitx;
    INT8U     bity;


    if ((oldprio >= OS_LOWEST_PRIO && oldprio != OS_PRIO_SELF)  || 
         newprio >= OS_LOWEST_PRIO) {
        return (OS_PRIO_INVALID);
    }
    OS_ENTER_CRITICAL();
    if (OSTCBPrioTbl[newprio] != (OS_TCB DT_XDATA *)0) {                 /* New priority must not already exist */
        OS_EXIT_CRITICAL();
        return (OS_PRIO_EXIST);
    } else {
        OSTCBPrioTbl[newprio] = (OS_TCB DT_XDATA *)1;                    /* Reserve the entry to prevent others */
        OS_EXIT_CRITICAL();
        y    = newprio >> 3;                                    /* Precompute to reduce INT. latency   */
        bity = OSMapTbl[y];
        x    = newprio & 0x07;
        bitx = OSMapTbl[x];
        OS_ENTER_CRITICAL();
        if (oldprio == OS_PRIO_SELF) {                          /* See if changing self                */
            oldprio = OSTCBCur->OSTCBPrio;                      /* Yes, get priority                   */
        }
        if ((ptcb = OSTCBPrioTbl[oldprio]) != (OS_TCB DT_XDATA *)0) {    /* Task to change must exist           */
            OSTCBPrioTbl[oldprio] = (OS_TCB DT_XDATA *)0;                /* Remove TCB from old priority        */
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
                    pevent->OSEventGrp    |= bity;              /* Add new priority to wait list       */
                    pevent->OSEventTbl[y] |= bitx;
                }
            }
            OSTCBPrioTbl[newprio] = ptcb;                       /* Place pointer to TCB @ new priority */
            ptcb->OSTCBPrio       = newprio;                    /* Set new task priority               */
            ptcb->OSTCBY          = y;
            ptcb->OSTCBX          = x;
            ptcb->OSTCBBitY       = bity;
            ptcb->OSTCBBitX       = bitx;
            OS_EXIT_CRITICAL();
            OSSched();                                          /* Run highest priority task ready     */
            return (OS_NO_ERR);
        } else {
            OSTCBPrioTbl[newprio] = (OS_TCB DT_XDATA *)0;                /* Release the reserved prio.          */
            OS_EXIT_CRITICAL();
            return (OS_PRIO_ERR);                               /* Task to change didn't exist         */
        }
    }
}
#endif