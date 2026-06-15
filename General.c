#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning(disable : 4996)
#define MAX_SIZE 1000


void str(const char character, const int repeat, const int nextLine) {
	for (int i = 0; i < repeat; i++) {
		printf("%c", character);
	}
	if (nextLine == 0) {
		printf("\n");
	}
}


void cs() {
	system("cls");
}

int isString(const char string[100]) {
	for (int i = 0; i < strlen(string); i++) {
		if (isalpha(string[i])) {
			return 0;
		}
	}

	return 1;
}

int isName(const char string[100]) {
	for (int i = 0; i < strlen(string); i++) {
		if (isalpha(string[i]) || isspace(string[i])) {
			return 0;
		}
	}

	return 1;
}

int isId(const char string[100]) {
	for (int i = 0; i < strlen(string); i++) {
		if (isdigit(string[i])) {
			return 0;
		}
	}

	return 1;
}








