#ifndef ADMIN_H
#define ADMIN_H
#define MAX_SIZE 1000

/// <summary>
/// Add student details
/// </summary>
/// <param name="studentList"></param>
/// <param name="numOfList"></param>
/// <returns></returns>
struct StudentResult addStudentDetails(struct StudentResult studentList[], int numOfList);


/// <summary>
/// Get gfradepoints for grade
/// </summary>
/// <param name="grade"></param>
/// <returns></returns>
double getGradePoint(const char* grade);


/// <summary>
/// Print all students 
/// </summary>
/// <param name="students"></param>
/// <param name="numStudents"></param>
void printAllStudents(struct StudentResult students[], int numStudents);

#endif // !ADMIN_H