#include "msort.h"
#include "student.h"
#include <stdio.h>

#ifndef OMIT_MSORT
void msort(Student * base, int nel, int (*compar)(const void *, const void *)) 
{
	
	//Base case: if the array has one or fewer elements, it's already sorted
	//so just return.

	//FILL IN
	if(nel <= 1)
	{
		return;
	}
	
	//Inductive case: split the array in two, sort the two pieces with msort,
	//merge the	sorted pieces
		
	//We're going to do this without explicitly creating the two separate arrays
	//We'll take advantage of the fact that to C, an array is just a pointer to
	//a region of memory. If we call msort on base, but pass in a smaller number
	//of elements, it will sort just that subarray. Similarly, if we call msort
	//but pass in the address of an element in the middle of the array, it will
	//sort the array *starting* from that element.
		
	//1. Find the midpoint of the array
	//FILL IN
	int midpoint = (nel / 2);                    //Midpoint of the array

	//2a. Sort the first half of the array (remember to adjust the # elements)

	//FILL IN
	msort(base, midpoint, compar);
	
	//2b. Sort the second half of the array. Pass in the address of the 
	//beginning of the second half of the array (remember to use the right # of 
	//elements)

	//FILL IN
	msort(&(base[midpoint + 1]), (nel - midpoint - 1), compar);
	
	//3a. Merge the two arrays (use merge)

	//FILL IN
	Student * newarr = merge(base, midpoint, (&(base[midpoint])), (nel - midpoint), compar); 
	
	//3b. Copy the merged array over top of the original array (use copy)
	//Don't forget to free the array you no longer need!

	//FILL IN
	copy(base, newarr, nel);
	free(newarr);                 
}
#endif

#ifndef OMIT_MERGE
Student * merge(Student * base1, int nel1, Student * base2, int nel2, int (*compar)(const void *, const void *)) {
	
	//1. Allocate space for the returned merged array
	
	//FILL IN
	int totallen = 0;                //stores the net sum of the number of elemnts obtained using (nel1 + nel2)
	totallen = (nel1 + nel2);

	Student * newarr = malloc(sizeof(Student) * (totallen));

	//base case for the merge function 
	if((nel1 == 0) || (nel2 == 0))
		{
			return newarr;
		}	
	//2. Create indices to keep track of where you are in the three arrays

	//FILL IN
	int basecounter1 = 0;                       //Goes through base-1
	int basecounter2 = 0;                       //Goes through base-2
	int final = 0;                              //Goes through totallen
	int result = 0;                             //Stores the value returned by compar which could be either -1 , 0 or 1
	//3. Go through base1 and base2, and merge them into the returned array

	//FILL IN
	for(final = 0; final < totallen; final++)
	{
		if(basecounter1 == nel1)
		{
			newarr[final] = base2[basecounter2];
			basecounter2++;	
		}
		else if(basecounter2 == nel2) 
		{
			newarr[final] = base1[basecounter1];
			basecounter1++;
		}
		else
		{
			result = compar(&base1[basecounter1], &base2[basecounter2]);
			if(result > 0)
			{
				newarr[final] = base2[basecounter2];
				basecounter2++;
			}
			else
			{
				newarr[final] = base1[basecounter1];
				basecounter1++;
			}
		}
	}

	//4. Return the merged array

	//FILL IN
    return newarr; 
}


void copy(Student * to, Student * from, int nel) {
	/*
	An efficient implementation of this would use memcpy:
	memcpy(to, from, nel * width);

	We will do an element-by-element copy so you can see how it is done
	*/
	
	//loop over the from array and copy it byte by byte to the to array.
	for (int i = 0; i < nel; i++) {
		to[i] = from[i];
	}
	
	return;
}
#endif
