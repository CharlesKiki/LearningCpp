/*
Use gcc to compile 
gcc -g -o Main main.cpp swap.cpp  will create a executable file
gcc -S main.cpp  will creat a assembling file
*/

void swap();

int buf[2] = {1,2};

int main()
{
	swap();
	while(1);
	return 0;
}
