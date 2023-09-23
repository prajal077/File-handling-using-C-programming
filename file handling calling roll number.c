#include<stdio.h>
#include<stdlib.h>
struct student {
	char name[50];
	int roll;
	int marks;
};

int main()
{
	int i=0, h=0;
	int check;
	FILE *p;
	p = fopen("D:\\filehandling\\students.dat", "wb+");
	if(p==NULL) {
		printf("file cannot be opened.");
		exit(0);
	}
	
	struct student s[3], test[3];
	for(i=0; i<3; i++) {
		printf("Enter name of student %d: \n", i+1);
		gets(s[i].name);
		fflush(stdin);
		printf("Enter the roll number: \n");
		scanf("%d", &s[i].roll);
		fflush(stdin);
		printf("Enter the marks: ");
		scanf("%d", &s[i].marks);
		fflush(stdin);
	}
	
	fwrite(s, sizeof(s), 1, p);
	rewind(p);
	fread(test, sizeof(struct student), 1, p);
	
	prajal:
	printf("Enter the roll number you wanna have details: \n");
	scanf("%d", &check);
	
	for(i=0; i<3; i++) {
		if(test[i].roll==check) {
			h=1;
			break;
		}
		else{
			h=0;
		}
	}
	if(h==0) {
		printf("Invalid roll number. Try again!\n");
		goto prajal;
	}
	else {
		printf("\nname : %s", test[i].name);
		printf("\nroll number : %d", test[i].roll);
		printf("\marks : %d", test[i].marks);
	}
	fclose(p);
	return 0;
	
}
