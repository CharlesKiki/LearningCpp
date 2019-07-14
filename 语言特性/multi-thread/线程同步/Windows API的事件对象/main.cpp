//main.cpp
#include <windows.h>
#include <iostream>

DWORD WINAPI Fun_1(LPVOID p);
DWORD WINAPI Fun_2(LPVOID p);

HANDLE h_event;
unsigned int counter = 0;

int main()
{
    h_event = CreateEvent(nullptr, true, false, nullptr);
    SetEvent(h_event);
    HANDLE h1 = CreateThread(nullptr, 0, Fun_1, nullptr, 0, nullptr);
    std::cout << "Thread 1 started...\n";
    HANDLE h2 = CreateThread(nullptr, 0, Fun_2, nullptr, 0, nullptr);
    std::cout << "Thread 2 started...\n";
    CloseHandle(h1);
    CloseHandle(h2);
    //
    system("pause");
    return 0;
}

DWORD WINAPI Fun_1(LPVOID p)
{
    while (true)
    {
        WaitForSingleObject(h_event, INFINITE);
        ResetEvent(h_event);
        if (counter < 1000)
        {
            ++counter;
            std::cout << "Thread 1 counting " << counter << "...\n";
            SetEvent(h_event);
        }
        else
        {
            SetEvent(h_event);
            break;
        }
    }
    return 0;
}

DWORD WINAPI Fun_2(LPVOID p)
{
    while (true)
    {
        WaitForSingleObject(h_event, INFINITE);
        ResetEvent(h_event);
        if (counter < 1000)
        {
            ++counter;
            std::cout << "Thread 2 counting " << counter << "...\n";
            SetEvent(h_event);
        }
        else
        {
            SetEvent(h_event);
            break;
        }
    }
    return 0;
}