#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "General.h"
#include "Admin.h"
#include "Student.h"
#pragma warning(disable : 4996)
#define MAX_SIZE 1000


void printStudentResult(struct StudentResult students[], int numStudents, const char* targetId) {
    printf("Printing student with ID: %s\n", targetId);
    //cs();
    
    // Variables
    char prevStd[50] = "";
    double totalQualityPoints = 0.0;
    int totalCreditHours = 0;
    double cgpa=0;
    int studentFound = 0;

    for (int i = 0; i < numStudents; i++) {  // Loop through the student's records to process each student's data
        if (strcmp(targetId, students[i].stdId) == 0) {  // Compare 'targetId' with the student ID at index 'i'
            studentFound = 1; // A variable used to indicate that a student has been found and processed.

            if (strcmp(prevStd, students[i].stdId) != 0) { // Check if the current student ID is different from the previous one.

                // Output student's information
                printf("\n\n");
                str('=', 79, 0);       // Print one whole line of '='
                printf("Student ID    : KPKL%s\n", students[i].stdId);
                printf("Name          : %s\n\n", students[i].stdName);
                str('-', 79, 0);

                printf("%-10s %-50s %-5s %-11s \n", "Semester", "Course Code", "Grade", "Credit Hour");
                str('-', 10, 1);
                printf(" ");
                str('-', 50, 1);
                printf(" ");
                str('-', 5, 1);
                printf(" ");
                str('-', 11, 1);
                printf("\n");

                // Reset totalQualityPoints and totalCreditHours for the new student.
                totalQualityPoints = 0.0;
                totalCreditHours = 0;
            }

            // Loop through the courses in the stored data for the current student.
            for (int s = 0; s < students[i].courseCnt; s++) {

                // Calculate grade points, total quality points and total credit hours
                double gradePoints = getGradePoint(students[i].grade[s]);
                totalQualityPoints += gradePoints * students[i].creditHour[s];
                totalCreditHours += students[i].creditHour[s];

                if (s == 0) {
                    printf("%-10d %-50s %-5s %-11d  \n", students[i].semester, students[i].courseCode[s], students[i].grade[s], students[i].creditHour[s]);
                }
                else {
                    printf("%-10s %-50s %-5s %-11d \n", " ", students[i].courseCode[s], students[i].grade[s], students[i].creditHour[s]);
                }
            }

            // Output student's current semester GPA
            printf("\n");
            printf("Your gpa score in semester %d is:%.2f\n", students[i].semester, students[i].gpa);

            // Check if it's the last student or the next student is different from the current one.
            if (i == numStudents - 1 || strcmp(students[i].stdId, students[i + 1].stdId) != 0) {
                printf("\n");

                // Calculate and print the CGPA for all semesters if it's the last student or the next student is different.
                double cgpa = totalQualityPoints / totalCreditHours;
                printf("Your cgpa score in all semesters is: %.2f\n", cgpa);
            }

            
        }

        // Copy the current student ID to 'prevStd' for comparison in the next replay.
        strcpy(prevStd, students[i].stdId);
    }

    if (!studentFound) {
        printf("Student with ID: %s not found.\n", targetId);
    }

    printf("\n\n");
    str('=', 85, 0);
}
