extern int buf[];
/*extern word means this file reference this variable from other code file*/

int *bufp0 = &buf[0];
int *bufp1;

void swap()
{
	int temp;
	
	bufp1 = &buf[1];
	temp = *bufp0;
	*bufp0 = *bufp1;
	*bufp1 = temp;
}
