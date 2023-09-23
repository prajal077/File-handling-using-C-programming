#include<stdio.h>
#include<stdlib.h>
struct students {
	char name[50];
	int roll_no;
	int marks;
};

int main()
{
	struct students s[2], test[2];
	int i=0, check=0, h;
	FILE *p;
	p = fopen("D:\\filehandling\\records.txt", "w+");
	if(p==NULL) {
		printf("Error!");
		exit(0);
	}
	
	for(i=0; i<2; i++) {
		printf("Enter the name of student %d: ", i+1);
		gets(s[i].name);
		printf("\nEnter the roll number: ");
		scanf("%d", &s[i].roll_no);
		printf("\nEnter the marks: ");
		scanf("%d", &s[i].marks);
		fflush(stdin);
	}
	fflush(stdin);
	fwrite(&s, sizeof(struct students), 1, p);
	rewind(p);
	fread(&test, sizeof(struct students), 1, p);
	flag:
	printf("Enter the roll number you want to check: ");
	scanf("%d", &check);
	
	for(i=0; i<2; i++) {
		if(s[i].roll_no==check) {
			h=1;
			break;
		}
		else {
			h=0;
		}
	}
	
	if(h==0) {
		printf("Invalid input.Try again\n");
		goto flag;
	}
	else {
		printf("The name of student of related roll number is %s\n", test[i].name);
		printf("The roll number of related student is %d\n", test[i].roll_no);
		printf("The marks of related student is %d", test[i].marks);
	}
	fclose(p);
	return 0;
}
