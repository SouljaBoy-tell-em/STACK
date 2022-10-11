//\file
///\/brief This file is header. This file contains program libraries, constants, enum cases and INFO about functions."


#ifndef _FUNC_H__
#define _FUNC_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>


#define MAXLEN 512
#define CANARY 0xDEDDED32
#define HASH_COEFFICIENT 0xDEADF00D
#define RATIO_SIZE_STACK 2
#define DETERMINERROR 000000001
#define POISON -228.228
#define STACKNAME(INIT, var) strcpy (INIT, (#var))
#define STATUS(codeError) (codeError) ? "error": "ok"
#define CHECK_ERROR(condition, message_error) 				 \
            do {                                          \
               if  (condition) {                          \
                   printf ("%s", message_error);          \
                   return 1;                              \
               }                                          \
            } while(false)


typedef double Elem_t;
typedef struct {

	long long startStructCanary;
	char name [MAXLEN];
	Elem_t * data;
	int size;
	int capacity;
	unsigned int code_of_error;
	long long hash_stack;
	Elem_t hash_data;
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


//! This function clears the dump-file;
void dumpFileCleaning (void);


//! This function can decode the errors, which stack gets in the work result;
//! @param [in] stack - pointer of the stack;
//! @param [in] dump - pointer of the dump-file.
void errorsDecoder (Stack * stack, FILE * dump);


//! This function can calculate code of error on the every stage;
//! @param [in] stack - pointer of the stack;
//! @return code of error.
unsigned int fullCodeError (Stack * stack);


//! This function can calculate code of error on the every stage;
//! @param [in] stack - pointer of the stack;
//! @return code of error.
uint8_t * getStartData (Stack * stack);


//! This function counts hash of the Elem_t data;
//! @param [in] stack - pointer of the stack;
//! @return hash of the Elem_t data.
unsigned int hashFunction (Stack * stack);


//! This function clears the Elem_t data;
//! @param [in] stack - pointer of the stack.
void StackClear (Stack * stack);


//! This function can create stack;
//! @param [in] stack - pointer of the stack;
//! @param [in] capacity - maximal amount of elements in the stack.
void StackCtor (Stack * stack, int capacity);


//! This function records info about the stack in the dump-file;
//! @param [in] stack - pointer of the stack;
//! @param [in] lineStackDump - string, where the StackDump was call;
//! @param [in] nameFunctionDump - name of function, where the StackDump was call;
//! @param [in] fileFunctionDump - name of file, where the StackDump was call.
void StackDump (Stack * stack, int lineStackDump, const char * nameFunctionDump, const char * fileFunctionDump);


//! This function checks the stack-errors;
//! @param [in] stack - pointer of the stack.
void StackError (Stack * stack);


//! This function show all-info about the stack;
//! @param [in] stack - pointer of the stack;
//! @param [in] stack - pointer of the dump-file.
void StackInfoDump (Stack * stack, FILE * dump);


//! This function destroys element of the stack;
//! @param [in] stack - pointer of the stack.
void StackPop (Stack * stack);


//! This function adds element of the stack;
//! @param [in] stack - pointer of the stack;
//! @param [in] addDataElement - adding element in the stack.
void StackPush (Stack * stack, Elem_t addDataElement);


//! This function increases max capacity of the stack;
//! @param [in] stack - pointer of the stack.
void StackReSizeDown (Stack * stack);

//! This function lowers max capacity of the stack;
//! @param [in] stack - pointer of the stack;
//! @param [in] stack - element, which adding in the stack.
void StackReSizeUp (Stack * stack, Elem_t addDataElement);


//! This function pours the stack elements by POISON;
//! @param [in] stack - pointer of the stack.
void UninititalizeElements (Stack * stack);


#endif
