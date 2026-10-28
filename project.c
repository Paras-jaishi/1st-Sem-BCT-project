
#include <stdio.h>
#include <string.h>

struct Student
{
    int roll;
    char name[50];
    char branch[30];
    float marks;
};

struct Student s[100];
int count = 0;

void addStudent()
{
    if (count >= 100)
    {
        printf("\nStudent record limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Branch: ");
    scanf(" %[^\n]", s[count].branch);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

void displayStudents()
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records found!\n");
        return;
    }

    printf("\n----- Student Records -----\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRoll Number: %d\n", s[i].roll);
        printf("Name: %s\n", s[i].name);
        printf("Branch: %s\n", s[i].branch);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

void searchStudent()
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Branch: %s\n", s[i].branch);
            printf("Marks: %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

void updateStudent()
{
    int roll, i, found = 0;

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Branch: ");
            scanf(" %[^\n]", s[i].branch);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("\nStudent record updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

void deleteStudent()
{
    int roll, i, j, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (i = 0; i < count; i++)
    {
        if (s[i].roll == roll)
        {
            for (j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;

            printf("\nStudent record deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nExiting Student Management System...\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}