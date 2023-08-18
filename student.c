#include <stdio.h>
struct student
{
    char name[100];
    int roll_no;
    char grade;
};
void studentdetails(struct student students[],int count);
void display(struct student students[],int count);
void sorting(struct student students[],int count);
int main()
{
    struct student students[100];
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    studentdetails(students,n);
    printf("\nStudent Details:\n");
    display(students,n);
    sorting(students,n);
    printf("\nStudent Details after sorting:\n");
    display(students,n);
    return 0;
}
void studentdetails(struct student students[], int count)
{
    for (int i=0; i<count;i++)
    {
        printf("\nEnter details for student %d:\n",i+1);
        printf("Name:");
        scanf("%s",students[i].name);
        printf("Roll Number:");
        scanf("%d",&students[i].roll_no);
        printf("Grade:");
        scanf(" %c",&students[i].grade);
    }
}
void display(struct student students[],int count)
{
    for (int i=0;i<count;i++)
    {
        printf("Name:%s;Roll no:%d;Grade:%c\n",students[i].name,students[i].roll_no,students[i].grade);
    }
}
void sorting(struct student students[],int count)
{
    for(int i=0;i<count-1;i++)
    {
        for (int j=0;j<count-i-1;j++)
        {
            if (students[j].roll_no>students[j + 1].roll_no)
            {
                struct student temp =students[j];
                students[j]=students[j + 1];
                students[j + 1]=temp;
            }
        }
    }
}
