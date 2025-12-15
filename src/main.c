#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"
void display_menu()
{
    printf("\n==================================\n");
    printf("  C STUDENT GRADING SYSTEM\n");
    printf("==================================\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Save Data to File\n");
    printf("5. Exit and Save\n");
    printf("----------------------------------\n");
    printf("Enter Choice: ");
}
int main()
{
    Student students[MAX_STUDENTS];
    int student_count = 0;
    int choice;
    student_count = load_data(students);
    while (1)
    {
        display_menu();
        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            choice = 0;
        }
        switch (choice)
        {
        case 1:
            add_student(students, &student_count);
            break;
        case 2:
            display_all_students(students, student_count);
            break;
        case 3:
            search_student(students, student_count);
            break;
        case 4:
            save_data(students, student_count);
            break;
        case 5:
            printf("\nExiting system. Saving data...\n");
            save_data(students, student_count);
            printf("Goodbye!\n");
            return 0;
        default:
            printf("*** Invalid choice. Please try again. ***\n");
        }
    }
    return 0;
}