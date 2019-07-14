#include <thread>
#include <mutex>
#include <iostream>

void Fun_1();
void Fun_2();

unsigned int counter = 0;
std::mutex mtx;

int main()
{
    std::thread thrd_1(Fun_1);
    std::thread thrd_2(Fun_2);
    thrd_1.join();
    thrd_2.join();
    system("pause");
    return 0;
}

void Fun_1()
{
    while (true)
    {
        std::lock_guard<std::mutex> mtx_locker(mtx);
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Function 1 counting " << counter << "...\n";
        }
        else
        {
            break;
        }
    }
}

void Fun_2()
{
    while (true)
    {
        std::lock_guard<std::mutex> mtx_locker(mtx);
        ++counter;
        if (counter < 1000)
        {
            std::cout << "Function 2 counting " << counter << "...\n";
        }
        else
        {
            break;
        }
    }
}