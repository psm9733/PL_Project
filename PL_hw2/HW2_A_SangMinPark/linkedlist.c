#include "header.h"

void InitList(List* list) {
	Student *header = (Student*)malloc(sizeof(Student));
	list->head = header;
	list->tail = header;
	list->cur = header;
	list->numofData = 0;
	return;
}

int Linsert(List* list, Student student) {
	Student *allo_student = (Student *)malloc(sizeof(Student));
	*allo_student = student;
	if (list->numofData == 0) {
		list->head->next = allo_student;
		list->tail = list->head->next;
		list->tail->next = NULL;
		list->numofData++; //inital numofData = 1;
		return true;
	}
	else {
		list->tail->next = allo_student;
		list->tail = list->tail->next;
		list->tail->next = NULL;
		list->numofData++;
		return true;
	}
	return false;
}

int LFirst(List* list, Student* getdata) {
	if (list->head->next != NULL) {
		list->cur = list->head->next;
		getdata = list->cur;
		return true;
	}
	return false;
}

int Lnext(List* list, Student* getdata) {
	if (list->cur->next != NULL) {
		list->cur = list->cur->next;
		getdata = list->cur;
		return true;
	}
	else if (list->numofData != 0 && list->cur->next == NULL) {
		list->cur = list->head->next;
		getdata = list->cur;
		return false;
	}
	return false;
}

void getLNumOfStudent(List* list, int* number) {
	*number = list->numofData;
}
