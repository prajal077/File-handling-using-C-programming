#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a[50];
	FILE *p;
	p = fopen("D:\\filehandling\\string.txt", "w+");
	if(p==NULL) {
		printf("file Doesn't exist");
	}
	else {
	printf("Enter the string: ");
	gets(a);
//	fgets(a, 50, p);
//	fputs(a, p);
	fprintf(p, "%s", a);
	}
	fclose(p);	
	return 0;
}
