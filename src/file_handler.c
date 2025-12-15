#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"
int load_data(Student students[])
{
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL)
    {
        return 0;
    }
    int count = 0;
    while (count < MAX_STUDENTS &&
           fscanf(file, "%d %49[^\n]%f%f%f%f%f\n",
                  &students[count].id,
                  students[count].name,
                  &students[count].grades[0], &students[count].grades[1], &students[count].grades[2],
                  &students[count].total_marks,
                  &students[count].average) == 7)
    {
        count++;
    }
    fclose(file);
    printf("\nLoaded %d student records from %s.\n", count, DATA_FILE);
    return count;
}
void save_data(const Student students[], int count)
{
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL)
    {
        perror("*** Error: Could not open file for saving");
        return;
    }
    for (int i = 0; i < count; i++)
    {
        const Student *s = &students[i];
        fprintf(file, "%d %s %f %f %f %f %f\n",
                s->id, s->name,
                s->grades[0], s->grades[1], s->grades[2],
                s->total_marks, s->average);
    }
    fclose(file);
    printf("SUCCESS: %d records saved to %s.\n", count, DATA_FILE);
}