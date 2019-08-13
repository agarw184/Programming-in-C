// You must modify this file
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "student.h"

// --------------------------------------------------------------
int main(int argc, char * * argv)
{
  // argv[1]: input file name
  // argv[2]: output file name, sorted by ID
  // argv[3]: output file name, sorted by first name
  // argv[4]: output file name, sorted by last name
  if (argc < 5)
    {
      return EXIT_FAILURE;
    }
  // create the necessary variables
    Student * stuptr;
    int numofstu = 0;              //Number-of-students
 
  // read students from the input file
  // return EXIT_FAILURE if reading fails
  //Variable 'indicator' is bool-type variable that stores the returned status 
    bool indicator = StudentRead(argv[1],(&stuptr),(&numofstu));         
    if(indicator == false)
    {
    	return EXIT_FAILURE;
    }

  // sort the students by IDs
    StudentSortbyID(stuptr,numofstu);  

  // write the result to the output (name is argv[2])
  // return EXIT_FAILURE if writing fails
    indicator = StudentWrite(argv[2],stuptr,numofstu);
    if(indicator == false)
    {
    	return EXIT_FAILURE;
    }

  // sort the students by first names
    StudentSortbyFirstName(stuptr,numofstu); 

  // write the result to the output (name is argv[3])
  // return EXIT_FAILURE if writing fails
    indicator = StudentWrite(argv[3],stuptr,numofstu);
    if(indicator == false)
    {
    	return EXIT_FAILURE ;
    }

  // sort the students by last names
    StudentSortbyLastName(stuptr,numofstu);   

  // write the result to the output (name is argv[4])
  // return EXIT_FAILURE if writing fails
    indicator = StudentWrite(argv[4],stuptr,numofstu);
    if(indicator == false)
    {
    	return EXIT_FAILURE ;
    }

  // release allocated memory
    free(stuptr);
    return EXIT_SUCCESS;
}
