#ifndef STUDENT_H
#define STUDENT_H
#define MAX_SIZE 1000
struct GradePoint
{
    char grade[3];
    double point;
};

struct StudentResult {
    char stdId[10];
    char stdName[40];
    int semester;
    int courseCnt;
    char courseCode[MAX_SIZE][51];
    char grade[MAX_SIZE][3];
    int creditHour[MAX_SIZE];
    double gpa;
    
};



/// <summary>
/// Print student reuslt with specific student ID
/// </summary>
/// <param name="students"></param>
/// <param name="numStudents"></param>
/// <param name="targetId"></param>
void printStudentResult(struct StudentResult students[], int numStudents, const char* targetId);

#endif

