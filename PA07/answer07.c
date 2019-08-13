#include "answer07.h"

bool isCircular(const node_t * head)
{
	if(head == NULL)                         
	{
		return false;
	}
	const node_t * slowptr = head;
	const node_t * fastptr = head;

	while((fastptr != NULL) && (fastptr -> next != NULL))
	{
		slowptr = slowptr -> next;
		fastptr = fastptr -> next -> next;

		if(fastptr == slowptr)
		{
			return true;
		}
	}
	return false;
}
