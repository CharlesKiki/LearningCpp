/*
    文件功能：递增一个临界区变量
    实验结果：程序运行后多线程将破坏变量的逻辑递增。

*/

#include <thread>
#include <iostream>

void Fun_1(unsigned int &counter);
void Fun_2(unsigned int &counter);

int main()
{
    unsigned int counter = 0;
    std::thread thrd_1(Fun_1, counter);
    std::thread thrd_2(Fun_2, counter);
    thrd_1.join();
    thrd_2.join();
    system("pause");
    return 0;
}

void Fun_1(unsigned int &counter)
{
    while (true)
    {
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

void Fun_2(unsigned int &counter)
{
    while (true)
    {
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