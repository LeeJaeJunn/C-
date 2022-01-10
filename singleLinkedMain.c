#include "singleLinked.h"
#include <stdio.h>
#include <stdlib.h>

void addHead(NODE *pHead, char data) {
  NODE *pNode = malloc(sizeof(NODE));
  pNode->data = data;

  pNode->next = pHead->next;
  pHead->next = pNode;
}

void addTail(NODE *pHead, char data) {
  NODE *cur = pHead;
  while (cur->next != NULL)
    cur = cur->next;

  addHead(cur, data);
}

void removeHead(NODE *pHead) {
  NODE *pNode = pHead->next;
  pHead->next = pNode->next;
  free(pNode);
}

void removeTail(NODE *pHead) {
  NODE *cur = pHead;
  while (cur->next->next != NULL)
    cur = cur->next;

  removeHead(cur);
}

// 정방향 출력 함수
void print(NODE *pHead) {
  NODE *cur = pHead->next;
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;
  }

  printf("\n");
}

// 첫번째 노드 머리 노드의 데이터 반환
char getHead(NODE *pHead) { return pHead->next->data; }

// 마지막 노드 꼬리 노드의 데이터 반환
char getTail(NODE *pHead) {
  NODE *cur = pHead;
  while (cur->next != NULL)
    cur = cur->next;

  return cur->data;
}

// 비어있는 리스트인지 검사. 비어있으면 TRUE(1), 노드가 있으면 FALSE(0)을 반환
int isEmpty(NODE *pHead) { return pHead->next == NULL; }

// 리스트에 포함된 노드의 개수 반환
int countNode(NODE *pHead) {
  int count;
  NODE *cur = pHead->next;

  for (count = 0; cur != NULL; count++)
    cur = cur->next;

  return count;
}

// 모든 노드를 삭제
void clear(NODE *pHead) {
  while (isEmpty(pHead) == 0)
    removeHead(pHead);
}

// 일치하는 데이터를 찾아 해당 노드의 포인터를 반환, 찾는 데이터가 없으면 NULL
// 포인터를 반환.
NODE *findData(NODE *pHead, char data) {
  NODE *cur = pHead->next;
  while (cur != NULL) {
    if (cur->data == data)
      break;

    cur = cur->next;
  }

  return cur;
}

// 정렬 리스트를 구현하는 함수. 위치를 지정하지 않고 데이터를 삽입하겠다는
// 의지만 표명함.
void insertData(NODE *pHead, char data) {
  NODE *cur = pHead;
  while (cur->next != NULL) {
    if (cur->next->data >= data)
      break;

    cur = cur->next;
  }

  addHead(cur, data);
}

// 일치하는 첫 번쨰 노드를 삭제
void deleteData(NODE *pHead, char data) {
  NODE *cur = pHead;
  while (cur->next != NULL) {
    if (cur->next->data == data) {
      removeHead(cur);
      break;
    }

    cur = cur->next;
  }
}

void main(void) {
  NODE head = {0};
  char str[] = "BLACK";
  int i;

  printf("** 원본 **\n");
  for (i = 0; str[i] != '\0'; i++) {
    addHead(&head, str[i]);
    addTail(&head, str[i]);
  }

  print(&head);
  printf("머리 : %c\n", getHead(&head));
  printf("꼬리 : %c\n", getTail(&head));

  printf("\n** 양끝에서 3문자씩 삭제\n");
  for (i = 0; i < 3; i++) {
    removeHead(&head);
    removeTail(&head);
  }

  print(&head);
  printf("개수 : %d\n", countNode(&head));

  printf("\n** 삭제 후 초기값 삽입 **\n");
  clear(&head);
  for (i = 0; str[i] != '\0'; i++)
    insertData(&head, str[i]);

  print(&head);

  printf("\n** 처음, 마지막, 중간 삭제 **\n");
  deleteData(&head, 'A');
  deleteData(&head, 'L');
  deleteData(&head, 'C');

  print(&head);
  clear(&head);
}