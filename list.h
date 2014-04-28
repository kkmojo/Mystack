#ifndef ds_list_h
//if not define
#define ds_list_h
//then define this

#include <stdio.h>
#include <stdlib.h>

#define TYPE int
#define NEW(TYPE) (TYPE*)malloc(sizeof(TYPE))
#define NEW_ARRAY(TYPE,LEN) (TYPE*)malloc(sizeof(TYPE)*LEN)
#define LOG_ERROR(MSG) printf("FILE: %s\nLINE: %d\n%s\n",__FILE__,__LINE__,MSG);exit(-1);

typedef struct _node{
    TYPE val;
    struct _node *next;
} Node;

typedef struct _list{
    Node *head;
    Node *tail;
    int length;
} List;

typedef int bool;

List *createList();
void listAdd(List *list, TYPE val);
void listRemove(List *list, int index);
TYPE listGet(List *list, int index);
void listInsert(List *list, TYPE val, int index);
void destroyList(List **listPointer);

#endif
