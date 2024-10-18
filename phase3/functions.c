#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

FILE *fp;

// Input student information
void student_info(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].name = malloc(30 * sizeof(char));
        stu[i].roll_no = malloc(20 * sizeof(char));
        if (stu[i].name == NULL || stu[i].roll_no == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        printf("-----------------    Data of Student %d    -----------------\n", i + 1);
        printf("Enter the name: ");
        scanf("%s", stu[i].name);
        printf("Enter the roll number: ");
        scanf("%s", stu[i].roll_no);
        printf("Enter the semester: ");
        scanf("%d", &stu[i].sem);

        // Initialize subjects and credits for each student
        Subjects(&stu[i]);
        Credits(&stu[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Input subject names
void Subjects(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter subject %d: ", i + 1);
        scanf("%s", stu->sub[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Input subject credits
void Credits(student *stu)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Enter the credits of subject %d: ", i + 1);
        scanf("%d", &stu->credit[i]);
    }
    printf("-----------------------------------------------------------\n");
}

// Input ISA1 marks
void ISA1(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa1 = malloc(3 * sizeof(int));
        printf("Enter the ISA 1 marks(out of 40) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa1[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Input ISA2 marks
void ISA2(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].isa2 = malloc(3 * sizeof(int));
        printf("Enter the ISA 2 marks(out of 40) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].isa2[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

//Input Internal marks
void Internals(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].internals = malloc(3 * sizeof(int));
        printf("Enter the internal marks(out of 10) of student %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].internals[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Input ESA marks
void ESA(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].esa = malloc(3 * sizeof(int));
        printf("Enter the ESA marks of student(out of 100) %d for the 3 subjects: ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &stu[i].esa[j]);
        }
    }
    printf("-----------------------------------------------------------\n");
}

// Calculating total marks
void total_marks(student *stu, int n)
{
    for (int i = 0; i < n; i++)
    {
        stu[i].tot_marks = malloc(3 * sizeof(float));
        for (int j = 0; j < 3; j++)
        {
            stu[i].tot_marks[j] = ((stu[i].isa1[j] * 0.5) + (stu[i].isa2[j] * 0.5) + (stu[i].esa[j] * 0.5) + stu[i].internals[j]);
        }
    }
}

// Calculating SGPA
void SGPA(student *stu, int n)
{
    int total_credits = 0;
    for (int i = 0; i < 3; i++)
    {
        total_credits += stu->credit[i];
    }
    for (int i = 0; i < n; i++)
    {
        stu[i].sgpa = 0;
        for (int j = 0; j < 3; j++)
        {
            if (stu[i].tot_marks[j] > 90 && stu[i].tot_marks[j] <= 100)
            {
                stu[i].sgpa += 10 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 80 && stu[i].tot_marks[j] <= 90)
            {
                stu[i].sgpa += 9 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 70 && stu[i].tot_marks[j] <= 80)
            {
                stu[i].sgpa += 8 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 60 && stu[i].tot_marks[j] <= 70)
            {
                stu[i].sgpa += 7 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 50 && stu[i].tot_marks[j] <= 60)
            {
                stu[i].sgpa += 6 * stu->credit[j];
            }
            else if (stu[i].tot_marks[j] > 40 && stu[i].tot_marks[j] <= 50)
            {
                stu[i].sgpa += 5 * stu->credit[j];
            }
            else
            {
                stu[i].sgpa += 4 * stu->credit[j];
            }
        }
        stu[i].sgpa /= total_credits;
    }
}

//Writing the data to the file
void WriteToFile(student *stu, int n)
{
    fp = fopen("student_data.csv", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "Name,Roll_Number,Sem,ISA1_S1,ISA2_S1,Internals_S1,ESA_S1,ISA1_S2,ISA2_S2,Internals_S2,ESA_S2,ISA1_S3,ISA2_S3,Internals_S3,ESA_S3,SGPA\n");

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%s,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f\n",
                stu[i].name, stu[i].roll_no, stu[i].sem,
                stu[i].isa1[0], stu[i].isa2[0], stu[i].internals[0], stu[i].esa[0],
                stu[i].isa1[1], stu[i].isa2[1], stu[i].internals[1], stu[i].esa[1],
                stu[i].isa1[2], stu[i].isa2[2], stu[i].internals[2], stu[i].esa[2],
                stu[i].sgpa);
    }
    printf("Written to file\n");
    fclose(fp);
}

//Reading the data from the file
void ReadFromFile(student *stu, int n)
{
    fp = fopen("student_data.csv", "r");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    char buffer[1024];
    int row = 0;

    fgets(buffer, sizeof(buffer), fp);

    while (fgets(buffer, sizeof(buffer), fp) && row < n)
    {
        stu[row].name = malloc(30 * sizeof(char));
        stu[row].roll_no = malloc(20 * sizeof(char));
        stu[row].isa1 = malloc(3 * sizeof(int));
        stu[row].isa2 = malloc(3 * sizeof(int));
        stu[row].internals = malloc(3 * sizeof(int));
        stu[row].esa = malloc(3 * sizeof(int));
        stu[row].tot_marks = malloc(3 * sizeof(float));

        sscanf(buffer, "%29[^,],%19[^,],%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%f",
               stu[row].name,
               stu[row].roll_no,
               &stu[row].sem,
               &stu[row].isa1[0], &stu[row].isa2[0], &stu[row].internals[0], &stu[row].esa[0],
               &stu[row].isa1[1], &stu[row].isa2[1], &stu[row].internals[1], &stu[row].esa[1],
               &stu[row].isa1[2], &stu[row].isa2[2], &stu[row].internals[2], &stu[row].esa[2],
               &stu[row].sgpa);
        row++;
    }

    fclose(fp);
}

// Display gradecard
void display_gradecard(student *stu, int n)
{
    int input;
    printf("Choose the grade card to be printed (1 - %d):\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, stu[i].name);
    }
    scanf("%d", &input);
    if (input >= 1 && input <= n)
    {
        input--;
        printf("\n");
        printf("====================================================================\n");
        printf("\t\t\t    GRADE CARD\n");
        printf("Name: %-30s\n", stu[input].name);
        printf("Semester: %-10d\n", stu[input].sem);
        printf("Roll No.: %-20s\n", stu[input].roll_no);
        printf("--------------------------------------------------------------------\n");
        printf("SGPA: %.2f\n", stu[input].sgpa);
        printf("--------------------------------------------------------------------\n");
        printf("Subject\t\tISA1\tISA2\tInternals\tESA\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%s\t\t%d\t%d\t%d\t\t%d\n", stu[input].sub[i], stu[input].isa1[i], stu[input].isa2[i], stu[input].internals[i], stu[input].esa[i]);
        }
        printf("====================================================================\n");
    }
    else
    {
        printf("Invalid number! Please enter a valid number\n");
    }
}

void search_students(student *stu, int n) {
    int choice;
    printf("Search by:\n");
    printf("1. Roll Number\n");
    printf("2. Marks (total)\n");
    printf("3. Semester\n");
    printf("Choose an option (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            char roll_no[20];
            printf("Enter roll number to search: ");
            scanf("%s", roll_no);
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(stu[i].roll_no, roll_no) == 0) {
                    printf("Found Student: %s, Roll Number: %s, Semester: %d\n", stu[i].name, stu[i].roll_no, stu[i].sem);
                    found = 1;
                    break; // Found the student, exit the loop
                }
            }
            if (!found) {
                printf("No student found with roll number %s.\n", roll_no);
            }
            break;
        }
        case 2: {
            float marks;
            printf("Enter marks to search: ");
            scanf("%f", &marks);
            int found = 0;
            for (int i = 0; i < n; i++) {
                // Check total marks for each subject
                for (int j = 0; j < 3; j++) {
                    if (stu[i].tot_marks[j] == marks) {
                        printf("Found Student: %s, Roll Number: %s, Semester: %d, Total Marks: %.2f\n", 
                            stu[i].name, stu[i].roll_no, stu[i].sem, stu[i].tot_marks[j]);
                        found = 1;
                    }
                }
            }
            if (!found) {
                printf("No student found with total marks %.2f.\n", marks);
            }
            break;
        }
        case 3: {
            int semester;
            printf("Enter semester to search: ");
            scanf("%d", &semester);
            int found = 0;
            for (int i = 0; i < n; i++) {
                if (stu[i].sem == semester) {
                    printf("Found Student: %s, Roll Number: %s, Semester: %d\n", stu[i].name, stu[i].roll_no, stu[i].sem);
                    found = 1;
                }
            }
            if (!found) {
                printf("No students found in semester %d.\n", semester);
            }
            break;
        }
        default:
            printf("Invalid choice.\n");
            break;
    }
}

