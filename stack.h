//
//  stack.h
//  study
//
//  Created by Ruzhe on 14-4-1.
//  Copyright (c) 2014年 Ruzhe. All rights reserved.
//

#ifndef study_stack_h
#define study_stack_h


#include "list.h"

typedef List Stack;

Stack *initStack();
bool isEmpty(Stack *stack);
void push(Stack *stack, TYPE val);
TYPE top(Stack *stack);
TYPE pop(Stack *stack);
void destroyStack(Stack **stackPointer);


#endif
