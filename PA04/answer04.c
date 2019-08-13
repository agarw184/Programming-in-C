#include <stdio.h>
#include <stdbool.h>
#include "pa04.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
	double lower = intrg -> lowerlimit;
	double upper = intrg -> upperlimit;
	int intvl = intrg -> intervals;
	double intvlwidth = (upper - lower) / intvl;
	double sum = 0;
	for (int cnt = 0; cnt < intvl; cnt ++)
	{
		sum += intrg -> func(lower);
		lower += intvlwidth;
	}
    sum *= intvlwidth;
    intrg -> answer = sum; 
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem

{ 
  Integration intrg;	
  // open the input file name for reading
  FILE * inf = fopen(infilename, "r");

  // if fopen fails, return false
  if(inf == NULL)
  {
  	return false;
  }

  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  int val = 0;
  val = fscanf(inf, "%lf", &(intrg.lowerlimit));
  if (val != 1)
  {
  	fclose(inf);
  	return false;
  }

  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  val = fscanf(inf, "%lf", &(intrg.upperlimit));
  if (val != 1)
  {
  	fclose(inf);
  	return false;
  }

  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
 val = fscanf(inf, "%d", &(intrg.intervals));
  if (val != 1)
  {
  	fclose(inf);
  	return false;
  }

  // close the input file
 fclose(inf);

  // open the output file for writing
  // if fopen fails, return false
 FILE * output_name = fopen(outfilename, "w");
 if(output_name == NULL)
 {
  	return false;
 }

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
 funcptr funcs[] = {func1, func2, func3, func4, func5};
 int length = (sizeof(funcs) / sizeof(funcs[0]));

  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
 for(int i = 0 ; i < length ; i++)
 {
	intrg.func = funcs[i];
	integrate(&intrg);
	val = fprintf(output_name, "%lf\n",(intrg.answer));
 }

  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false
 if(val < 1)
 { 
	fclose(output_name);
	return false;
 }

  // after going through all functions in funcs
  // close the output file
 fclose(output_name);

  // if the function reaches here, return true
 return true; 
}
#endif // RUN_INTEGRATE
