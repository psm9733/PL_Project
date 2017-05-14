#ifndef __HEADER_H__
#define __HEADER_H__
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

/* Data define */

typedef struct student {
	int NumberOfStudent;
	int NumberOfSubject;
	int *score;
	float average;
	struct student *next;
}Student;

/* Linked list */

typedef struct linkedlist {
	int numofData;
	Student *head;
	Student *cur;
	Student *tail;
}List;

void InitList(List* list);
int Linsert(List* list, Student student);
int LFirst(List* list, Student* getdata);
int Lnext(List* list, Student* getdata);
void getLNumOfStudent(List* list, int* number);

/* --data handling -- */

void setStudent(List* list, Student* student, int Numberofpeople, int NumberofSubject);
int getNumOfStudent(Student* student);
int getSubjectOfNumber(Student* student);

/* --file handling -- */

List* readData(char* path);
List* calcGrade(List* list);
void outputResult(List* list, char* path);
#endif
