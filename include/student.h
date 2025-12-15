#ifndef STUDENT_H
#define STUDENT_H
#define MAX_STUDENTS 50
#define NUM_SUBJECTS 3
#define DATA_FILE "students.dat"
typedef struct
{
    int id;
    char name[50];
    float grades[NUM_SUBJECTS];
    float total_marks;
    float average;
} Student;
void add_student(Student students[], int *count);
void calculate_performance(Student *s);
void display_all_students(const Student students[], int count);
void search_student(const Student students[], int count);
int load_data(Student students[]);
void save_data(const Student students[], int count);
#endif