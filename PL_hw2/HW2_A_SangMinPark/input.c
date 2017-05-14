#pragma warning(disable:4996)
#include "header.h"

List* readData(char *path) {
	int NumberOfStudent = 0;
	int NumberOfSubject = 0;
	char ch;
	int m, n;
	FILE *fp;
	List *list;
	Student *TempStudent = (Student*)malloc(sizeof(Student));
	Student *test = (Student*)malloc(sizeof(Student));

	list = (List *)malloc(sizeof(List));
	fp = fopen(path, "rt");
	InitList(list);
	if (fp == NULL) {
		printf("File doesn't exit\n");
		exit(true);
	}
	InitList(list);
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == 10) {										//Ascii  \n -> 10
			NumberOfStudent++;
		}
		else if (ch == 32 && NumberOfStudent == 0) {		//Ascii  space(" ") -> 32
			NumberOfSubject++;
		}
	}
	NumberOfStudent++;
	NumberOfSubject++;
	setStudent(list, TempStudent, NumberOfStudent, NumberOfSubject);

	fseek(fp, 0, SEEK_SET);
	for (m = 0; m < NumberOfStudent; m++) {
		TempStudent = (Student*)malloc(sizeof(Student));
		setStudent(list, TempStudent, NumberOfStudent, NumberOfSubject);
		for (n = 0; n < NumberOfSubject; n++) {
			fscanf(fp, "%d", &(TempStudent->score[n]));
			if (feof(fp)) {
				break;
			}
		}
		Linsert(list, *TempStudent);
	}
	fclose(fp);
	return list;
}
