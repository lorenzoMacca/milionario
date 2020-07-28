#ifndef LISTA_CONCATENATA_H    // include guard
#define LISTA_CONCATENATA_H 

#include <stdbool.h>
#include <string.h>

typedef struct {
	char domanda [100];
	char r1 [20];
	char r2 [20];
	char r3 [20];
	char r4 [20];
	int risposta_corretta;
} domanda;

//typedef struct domanda *Domanda;

struct node {
  domanda domanda;
  struct node *next;
};

typedef struct node *Node;

struct list {
    Node head;
    Node curN;
};

typedef struct list *List;

// return a pointer to a new list
List createList();

//print the list to screen
void printList(List list);

//insert data at the head of the list
bool insertFirst(List list, domanda domanda);

//delete head item of the list
int deleteFirst(List list);

//return 'true' if the list is empty, 'false' otherwise
bool isEmpty(List list);

// current size of the list
int length(List list);

//insert a new node with value 'n' after the (first) node with value 'p'
bool insertAfter(List list, int p, int n);

//return 'true' is the list contains the given data
bool find(List list, int data);

//delete the first node with the given data
bool delete(List list, int data);

// to iterate over the list (i.e. to visit node-by-node the list),
// you should always check if there is a next node before invoking the 'next' function
bool hasNext(List list);

// bring the cursor of the iterator back to the first item of the list
void resetCursor(List list);

// return the data value of the node in the current position of the iteration cursor
int next(List list);

// Insert a new value into the list in sorted order
bool insertSorted(List l, int data);

#endif