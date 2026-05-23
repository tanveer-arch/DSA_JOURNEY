#include<stdio.h>
#include<string.h>

struct Student{
    int rollno;
    int marks;
    char name[50];
    char grade;
};

int main(void){
    int max =100;
    struct Student students[max];
    int n,i;
    char searchName[50];
    int found =0;
    
    printf("Enter the number of students: ");
    scanf("%d",&n);
    
    for (i=0;i<n;i++){
        printf("Enter details for students %d\n",i+1);
        printf("Enter the roll number of the student: ");
        scanf("%d",&students[i].rollno);
        
        getchar();
        printf("Enter the student name: \n");
        fgets(students[i].name,max,stdin);
        
        printf("Enter the marks: ");
        scanf("%d",&students[i].marks);
    
        printf("Enter the grade of the student:");
        getchar();
        students[i].grade=getchar();
        getchar();
        
    }
    
    printf("Enter the name of the student to be searched: ");
    getchar();
    fgets(searchName,max,stdin);
    
    for (int i=0;i<n;i++){
        if (strcmp(students[i].name,searchName)==0){
            found =1;
            printf("The name of the student is: %s\n",searchName);
            printf("The roll number of the student is: %d/n",students[i].rollno);
            printf("The marks of the student is : %d/n",students[i].marks);
            printf("The Grade of the student is : %c/n",students[i].grade);
        }
        
    }
    
    if (found==0){
        printf("Such name could not be found!!!/n");
    }
    int 
    return 0; 
}