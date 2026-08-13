#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/student.h"

#define STUDENT_FILE "data/student.dat"
#define TEMP_FILE "data/temp.dat"


void addStudent()
{
    Student s;

    printf("Enter id: ");
    scanf("%d", &s.id);

    printf("Enter name: ");
    scanf("%49s", s.name);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    FILE *fp = fopen(STUDENT_FILE, "ab");

    if(fp == NULL)
    {
        printf("File not opened! ERROR\n");
        return;
    }

    size_t written = fwrite(&s, sizeof(s), 1, fp);

    if(written != 1)
    {
        printf("Student not added!\n");
        fclose(fp);
        return;
    }

    fclose(fp);

    printf("Student added successfully!\n");
}



void showStudent()
{
    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    Student s;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("\nID    : %d\n", s.id);
        printf("Name  : %s\n", s.name);
        printf("Marks : %.2f\n", s.marks);
        printf("----------------------\n");
    }

    fclose(fp);
}


void searchStudent()
{
    int searchId;

    printf("Enter id of student: ");
    scanf("%d", &searchId);

    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    Student s;
    bool found = false;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.id == searchId)
        {
            found = true;

            printf("\nStudent Found!\n");
            printf("ID    : %d\n", s.id);
            printf("Name  : %s\n", s.name);
            printf("Marks : %.2f\n", s.marks);
            printf("----------------------\n");

            break;
        }
    }

    if(!found)
    {
        printf("Student not found!\n");
    }

    fclose(fp);
}



void updateStudent()
{
    int searchId;

    printf("Enter id of student to update: ");
    scanf("%d", &searchId);

    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    FILE *temp = fopen(TEMP_FILE, "wb");

    if(temp == NULL)
    {
        printf("Temporary file could not be created!\n");
        fclose(fp);
        return;
    }

    Student s;
    bool found = false;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.id == searchId)
        {
            found = true;

            printf("Enter new name: ");
            scanf("%49s", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);
        }

        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove(STUDENT_FILE);
        rename(TEMP_FILE, STUDENT_FILE);

        printf("Student updated successfully!\n");
    }
    else
    {
        remove(TEMP_FILE);

        printf("Student not found!\n");
    }
}


void deleteStudent()
{
    int deleteId;

    printf("Enter id of student to delete: ");
    scanf("%d", &deleteId);

    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    FILE *temp = fopen(TEMP_FILE, "wb");

    if(temp == NULL)
    {
        printf("Temporary file could not be created!\n");
        fclose(fp);
        return;
    }

    Student s;
    bool found = false;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(s.id == deleteId)
        {
            found = true;
            continue;
        }

        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    if(found)
    {
        remove(STUDENT_FILE);
        rename(TEMP_FILE, STUDENT_FILE);

        printf("Student deleted successfully!\n");
    }
    else
    {
        remove(TEMP_FILE);

        printf("Student not found!\n");
    }
}


void findTopper()
{
    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    Student s;
    Student topper;

    bool found = false;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(!found || s.marks > topper.marks)
        {
            topper = s;
            found = true;
        }
    }

    fclose(fp);

    if(found)
    {
        printf("\n========== TOPPER ==========\n");

        printf("ID    : %d\n", topper.id);
        printf("Name  : %s\n", topper.name);
        printf("Marks : %.2f\n", topper.marks);
    }
    else
    {
        printf("No students found!\n");
    }
}



void showAverage()
{
    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    Student s;

    float total = 0;
    int count = 0;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        total += s.marks;
        count++;
    }

    fclose(fp);

    if(count > 0)
    {
        printf("Average Marks = %.2f\n", total / count);
    }
    else
    {
        printf("No students found!\n");
    }
}


void sortStudents()
{
    FILE *fp = fopen(STUDENT_FILE, "rb");

    if(fp == NULL)
    {
        printf("File failed to open!\n");
        return;
    }

    Student *students = NULL;

    int size = 0;
    int capacity = 2;

    students = malloc(capacity * sizeof(Student));

    if(students == NULL)
    {
        printf("Memory allocation failed!\n");
        fclose(fp);
        return;
    }

    Student s;

    while(fread(&s, sizeof(s), 1, fp) == 1)
    {
        if(size == capacity)
        {
            capacity = capacity * 2;

            Student *temp = realloc(
                students,
                capacity * sizeof(Student)
            );

            if(temp == NULL)
            {
                printf("Memory allocation failed!\n");

                free(students);
                fclose(fp);

                return;
            }

            students = temp;
        }

        students[size] = s;
        size++;
    }

    fclose(fp);



    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(students[i].marks < students[j].marks)
            {
                Student temp = students[i];

                students[i] = students[j];

                students[j] = temp;
            }
        }
    }


    printf("\n========== SORTED STUDENTS ==========\n");

    for(int i = 0; i < size; i++)
    {
        printf(
            "ID: %d | Name: %s | Marks: %.2f\n",
            students[i].id,
            students[i].name,
            students[i].marks
        );
    }

    free(students);
}