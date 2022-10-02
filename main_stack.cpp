#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define CANARY 0xDEDDED32
#define RATIO_SIZE_STACK 2
#define POISON -228.0
#define CHECK_ERROR(condition, message_error) \
            do {                                          \
               if (condition) {                           \
                   printf ("%s", message_error);          \
                   return 1;                              \
               }                                          \
            } while(false)


typedef double Elem_t;
typedef struct {

	long long startStructCanary;
	Elem_t * data;
	int size;
	int capacity;
	unsigned int code_of_error;
	long long finishStructCanary;
} Stack;	 


enum errors {

	NO_ERROR = 0,
	BAD_DATA = 1 << 1,
	BAD_SIZE = 1 << 2,
	BAD_CAPACITY = 1 << 3,
	OVERFLOW = 1 << 4,
	BAD_START_ELEM_T_CANARY = 1 << 5,
	BAD_FINISH_ELEM_T_CANARY = 1 << 6,
	BAD_START_STRUCT_CANARY = 1 << 7,
	BAD_FINISH_STRUCT_CANARY = 1 << 8,
	STACK_NULL = 1 << 9
};


void dumpFileCleaning (void);
bool StackCtor (Stack * stack, int capacity);
void StackPush (Stack * stack, Elem_t addDataElement);
void StackError (Stack * stack);
void StackDumpErrors (Stack * stack);
void StackReSize (Stack * stack);



int main (void) {

	Stack stack = {};

	dumpFileCleaning ();
	CHECK_ERROR (!StackCtor (&stack, 8), "Stack has null-pointer in main ().");

/*
	for (int i = 0; i < 10; i++)
		StackPush (&stack, (double) i);

	for (int i = 0; i < 10; i++)
		printf ("Elem: %lf; size: %d; adress: %p; capacity: %d;\n", stack.data[i], stack.size, &stack.data[i], stack.capacity);

	printf ("CANARY_START: %x; adress: %p\n", stack.startStructCanary, &stack.startStructCanary);
	printf ("CANARY_FINISH: %x; adress: %p\n", stack.finishStructCanary, stack.finishStructCanary);

	*/

	return 0;
}


void dumpFileCleaning (void) {

	FILE * dumpfile = fopen ("dumpfile.txt", "w");
	fclose (dumpfile);
}


bool StackCtor (Stack * stack, int capacity) {

	if (stack == NULL)
		return false;

	stack->code_of_error = NO_ERROR;

	if ((stack->data = (Elem_t * ) calloc (capacity + 2, sizeof (Elem_t))) == NULL)
		stack->code_of_error = BAD_DATA;

	stack->capacity = capacity;
	if (stack->capacity < 0)
		stack->code_of_error = BAD_CAPACITY;

	stack->size                                            =      0;
	stack->startStructCanary                               = CANARY;
	stack->finishStructCanary                              = CANARY;
	* ((long long * ) stack->data)                         = CANARY;
	* ((long long * )(stack->data + stack->capacity) + 1)  = CANARY;

	return true;
}


void StackPush (Stack * stack, Elem_t addDataElement) {


	if (stack->size > stack->capacity)
		 StackReSize (stack);

	* (stack->data + stack->size) = addDataElement;
	stack->size++;

}


void StackError (Stack * stack) {

	if (stack == NULL)
		stack->code_of_error = STACK_NULL;

	if (stack->data == NULL)
		stack->code_of_error = BAD_DATA;

	if (stack->size < 0)
		stack->code_of_error = BAD_SIZE;

	if (stack->capacity < 0)
		stack->code_of_error = BAD_CAPACITY;

	if (stack->capacity > stack->size)
		stack->code_of_error = OVERFLOW;

	if (stack->startStructCanary != CANARY)
		stack->code_of_error = BAD_START_ELEM_T_CANARY;

	if (stack->finishStructCanary != CANARY)
		stack->code_of_error = BAD_FINISH_ELEM_T_CANARY;

	if ( * ((long long * ) stack->data) != CANARY)
		stack->code_of_error = BAD_START_ELEM_T_CANARY;

	if ( * ((long long * )(stack->data + stack->capacity) + 1) != CANARY)
		stack->code_of_error = BAD_START_ELEM_T_CANARY;

	//if (stack->code_of_error != 0)
		//StackDumpErrors (stack);
}


void StackDumpErrors (Stack * stack) {


} 

void StackReSize (Stack * stack) {

	StackError (stack);
	* ((Elem_t * )(stack->data + stack->capacity)) = POISON;
	stack->data = (Elem_t * ) realloc (stack->data, sizeof (Elem_t) * (RATIO_SIZE_STACK * stack->capacity + 2));
	stack->capacity =  RATIO_SIZE_STACK * stack->capacity;
	* ((long long * )(stack->data + stack->capacity) + 1) = CANARY;
	StackError (stack);
}


void IncreaseMemory () {



}
