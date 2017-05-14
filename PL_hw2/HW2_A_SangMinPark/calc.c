#include "header.h"

List* calcGrade(List* list) {
	char *str;
	int index = 0;
	int sum = 0;	
	int NumberofSubject = 0;
	float average;
	Student* temp = (Student*)malloc(sizeof(Student));
	NumberofSubject = list->head->NumberOfSubject;
	str = "SCORE";
	printf("--------grade.txt--------\n");
	for(index = 0; index < NumberofSubject; index++){
		printf("%6s%d", str, index); 
	}
	str = "AVERAGE";
	printf("%9s\n", str);
	while (Lnext(list, temp)) {
		for (index = 0; index < NumberofSubject; index++) {
			sum += list->cur->score[index];
			printf("%7d", list->cur->score[index]);
		}
		average = (float)sum / NumberofSubject;
		(list->cur->average) = average;
		printf("%9.1f\n", list->cur->average);
		sum = 0;
	}
	return list;
}
