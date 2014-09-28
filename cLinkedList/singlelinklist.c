/*
   singlelinklist.c

   Author: Paul Sitoh
 
   This is a very trivial demonstration of an
   implementation of single link list. 

   On Mac and Linux, to create an executable
   issue the following commands:

      gcc -o main singlelinklist.c

 */

#include <stdlib.h>
#include <stdio.h>

// List node
typedef struct node_{
  void *data;
  struct node_ *next;
} Node;

// Create a list with the first item.
void initialize(Node **list, void *data){

  *list = (Node*) malloc(sizeof(Node));
  (*list)->data = data;
  (*list)->next = NULL;

}

// Add data to the end of the list
void add(Node *list, void *data){

  Node *_node = list;

  while( NULL != _node->next ){
    _node = _node->next;
  }

  Node *_newNode = (Node*) malloc(sizeof(Node));
  _newNode->data = data;
  _newNode->next = NULL;

  _node->next = _newNode;
}

void displayList(Node *list){

  Node *_node = list;

  do{
    printf("Data->%i\n", *((int*)_node->data));
    _node = _node->next;
  }while ( NULL != _node->next );

  printf("Data->%i\n", *((int*)_node->data));

}

int main(int argc, char **argv){

  Node *list;

  int *_pi0 = (int*) malloc(sizeof(int));
  *_pi0 = 0;

  initialize(&list,_pi0);

  int *_pi1 = (int*) malloc(sizeof(int));
  *_pi1 = 1;

  add(list, _pi1);

  displayList(list);

  // Note there is no routine to free memory.

}
