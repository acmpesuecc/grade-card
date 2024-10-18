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

    do
    {
        printf("Select an option: \n");
        printf("1. Enter student details and marks\n2. Display the gradecard of the student\n3. View all student records\n4. Modify a student record\n5. Exit\n");
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
            ViewRecords(); 
            break;
        case 4:
            ModifyRecord(); 
            break;
        case 5:
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 5);

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
