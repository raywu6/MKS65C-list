#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

// Raymond Wu
// Systems p10
// Lab -- Linked List
// 2018-10-11

int main() {

  // prepare them linked lists...
  
  struct node *myNodeList0;
  struct node *myNodeList1;
  
  myNodeList0 = malloc( sizeof(struct node) );
  myNodeList1 = malloc( sizeof(struct node) );
  
  myNodeList0->i = 1;
  myNodeList0->next = NULL;

  myNodeList1->i = 2;
  myNodeList1->next = NULL;

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING print_list(struct node *)
   * * * * * * * * * * * * * * * * * * * * * * * */
 
  print_list(myNodeList0);  // [1]
  print_list(myNodeList1);  // [2]

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING insert_front(struct node * , int)
   * * * * * * * * * * * * * * * * * * * * * * * */ 

  myNodeList0 = insert_front(myNodeList0 , 3);
  print_list( myNodeList0 );  // [3, 1]

  myNodeList1 = insert_front(myNodeList1 , 4);
  print_list( myNodeList1 );  // [4, 2]

  /* * * * * * * * * * * * * * * * * * * * * * * *
     TESTING free_list(struct node *)
   * * * * * * * * * * * * * * * * * * * * * * * */ 
  
  myNodeList0 = free_list(myNodeList0);
  print_list( myNodeList0 );  // []
  
  return 0;
}
