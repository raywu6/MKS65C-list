
// Raymond Wu
// Systems pd10
// Lab -- Linked List
// 2018-10-10

// struct prototype
struct node {int i ; struct node *next ;};

// methods
void print_list (struct node *);

struct node * insert_front (struct node * , int);

struct node * free_list (struct node *);
