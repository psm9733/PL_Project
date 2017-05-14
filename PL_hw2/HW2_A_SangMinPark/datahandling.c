#include "header.h"

void setStudent(List* list, Student* student, int Numberofpeople, int NumberofSubject) {
	student->NumberOfStudent = Numberofpeople;
	student->NumberOfSubject = NumberofSubject;
	list->head->NumberOfStudent = Numberofpeople;
	list->head->NumberOfSubject = NumberofSubject;
	student->score = (int*)malloc(sizeof(int)*NumberofSubject);
}

int getNumOfStudent(Student* student) {
	return student->NumberOfStudent;
}

int getSubjectOfNumber(Student* student) {
	return student->NumberOfSubject;
}
