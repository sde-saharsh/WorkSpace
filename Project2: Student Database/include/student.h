#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

void addStudent();
void showStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void findTopper();
void showAverage();
void sortStudents();

#endif