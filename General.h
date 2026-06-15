#ifndef GENERAL_H
#define GENERAL_H
#define MAX_SIZE 1000

/// <summary>
/// Repeate the character pass in
/// </summary>
/// <param name="character"></param>
/// <param name="repeat"></param>
/// <param name="nextLine"></param>
void str(const char character, const int repeat, const int nextLine);

/// <summary>
/// Clear Screen
/// </summary>
void cs();


/// <summary>
/// Check is string
/// </summary>
/// <param name="string"></param>
/// <returns>0 = TRUE 1 = FALSE</returns>
int isString(const char string[100]);


/// <summary>
/// Check is alphabet only
/// </summary>
/// <param name="string"></param>
/// <returns>0 = TRUE 1 = FALSE</returns>
int isName(const char string[100]);


/// <summary>
/// Check is alphabet and number only
/// </summary>
/// <param name="string"></param>
/// <returns>0 = TRUE 1 = FALSE</returns>
int isId(const char string[100]);
#endif