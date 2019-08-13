#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "calc.h"
#include "stack.h"

float calculator (float val1,float val2,char ch, Stack* s, float * result)
{

	switch(ch) 
	{
		case '+': *result = (val1 + val2);
				  break;                        
		case '-': *result = (val2 - val1);
				  break;
		case '*': *result = (val1 * val2);
				  break;
		case '/': if (val1 == 0)
				  {
				  	*result = (val2 / val1);  
				  }else{
				  	*result = (val2 / val1);
				  }
	}
	return *result ;
}
