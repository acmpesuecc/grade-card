#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "functions.c"

int main()
{
    int n;
    printf("Enter the number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    student *students = malloc(n * sizeof(student));
    if (students == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    int choice;

    do {
        printf("\nSelect an option:\n");
        printf("1. Enter student details and marks\n");
        printf("2. Display the grade card of a student\n");
        printf("3. Search for students\n");
        printf("4. Exit\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4.\n");
            // Clear input buffer if invalid
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
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
            search_students(students, n);
            break;

        case 4:
            break;    
            
        default:
            printf("Invalid option.\n");
        }
    } while (choice != 4);

    for (int i = 0; i < n; i++) {
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
