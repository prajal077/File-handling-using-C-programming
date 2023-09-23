#include<stdio.h>
#include<stdlib.h>
struct student{
	char name[50];
	int roll;
	int marks;
};

int main()
{
	int i=0;
	FILE *p;
	p = fopen("D:\\filehandling\\structure.dat", "wb+");
	if(p==NULL) {
		printf("ERROTR");
		exit(0);
	}
	
	struct student s[3], t;
	for(i=0; i<3; i++) {
		printf("Enter the name of student %d: \n", i+1);
		gets(s[i].name);
	//	fgets(s[i].name, sizeof(s[i].name), stdin);

		fflush(stdin);
		printf("Enter the roll number: \n");
		scanf("%d", &s[i].roll);
		fflush(stdin);
		printf("Enter the marks: \n");
		scanf("%d", &s[i].marks);
		fflush(stdin);
	}
	
	
	fwrite(s, sizeof(s), 1, p);
	rewind(p);
	while(fread(&t, sizeof(struct student), 1, p)) {
		/*printf("name is : %s", t.name);
		printf("\nroll number is: %d", t.roll);
		printf("\nmarks is: %d", t.marks);*/
		
		printf("\n%s \t\n%d \t\n%d", t.name, t.roll, t.marks);
	}
	fclose(p);
	return 0;
}

