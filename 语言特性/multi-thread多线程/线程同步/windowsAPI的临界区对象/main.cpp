//main.cpp
#include <windows.h>
#include <iostream>
#include "header.h"

DWORD WINAPI Fun_1(LPVOID p);
DWORD WINAPI Fun_2(LPVOID p);

unsigned int counter = 0;
RAII_CrtcSec cs;

int main()
{
    HANDLE h1, h2;
    h1 = CreateThread(nullptr, 0, Fun_1, nullptr, 0, 0);
    std::cout << "Thread 1 started...\n";
    h2 = CreateThread(nullptr, 0, Fun_2, nullptr, 0, 0);
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
        cs.Lock();
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Thread 1 counting " << counter << "...\n";
            cs.Unlock();
        }
        else
        {
            cs.Unlock();
            break;
        }
    }
    return 0;
}

DWORD WINAPI Fun_2(LPVOID p)
{
    while (true)
    {
        cs.Lock();
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Thread 2 counting " << counter << "...\n";
            cs.Unlock();
        }
        else
        {
            cs.Unlock();
            break;
        }
    }
    return 0;
}