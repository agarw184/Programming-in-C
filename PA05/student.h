// You must modify this file
#ifndef PA05_H
#define PA05_H
#include "constant.h"
#include <stdbool.h>

// create a structure type that has the following attributes
// please make sure the names are exactly the same
//  int- IO
//  char- firstname[NAME_LENGTH]
//  char- lastname[NAME_LENGTH]

typedef struct
{
	int ID;
	char firstname[NAME_LENGTH];
	char lastname[NAME_LENGTH];
} Student;

// functions to be implemented
bool StudentRead(char * filename, Student * * stu, int * numelem);
bool StudentWrite(char * filename, Student * stu, int numelem);
int comparefuncID(const void * arg1, const void * arg2);
void StudentSortbyID(Student * stu, int numelem);
int cmpstringpfirstname(const void *arg1, const void *arg2);
void StudentSortbyFirstName(Student * stu, int numelem);
int cmpstringplastname(const void *arg1, const void *arg2);
void StudentSortbyLastName(Student * stu, int numelem);

// function already impelemented for you
void StudentPrint(Student * stu, int num);
#endif
