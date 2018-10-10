#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

// Raymond Wu
// Systems p10
// Lab -- Linked List
// 2018-10-10

void print_list (struct node *n) {
  printf("[");
  
  while (n->next) {
    printf("%d, ", n->i);
    n = n->next;
  }
  
  printf("%d]\n", n->i);
}

struct node * insert_front (struct node *n , int newInt) {
  struct node *newNode;
  newNode = malloc( sizeof(struct node) );
  newNode->i = newInt;
  newNode->next = n;

  return newNode;
}

struct node * free_list (struct node *n) {
  struct node *leaderPtr   = n;  // if delete self
  struct node *followerPtr = n;  // how to go to next node?
  
  while (leaderPtr->next) {
    leaderPtr = leaderPtr->next;
    free(followerPtr);
    followerPtr = leaderPtr;
  }
  free(leaderPtr);

  return n;
}

int main() {
  struct node *myNode0;
  struct node *myNode1;
  struct node *myNode2;

  myNode0 = malloc( sizeof(struct node) );
  myNode1 = malloc( sizeof(struct node) );
  myNode2 = malloc( sizeof(struct node) );
  
  myNode0->i = 1;
  myNode0->next = myNode1;

  myNode1->i = 3;
  myNode1->next = myNode2;

  myNode2->i = 5;
  myNode2->next = 0;  // NULL

  struct node *myNode3;
  struct node *myNode4;
  struct node *myNode5;

  myNode3 = malloc( sizeof(struct node) );
  myNode4 = malloc( sizeof(struct node) );
  myNode5 = malloc( sizeof(struct node) );
  
  myNode3->i = 2;
  myNode3->next = myNode4;

  myNode4->i = 4;
  myNode4->next = myNode5;

  myNode5->i = 6;
  myNode5->next = 0;  // NULL

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING insert_front(struct node * , int)
   * * * * * * * * * * * * * * * * * * * * * * * */
  
  print_list(myNode0);  // [1, 3, 5]
  print_list(myNode1);  // [3, 5]
  print_list(myNode3);  // [2, 4, 6]
  print_list(myNode5);  // [6]

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING insert_front(struct node * , int)
   * * * * * * * * * * * * * * * * * * * * * * * */ 

  print_list( insert_front(myNode0, -1) );  // [-1, 1, 3, 5]
  print_list( insert_front(myNode3,  0) );  // [0, 2, 4, 6]

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING free_list(struct node *)
   * * * * * * * * * * * * * * * * * * * * * * * */ 

  free_list(myNode0);
  printf("%d\n", myNode0->i);     // 0 / NULL
  printf("%p\n", myNode0->next);  // 0x?000000000000000
  //                                 NULL? is that you?
  // print_list(myNode0);  // seg fault
  
  return 0;
}
