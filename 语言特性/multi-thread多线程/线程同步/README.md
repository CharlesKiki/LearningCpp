第一种实现线程同步的方法：CPP标准库的实现方法
使用C++标准库的thread、mutex头文件：
在两个线程关联的函数中加了一句
std::lock_guard<std::mutex> mtx_locker(mtx);

在C++中，通过构造std::mutex的实例来创建互斥元，可通过调用其成员函数lock()和unlock()来实现加锁和解锁，然后这是不推荐的做法，因为这要求程序员在离开函数的每条代码路径上都调用unlock()，包括由于异常所导致的在内。

作为替代，标准库提供了std::lock_guard类模板，实现了互斥元的RAII惯用语法（资源获取即初始化）。

该对象在构造时锁定所给的互斥元，析构时解锁该互斥元，从而保证被锁定的互斥元始终被正确解锁。

代码运行结果如下图所示，可见得到了正确的结果。

第二种实现线程同步的方法：使用windows API的临界区对象
使用了windows提供的API中的临界区对象来实现线程同步。临界区是指一个访问共享资源的代码段，临界区对象则是指当用户使用某个线程访问共享资源时，必须使代码段独占该资源，不允许其他线程访问该资源。在该线程访问完资源后，其他线程才能对资源进行访问。Windows API提供了临界区对象的结构体CRITICAL_SECTION，对该对象的使用可总结为如下几步：

　　1.InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection)，该函数的作用是初始化临界区，唯一的参数是指向结构体CRITICAL_SECTION的指针变量。

　　2.EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)，该函数的作用是使调用该函数的线程进入已经初始化的临界区，并拥有该临界区的所有权。这是一个阻塞函数，如果线程获得临界区的所有权成功，则该函数将返回，调用线程继续执行，否则该函数将一直等待，这样会造成该函数的调用线程也一直等待。如果不想让调用线程等待（非阻塞），则应该使用TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)。

　　3.LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)，该函数的作用是使调用该函数的线程离开临界区并释放对该临界区的所有权，以便让其他线程也获得访问该共享资源的机会。一定要在程序不适用临界区时调用该函数释放临界区所有权，否则程序将一直等待造成程序假死。

　　4.DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection)，该函数的作用是删除程序中已经被初始化的临界区。如果函数调用成功，则程序会将内存中的临界区删除，防止出现内存错误。
　　
第三种方法：Windows API的事件对象

　　
　　事件对象是一种内核对象，用户在程序中使用内核对象的有无信号状态来实现线程的同步。使用事件对象的步骤可概括如下：

　　1.创建事件对象，函数原型为：
　　
　　HANDLE WINAPI CreateEvent(
  _In_opt_ LPSECURITY_ATTRIBUTES lpEventAttributes,
  _In_     BOOL                  bManualReset,
  _In_     BOOL                  bInitialState,
  _In_opt_ LPCTSTR               lpName
);

如果该函数调用成功，则返回新创建的事件对象，否则返回NULL。函数参数的含义如下：

　　-lpEventAttributes：表示创建的事件对象的安全属性，若设为NULL则表示该程序使用的是默认安全属性。

　　-bManualReset：表示所创建的事件对象是人工重置还是自动重置。若设为true，则表示使用人工重置，在调用线程获得事件对象所有权后用户要显式地调用ResetEvent()将事件对象设置为无信号状态。

　　-bInitialState：表示事件对象的初始状态。如果为true，则表示该事件对象初始时为有信号状态，则线程可以使用事件对象。

　　-lpName：表示事件对象的名称，若为NULL，则表示创建的是匿名事件对象。

　　2.若事件对象初始状态设置为无信号，则需调用SetEvent(HANDLE hEvent)将其设置为有信号状态。ResetEvent(HANDLE hEvent)则用于将事件对象设置为无信号状态。

　　3.线程通过调用WaitForSingleObject()主动请求事件对象，该函数原型如下：
　　
　　1 DWORD WINAPI WaitForSingleObject(
   _In_ HANDLE hHandle,
   _In_ DWORD  dwMilliseconds
    );
　　该函数将在用户指定的事件对象上等待。如果事件对象处于有信号状态，函数将返回。否则函数将一直等待，直到用户所指定的事件到达。
　　
　　线程同步的第四种方法：Windows API的互斥对象
　　
　　互斥对象的使用方法和c++标准库的mutex类似，互斥对象使用完后应记得释放。
　　