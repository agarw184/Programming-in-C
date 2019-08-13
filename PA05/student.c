// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  for (int ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n",
	     stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
 
// open the file to read
  FILE * inf;
  inf = fopen(filename, "r");
    
// if fopen fails, return false
// do not use fclose since fopen already fails
  if (inf == NULL)
  {
    return false;
  } 


// count the number of lines to determine the number of students
  char character;                      //stores the character obtained using fscanf 
  int length = 0;                      //stores the length 
  int current = fscanf(inf, "%c", &character);
  while(current != EOF)
  {

  	if(character == '\n')
  	{
  		(length++);
	}
	current = fscanf(inf, "%c", &character);
  }
  (*numelem) = length;               //assigns the obtained length value to the data at numelem


// return to the beginning of the file
// you can use fseek or
// fclose followed by fopen
// You need to check whether fseek or fopen fails
// Do not use rewind because it does not report whether it fails
  int status = 0;                   //stores the status returned by fseek
  status = fseek(inf,0,SEEK_SET);
  if(status)
  {
  	return false;
  }


// allocate memory for the data
  Student * stuptr;
  stuptr = malloc(sizeof(*stuptr) * (length));
  *stu = stuptr;

// check whether memory allocation fails
  if((stuptr) == NULL)
  {
  	return false;
  }

// read the data from the file and store the data in the allocated memory
  int counter1 = 0;          //Counter variable for the for-loop
  for(counter1 = 0; counter1 < length; counter1++)
  {
  	fscanf(inf, "%d %s %s\n", &(stuptr[counter1]).ID, stuptr[counter1].firstname, stuptr[counter1].lastname);
  }

// close the file
  fclose(inf);
  return true;
}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  FILE * ouf;
	ouf = fopen(filename,"w");

// if fopen fails, return false
// do not use fclose since fopen already fails
  if(ouf == NULL)
  {
    return false;
  }

// write the students to the output file
  int counter2 = 0;
  for(counter2 = 0; counter2 < numelem; counter2++)
  { 
    fprintf(ouf, "%d %s %s\n", stu[counter2].ID, stu[counter2].firstname, stu[counter2].lastname);
  }
  fclose(ouf);
  return true;
}
#endif 

#ifdef TEST_SORTID
int comparefuncID(const void * arg1, const void * arg2) 
{
  const Student * ptr1 = (const Student *) arg1;
  const Student * ptr2 = (const Student *) arg2;
  return ((ptr1->ID) - (ptr2->ID)); 
}

void StudentSortbyID(Student * stu, int numelem)
{
  qsort(stu,numelem,sizeof(Student),comparefuncID);
}
#endif

#ifdef TEST_SORTFIRSTNAME
int cmpstringpfirstname(const void *arg1, const void *arg2)
{
  const Student * ptr1 = (const Student *) arg1;
  const Student * ptr2 = (const Student *) arg2;
  return strcmp(ptr1->firstname, ptr2->firstname); 
}

void StudentSortbyFirstName(Student * stu, int numelem)
{
  qsort(stu,numelem,sizeof(Student),cmpstringpfirstname);
}
#endif

#ifdef TEST_SORTLASTNAME
int cmpstringplastname(const void *arg1, const void *arg2)
{
  const Student * ptr1 = (const Student *) arg1;
  const Student * ptr2 = (const Student *) arg2;
  return strcmp(ptr1->lastname, ptr2->lastname); 
}

void StudentSortbyLastName(Student * stu, int numelem)
{
  qsort(stu,numelem,sizeof(Student),cmpstringplastname);
}
#endif
