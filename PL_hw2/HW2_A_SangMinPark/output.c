#pragma warning(disable:4996)
#include "header.h"

void outputResult(List* list, char* path) {
	int student_counter, subject_counter;
	int NumberOfStudent;
	int NumberOfSubject;
	Student *temp = (Student*)malloc(sizeof(Student));
	NumberOfStudent = list->head->NumberOfStudent;
	NumberOfSubject = list->head->NumberOfSubject;
	FILE *fp;
	fp = fopen(path, "wt");
	for (student_counter = 0; student_counter < NumberOfStudent; student_counter++) {
		for (subject_counter = 0; subject_counter < NumberOfSubject; subject_counter++) {
			fprintf(fp, "%d ", list->cur->score[subject_counter]);
		}
		fprintf(fp, "%.1f \r\n", list->cur->average);
		Lnext(list, temp);
	}
	fclose(fp);
	return;
}