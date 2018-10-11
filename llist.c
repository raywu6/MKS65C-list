#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

// Raymond Wu
// Systems p10
// Lab -- Linked List
// 2018-10-11

void print_list (struct node *n) {

  printf("[");
  
  // can't use n->next b/c n might be NULL
  while (n) {
    printf("%d, ", n->i);
    n = n->next;
  }
  
  printf("]\n");
}

struct node * insert_front (struct node *n , int newInt) {
  struct node *newNode;
  newNode = malloc( sizeof(struct node) );
  newNode->i = newInt;
  newNode->next = n;

  return newNode;
}

struct node * free_list (struct node *n) {
  struct node *follower = n;
  
  while (n) {
    n = n->next;
    free(follower);
    follower = n;
  }

  return n;
}
