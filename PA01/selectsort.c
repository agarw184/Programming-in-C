//#ifdef SELECTION_SORT
#include "pa01.h"
void selectSort(int * arr, int size)
{                                                                        
	int min = 0 ;                         //Minimum Index 
	                                      //Assuming size is greater than 0 
    for(int i = 0 ; i < size - 1 ; i++)   //'i' used as counter-variable used for outer-loop
    {
		min = i;                                
	
	    for(int j = i + 1; j < size ; j++) //Finds the minimum element in the unsorted array and 'j' is used as counter-variable used for inner-loop
	    {
		    if(arr[j] < arr[min])
		    {
				min = j;
		    }
		}
		    if(min != i)
		    {
				swap(&arr[i], &arr[min]); //Swaps the found minimum element with the other
		    }
		
	}
}	
//#endif
// Submitted by : Abhimanyu Agarwal , 0031135872
