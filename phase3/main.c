#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    student *students = malloc(n * sizeof(student));
    if (students == NULL)
    {
        printf("Error allocating memory\n");
        return 1;
    }

    int choice;
    student *stu;

    do
    {
        printf("Select an option: \n");
        printf("1. Enter student details and marks\n2. Display the gradecard of the student\n3.Sort students by SGPA\n4.Sort student by Name\n5.Sort student by roll number\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            student_info(students, n);
            ISA1(students, n);
            ISA2(students, n);
            Internals(students, n);
            ESA(students, n);
            total_marks(students, n);
            SGPA(students, n);
            WriteToFile(students, n);
            break;

        case 2:
            ReadFromFile(students, n);
            display_gradecard(students, n);
            break;
        case 3:
            qsort(stu, n, sizeof(student), sort_by_sgpa);
            printf("Students sorted by SGPA.\n");
            break;
        case 4:
            qsort(stu, n, sizeof(student), sort_by_name);
            printf("Students sorted by name.\n");
            break;
        case 5:
            qsort(stu, n, sizeof(student), sort_by_roll_no);
            printf("Students sorted by roll number.\n");
            break;
        case 6:
            break;
            
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 3);

    for (int i = 0; i < n; i++)
    {
        free(students[i].name);
        free(students[i].roll_no);
        free(students[i].isa1);
        free(students[i].isa2);
        free(students[i].internals);
        free(students[i].esa);
        free(students[i].tot_marks);
    }
    free(students);

    return 0;
}
