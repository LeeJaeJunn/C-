#pragma once

typedef struct _NODE
{
  char data;
  struct _NODE* next;
}
NODE;

void addHead(NODE* pHead, char data);
void addTail(NODE* pHead, char data);
void removeHead(NODE* pHead);
void removeTail(NODE* pHead);
void print(NODE* pHead);
char getHead(NODE* pHead);
char getTail(NODE* pHead);
int isEmpty(NODE* pHead);
int countNode(NODE* pHead);
void clear(NODE* pHead);
NODE* findData(NODE* pHead, char data);
void insertData(NODE* pHead, char data);
void deleteData(NODE* pHead, char data);
