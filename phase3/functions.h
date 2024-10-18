#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct {
    char *name;
    char *roll_no;
    int sem;
    int *isa1;
    int *isa2;
    int *internals;
    int *esa;
    float *tot_marks;
    float sgpa;
    char sub[3][10];
    int credit[3];
} student;

void student_info(student *stu, int n);
void Subjects(student *stu);
void Credits(student *stu);
void ISA1(student *stu, int n);
void ISA2(student *stu, int n);
void Internals(student *stu, int n);
void ESA(student *stu, int n);
void total_marks(student *stu, int n);
void SGPA(student *stu, int n);
void display_gradecard(student *stu, int n);
void WriteToFile(student *stu, int n);
void ReadFromFile(student *stu, int n);
void search_students(student *stu, int n);

#endif