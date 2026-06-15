#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "General.h"
#include "Student.h"
#pragma warning(disable : 4996)
#define MAX_SIZE 1000



//function to get point
double getGradePoint(const char* grade) {
    struct GradePoint gradePoints[] =
    {
        {"A", 4.00},
        {"A-", 3.75},
        {"B+", 3.50},
        {"B", 3.00},
        {"B-", 2.75},
        {"C+", 2.50},
        {"C", 2.00},
        {"F", 0.00}
    };

    int numOfGrade = sizeof(gradePoints) / sizeof(gradePoints[0]);

    for (int i = 0; i < numOfGrade; i++) {
        if (strcmp(grade, gradePoints[i].grade) == 0) {
            return gradePoints[i].point;
        }
    }

    return -1;
}



//add student details
struct StudentResult addStudentDetails(struct StudentResult studentList[], int numOfList) {
    //variable declaration
    char stdId[10], stdName[41], courseCode[51]="", grade[3], subjectList[MAX_SIZE][50], gradeList[MAX_SIZE][3];
    int semester, creditHour, creditHourList[MAX_SIZE];

    int flag = 1;

    cs();
    //loop to enter student name and id
    int endStudent = 1;
    do {
        do {
            int errCnt = 0;

            printf("%-20s : KPKL", "Student ID");
            scanf(" %9[^\n]s", &stdId);
            rewind(stdin);

            if (isId(stdId) == 1) { //validation to check input is id 
                errCnt++;
                printf("Please inside a valid StudentID (e.g. KPKL12345)\n");
            }

            if (errCnt == 0) {
                break;
            }

        } while (flag == 1);


        while (1)
        {
            printf("%-20s : ", "Student Name");
            scanf(" %40[^\n]s", &stdName);
            rewind(stdin);

            // Convert the student name to uppercase
            for (int i = 0; i < stdName[i]; i++) {
                stdName[i] = toupper(stdName[i]);
            }

            if (isName(stdName) == 1) { //validation to check input is name
                printf("The student name must be a string\n");
            }
            else {
                endStudent = 0;
                break;
            }

        }

    } while (endStudent == 1);

    //print sem
    int cnt = 0;
    for (int i = 0; i < numOfList; i++) {
        if (strcmp(stdId, studentList[i].stdId) == 0) {
            cnt++;

        }
    }
    semester = cnt + 1;
    printf("%-20s :%d\n ", "Semester", semester);

    //loop to enter course details
    str('=', 20, 0);
    int endCourse = 1; int courseCnt = 0;
    do {
        do {
            int errCnt = 0;

            printf("%0d %-20s : ", courseCnt + 1, "Course Code (enter 0 to stop)");
            scanf(" %50[^\n]s", &courseCode);
            rewind(stdin);

            if (strcmp(courseCode, "0") == 0) { //if enter 0 will end the course detials
                flag = 2;
                endCourse = 2;
                break;
            }
            else if (strlen(courseCode) < 5 || strlen(courseCode) > 50) { //validation to check length of input
                errCnt++;
                printf("The subject must be between 5 to 50 characters.\n");
            }
            else if (isString(courseCode) == 1) { //validation to check input is a string
                errCnt++;
                printf("The subject must be a string.\n");
            }


            if (errCnt == 0) {
                break;
            }

        } while (flag == 1);



        while (flag == 1)
        {
            printf("   %-20s : ", "Grade");
            scanf("%2s", &grade);
            rewind(stdin);

            if (getGradePoint(grade) == -1.0) { //validation to check grade points
                printf("Invalid Grade.\n");
                continue;
            }
            do {
                int errcnt = 0;
                printf("   %-20s : ", "Credit Hour");
                rewind(stdin);
                if (scanf("%1d", &creditHour) != 1) { //validation to check credit hours is diigt only
                    errcnt++;
                    printf("Credit hour must be an integer.\n");
                }

                if (errcnt == 0) {
                    break;
                }
            } while (flag == 1);

            //store course details
            strcpy(subjectList[courseCnt], courseCode);
            strcpy(gradeList[courseCnt], grade);
            creditHourList[courseCnt] = creditHour;
            courseCnt++;

            break;
        }
    } while (endCourse == 1);

    printf("\n\n\n");
    //print course details
    for (int i = 0; i < courseCnt; i++) {
        printf("%02d %-50s %-2s %-2d \n", i + 1, subjectList[i], gradeList[i], creditHourList[i]);
    }


    // Calculate Total Grade Points and GPA
    double totalQualityPointsOneSem = 0.0;
    int totalCreditHoursOneSem = 0;
    for (int i = 0; i < courseCnt; i++) {
        double gradePoint = getGradePoint(gradeList[i]);
        totalQualityPointsOneSem += gradePoint * creditHourList[i];
        totalCreditHoursOneSem += creditHourList[i];
    }

    if (totalCreditHoursOneSem == 0) {
        printf("Error: Division by zero.\n");
        return;
    }

    double gpa = totalQualityPointsOneSem / totalCreditHoursOneSem;
    printf("GPA: %.2f\n", gpa);

  
    
    //store all data into structure
    struct StudentResult std;
    strcpy(std.stdId, stdId);
    strcpy(std.stdName, stdName);
    std.semester = semester;
    std.courseCnt = courseCnt;
    for (int i = 0; i < courseCnt; i++) {
        strcpy(std.courseCode[i], subjectList[i]);
        strcpy(std.grade[i], gradeList[i]);
        std.creditHour[i] = creditHourList[i];

    }
    std.gpa = gpa;
    return std;

    
}


//print all student result
void printAllStudents(struct StudentResult students[], int numStudents) {
    printf("Printing all students:\n");
    //cs();
    char prevStd[50]="";
    double totalQualityPoints = 0.0;
    int totalCreditHours = 0;
    double cgpa=0;

    //loop for numStudents
    for (int i = 0; i < numStudents; i++) {
        
        //if previous student not equal to students[i].stdId
        if (strcmp(prevStd, students[i].stdId) != 0) {
            printf("\n\n");
            str('=', 79, 0);
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

            //set to 0 for another student
            totalQualityPoints = 0.0;
            totalCreditHours = 0;
        }

        //loop to get gradepoints and caredit hour for every course code
        for (int s = 0; s < students[i].courseCnt; s++) {
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
        printf("\n");
        printf("Your gpa score in semester %d is:%.2f\n", students[i].semester, students[i].gpa);
        
        //print cgpa only if student result completly
        if (i == numStudents - 1 || strcmp(students[i].stdId, students[i + 1].stdId) != 0) {
            printf("\n");
            double cgpa = totalQualityPoints / totalCreditHours;
            printf("Your cgpa score in all semester is:%.2f\n", cgpa);
        }

        //replace previous student with students[i].stdId
        strcpy(prevStd, students[i].stdId);



    }

    printf("\n\n");
    str('=', 79, 0);
}