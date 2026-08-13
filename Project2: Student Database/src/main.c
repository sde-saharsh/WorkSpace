#include <stdio.h>
#include "../include/student.h"

int main()
{
    int choice;

    while(1)
    {
        printf("\n========== STUDENT DATABASE ==========\n");
        printf("1. Add Student\n");
        printf("2. Show All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Find Topper\n");
        printf("7. Show Average Marks\n");
        printf("8. Sort Students\n");
        printf("9. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            addStudent();
        }
        else if(choice == 2)
        {
            showStudent();
        }
        else if(choice == 3)
        {
            searchStudent();
        }
        else if(choice == 4)
        {
            updateStudent();
        }
        else if(choice == 5)
        {
            deleteStudent();
        }
        else if(choice == 6)
        {
            findTopper();
        }
        else if(choice == 7)
        {
            showAverage();
        }
        else if(choice == 8)
        {
            sortStudents();
        }
        else if(choice == 9)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}