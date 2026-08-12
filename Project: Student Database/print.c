#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[50];
    float marks;
} Student;

int main()
{

    Student s;

    FILE *fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File open failed !");
        return 0;
    }

    // size_t read = fread(&s, sizeof(s), 1, fp);

    // if (read != 1)
    // {
    //     printf("Could not read the file!");
    //     fclose(fp);
    //     return 0;
    // }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("ID: %d\n", s.id);
        printf("Name: %s\n", s.name);
        printf("Marks: %.2f\n", s.marks);
        printf("---------------\n");
    }

    fclose(fp);

    return 0;
}