#include <stdio.h>
#include <string.h>
#include "../include/student.h"
void calculate_performance(Student *s)
{
    s->total_marks = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        s->total_marks += s->grades[i];
    }
    s->average = s->total_marks / NUM_SUBJECTS;
}
void add_student(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\n*** Error: Maximum Number of Students Reached (%d). ***\n", MAX_STUDENTS);
        return;
    }
    printf("\n--- Add New Student ---\n");
    Student new_student;
    printf("Enter Student ID: ");
    scanf("%d", &new_student.id);
    for (int i = 0; i < *count; i++)
    {
        if (students[i].id == new_student.id)
        {
            printf("*** Error: Student ID %d already exists. ***\n", new_student.id);
            return;
        }
    }
    printf("Enter Name: ");
    scanf(" %49[^\n]", new_student.name);
    printf("Enter Grades for %d subjects:\n", NUM_SUBJECTS);
    for (int i = 0; i < NUM_SUBJECTS; i++)
    {
        printf("  Subject %d Grade: ", i + 1);
        scanf("%f", &new_student.grades[i]);
    }
    calculate_performance(&new_student);
    students[*count] = new_student;
    (*count)++;
    printf("\nSUCCESS: Student '%s' added successfully.\n", new_student.name);
}
void display_all_students(const Student students[], int count)
{
    if (count == 0)
    {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n========================================================================\n");
    printf("| ID  | Name          | G1    | G2    | G3    | Total | Average | Status |\n");
    printf("========================================================================\n");
    for (int i = 0; i < count; i++)
    {
        const Student *s = &students[i];
        const char *status = (s->average >= 70.0) ? "Pass" : "Fail";

        printf("| %-3d | %-13s | %-5.1f | %-5.1f | %-5.1f | %-5.1f | %-7.2f | %-6s |\n",
               s->id, s->name, s->grades[0], s->grades[1], s->grades[2],
               s->total_marks, s->average, status);
    }
    printf("========================================================================\n");
}
void search_student(const Student students[], int count)
{
    int search_id;
    printf("\n--- Search Student ---\n");
    printf("Enter Student ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < count; i++)
    {
        if (students[i].id == search_id)
        {
            const Student *s = &students[i];
            printf("\nFound Student ID: %d\n", s->id);
            printf("Name: %s\n", s->name);
            printf("Average Grade: %.2f\n", s->average);
            return;
        }
    }
    printf("\n*** Error: Student with ID %d not found. ***\n", search_id);
}