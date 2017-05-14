#include "header.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("argc number < 2\n");
		exit(true);
	}
	List *list = (List*)malloc(sizeof(List));
	list = readData(argv[0]);
	list = calcGrade(list);
	outputResult(list, argv[1]);
	return 0;
}
