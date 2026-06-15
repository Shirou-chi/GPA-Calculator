#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "General.h"
#include "Student.h"   
#include "Admin.h"
#pragma warning(disable : 4996)
#define MAX_SIZE 1000

struct StudentResult studentList[MAX_SIZE];
int numOfList = 0;
const char correctPassword[] = "admin";

void addStudentResult();
//sort student 
struct StudentResult* sortStudent(struct StudentResult students[], int numStudent) {
    struct StudentResult* tempStudentList = malloc(numStudent * sizeof(struct StudentResult));
    char   studentIdList[MAX_SIZE][10];
    int    stdIdCnt = 0, tempStudentCnt = 0;

    //loop to find student
    for (int i = 0; i < numStudent; i++) {

        //set found =0
        int found = 0;

        //loop to compare student Id
        for (int x = 0; x < stdIdCnt; x++) {
            if (strcmp(students[i].stdId, studentIdList[x]) == 0) {
                found++;
            }
        }



        if (found == 0) {
            strcpy(studentIdList[stdIdCnt], students[i].stdId);
            stdIdCnt++;
        }

    }

    //loop for student Id
    for (int i = 0; i < stdIdCnt; i++) {
        //variable declaration
        char stdId[10];
        //replace stdId with stuadentIdList[i]
        strcpy(stdId, studentIdList[i]);

        for (int x = 0; x < numStudent; x++) {
            if (strcmp(students[x].stdId, stdId) == 0) {
                struct StudentResult std;

                strcpy(std.stdId, students[x].stdId);
                strcpy(std.stdName, students[x].stdName);
                std.semester = students[x].semester;
                std.courseCnt = students[x].courseCnt;
                for (int c = 0; c < std.courseCnt; c++) {
                    strcpy(std.courseCode[c], students[x].courseCode[c]);
                    strcpy(std.grade[c], students[x].grade[c]);
                    std.creditHour[c] = students[x].creditHour[c];
                }
                std.gpa = students[x].gpa;
                

                tempStudentList[tempStudentCnt] = std;
                tempStudentCnt++;
            }
        }
    }


    return tempStudentList;
}



//admin menu
void adminMenu() {
    //variable declaration
    int flag = 1;

    do {
        char choice[2];
        printf("========================\n");
        printf("#1 Add Student Result\n");
        printf("#2 Show Student Result\n");
        printf("#0 Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%1s", &choice);
        rewind(stdin);

        switch (choice[0]) {
        case '1': {
            addStudentResult();
            break;
        }

        case '2':
            cs();
            struct StudentResult* newStdList = sortStudent(studentList, numOfList);
            printAllStudents(newStdList, numOfList);
            break;

        case '0':
            flag = 0;
            break;

        default:
            printf("Invalid Input\n\n\n");
            continue;
        }
    } while (flag == 1);
}

//add student result
void addStudentResult() {
    struct StudentResult newStdResult = addStudentDetails(studentList, numOfList);

    studentList[numOfList] = newStdResult;
    numOfList++;
}

//student menu
void studentMenu() {
    //variable declaration
    int choice;
    char targetId[50];

    while (1) {
        printf("\nStudent Menu\n");
        printf("1. Print student result\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter student ID to print result: KPKL");
            scanf("%s", targetId);
            
            printf("result is printing..\n");

            cs();
            struct StudentResult* newStdList = sortStudent(studentList, numOfList);
            printStudentResult(newStdList, numOfList, targetId);
            break;

        case 0:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

}

//start
void start() {
    //varaible declaration
    int flag = 1;

    do {
        char choice;
        cs();
        printf("==================================\n");
        printf("#1 Kolej Pasar staff administrator\n");
        printf("#2 Kolej Pasar student\n");
        printf("#0 Exit\n");
        printf("==================================\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        rewind(stdin);

        switch (choice)
        {
        case '1':
            cs();
                char password[100]="";
                printf("Enter the password to access 'Kolej Pasar staff administrator': ");
                scanf("%99[^\n]s", password);
                rewind(stdin);

                if (strcmp(password, correctPassword) == 0) {
                    cs();
                    printf("Login Successful!!!\n");
                    adminMenu();
                }
                else {
                    printf("Incorrect password. Access denied.\n\n\n");
                }
                break;

        case '2':
            cs();
            studentMenu();
            break;

        case '0':
            flag = 0;
            break;

        default:
            printf("Invalid Input\n\n\n");
            continue;
        }
    } while (flag == 1);
    
}



//main
void main() {
    start();
}