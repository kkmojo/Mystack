//
//  stack.c
//  study
//
//  Created by Ruzhe on 14-4-2.
//  Copyright (c) 2014年 Ruzhe. All rights reserved.
//

#include "stack.h"

Stack *iniStack()
{
    Stack *stack = NEW(Stack);
    stack->length = 0;
    return stack;
}

bool isEmpty(Stack *stack)
{
    return stack->length == 0;
}

void push(Stack *stack, TYPE val)
{
    Node *newNode = NEW(Node);
    newNode->val = val;
    newNode->next = NULL;
    
    if(isEmpty(stack))
    {
        stack->head = newNode;
        stack->tail = newNode;
    }
    else
    {
        stack->tail->next = newNode;
        stack->tail = newNode;
    }
    stack->length++;
    
}

TYPE top(Stack *stack)
{
    if(isEmpty(stack))
    {
        LOG_ERROR("Stack is Empty");
    }
    else
    {
        return stack->tail->val;
    }
}

TYPE pop(Stack *stack)
{
    if(isEmpty(stack))
    {
        LOG_ERROR("Stack is Empty");
    }
    else
    {
        Node *p = stack->head;
        Node *q;
        
        while(p->next != NULL)
        {
            q=p;
            p=p->next;
        }
        
        return p->val;
        q->next = NULL;
        stack->tail = q;
        free(p);
    }
    stack->length--;
}


void destroyStack(Stack **stackPointer)
{
    Stack *stack = *stackPointer;
    
    if(isEmpty(stack))
    {
        free(stack);
    }
    
    else
    {
        Node *p = stack->head;
        Node *q = p;
        
        while (p->next != NULL)
        {
            q = p;
            p = p->next;
            free(q);
        }
        free(p);
        free(stack);
    }
}