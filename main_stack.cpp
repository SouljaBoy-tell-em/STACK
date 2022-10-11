//\file
///\/brief This file can show "The STACK program."


#include "head_stack.h"
#include "stack.h"


int main (void) {

	Stack stack = {};
	STACKNAME (stack.name, stack);
	//strcpy (stack.name, STACKNAME (stack));
	dumpFileCleaning ();
	StackCtor (&stack, 25);
	

	for (int i = 0; i < 30; i++)
		StackPush (&stack, (Elem_t) (i + 1));

	//for (int i = 0; i < 3; i++)
	//	StackPop (&stack);

	return 0;
}
