#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "calc.h"
#include "stack.h"
#define SIZE 12

//Function Declaration 
void mem(Stack* s);

int main (int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "Incorrect number of arguments.\n");
		fprintf(stderr, "Usage: ./pa08 <input file>\n");		
		return EXIT_FAILURE;
	}

	//File Handle
	FILE* in = fopen(argv[1], "r");
	if(in == NULL) 
	{
		return EXIT_FAILURE;
	}

	//Stack
	Stack* s = malloc(sizeof(Stack));
	if (s == NULL)
	{
		return EXIT_FAILURE;
	}
	s->head = NULL;

	//array
	char* chararray = malloc(sizeof(char) * SIZE);

	//Variables used
	float tempanswer = 0;
	float tempval = 0;
	float resultant = 0;
	float result = 0;
	int numcounter = 0;
	int opcounter = 0;
	int height = 0;

	while(fscanf(in,"%s",chararray) != EOF)
	{
		if((chararray[0] == '-' || chararray[0] == '/' || chararray[0] == '*' || chararray[0] == '+') && strlen(chararray) == 1)
		{
			opcounter++;
			if((opcounter - numcounter) < 0)
			{
				float value1 = pop(s);
				float value2 = pop(s);
				tempanswer = calculator(value1, value2, chararray[0], s, &resultant);
				if(tempanswer == false)
				{
					fclose(in);
					free(chararray);
					mem(s);
					free(s);
					return EXIT_FAILURE;
				}
				else
				{   
					push(s,resultant);
				}
			}
			else if ((opcounter - numcounter) >= 0)
			{
				fclose(in);
				free(chararray);
				mem(s);
				free(s);
				return EXIT_FAILURE;
			}
		}
		else
		{
			numcounter++;

			tempval = (float) atof(chararray);
			if (tempval == -0)
			{
				tempval = fabs(tempval) < 10e-12 ? 0 : tempval;
			}
			push(s,tempval);
		}
	}

	//Call to obtain stack height 
	height = stackele(s);

	if ((height > 1))
	{
		fclose(in);
		mem(s);
		free(chararray);
		free(s);
		return EXIT_FAILURE;
	}
	else if (height == 1)
	{
		result = pop(s);
		printf("%f\n", result);
		fclose(in);
		free(chararray);
		free(s);
		return EXIT_SUCCESS;
	}else if (height == 0)
	{
		fclose(in);
		mem(s);
		free(chararray);
		free(s);
		return EXIT_FAILURE;
	}
}

//Function to free the memory
void mem(Stack* s)
{
	while(s->head != NULL)
	{
		pop(s);
	}
}
