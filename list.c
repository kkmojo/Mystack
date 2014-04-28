//
//  list.c
//  study
//
//  Created by Ruzhe on 14-3-26.
//  Copyright (c) 2014年 Ruzhe. All rights reserved.
//

#include "list.h"

List *createList()
{
    
    List *list = NEW(List);
    list->length = 0;
    return list;
    
}

void listAdd(List *list, TYPE val)
{
    Node *newNode= NEW(Node);
    newNode->val = val;
    newNode->next = NULL;
    
    
    if(list->length == 0)
    {
        list->head = newNode;
        list->tail = list->head;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    
    list->length++;
}

void listRemove(List *list, int index)
{
    Node *p = list->head;
    Node *q;
    Node *needRemoved;
    
    if(index <= list->length)
    {
        for(int i = 1; i<index; i++)
        {
            q = p;
            p = p->next;
        }
        
        needRemoved = p;
        p = p->next->next;
        q->next = p;
        free(needRemoved);
    }
    else
    {
        LOG_ERROR("index larger than length");
    }
    
    list->length--;
}

TYPE listGet(List *list, int index)
{
    if(list->length == 0)
    {
        LOG_ERROR("Empty list");
    }
    else
    {
        Node *p = list->head;
        if(index <= list->length)
        {
            for (int i = 1; i<index; i++)
            {
                p = p->next;
            }
        }
        else
        {
            LOG_ERROR("index larger than length");
        }
        
        return p->val;
    }
    
}

void listInsert(List *list, TYPE val, int index)
{
    if(index <= list->length && index > 0)
    {
        Node *p = list->head;
        Node *q;
        Node *needInsert = NEW(Node);
        needInsert->val = val;
        
        
        if(index == 1)
        {
            needInsert->next = p;
            list->head = needInsert;
            
        }
        else
        {
            for(int i = 1; i<index; i++)
            {
                q = p;
                p = p->next;
            }
            
            p = p->next->next;
            q->next = needInsert;
            needInsert->next = p;
        }
    }
    else
    {
        LOG_ERROR("index larger than length");
    }
}

void destroyList(List **listPointer)
{
    List *list = *listPointer;
    
    if(list->length == 0)
    {
        free(list);
    }
    else
    {
        Node *p;
        Node *q;
        p = list->head;
        
        while(p->next != NULL)
        {
            q = p;
            p = p->next;
            free(q);
            
        }
        free(p);
        free(list);
    }
}
