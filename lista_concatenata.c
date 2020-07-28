#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "lista_concatenata.h"

List createList() {
    List l = (List)malloc(sizeof(struct list));
    if (l != NULL) {
        l->head = NULL;
        l->curN = NULL;
    }
    else
        printf("list not created. No memory available.\n");
    return l;
}

void printList(List l) {
   if (l != NULL) {
        Node n = l->head;
       printf("\n[ ");
       while(n != NULL) {
          printf("Domanda: %s \n", n->domanda.domanda);
		  printf("R1: %s \n", n->domanda.r1);
		  printf("R2: %s \n", n->domanda.r2);
		  printf("R3: %s \n", n->domanda.r3);
		  printf("R4: %s \n", n->domanda.r4);
		  printf("Risposta esatta: %d \n\n", n->domanda.risposta_corretta);
          n = n->next;
       }
       printf(" ]\n");
   }
   else
      printf("cannot print a NULL list!\n");
}

bool insertFirst(List l, domanda domanda) {
   Node node = (Node)malloc(sizeof(struct node));
   bool inserted = false;
   if(l != NULL && node != NULL) {
       node->domanda = domanda;
       node->next = l->head;
       l->head = node;
       inserted = true;
   }
   else
        printf("No memory available.\n");
   return inserted;
}

/*int deleteFirst(List l) {
    int deletedValue = INT_MIN;
    if (l != NULL) {
       Node tempNode = l->head;
       l->head = l->head->next;
       deletedValue = tempNode->data;
       free(tempNode);
    }
    return deletedValue;
}*/

bool isEmpty(List l) {
   return l == NULL || l->head == NULL;
}

int length(List l) {
   int length = INT_MIN;

   if (l != NULL) {
       length = 0;
       Node current = l->head;
       while(current != NULL) {
            current = current->next;
            length++;
       }
   }

   return length;
}

/*bool insertAfter(List l, int p, int data) {
    bool inserted = false;
    if (l != NULL) {
        Node q = (Node)malloc(sizeof(struct node));
        if (q != NULL) {
            q->data = data;

            Node pNode = l->head;
            bool trovato = false;

            while(!trovato && pNode != NULL) {
                if(pNode->data == p) {
                    q->next = pNode->next;
                    pNode->next = q;
                    inserted = true;
                    trovato = true;
                }
                else
                    pNode = pNode->next;
            }
        }
        else
            printf("%d not inserted. No memory available.\n", data);
    }
    return inserted;
}*/

/*bool find(List l, int data) {
    bool trovato = false;
    if (l != NULL) {
        Node current = l->head;

        while(!trovato && current != NULL) {
            if(current->data == data)
                trovato = true;
            else
                current = current->next;
        }
    }
    return trovato;
}*/

/*bool delete(List l, int data) {
    bool trovato = false;
	if (l != NULL) {
        Node previous = NULL;
        Node current = l->head;

        while(!trovato && current != NULL) {
            if(current->data == data)
                trovato = true;
            else {
                previous = current;
                current = current->next;
            }
        }

        //if found a match, update the node..
        if(current != NULL) {
            if(current == l->head)
                l->head = l->head->next;
            else
                previous->next = current->next;
           free(current);
        }
    }
    return trovato;
}*/

bool hasNext(List l) {
	return l != NULL && l->curN != NULL;
}

void resetCursor(List l) {
    if (l != NULL)
        l->curN = l->head;
}

/*int next(List l) {
    Node temp = NULL;
    int value = INT_MIN;
    if (hasNext(l)) {
        temp = l->curN;
        value = temp->data;
        l->curN = l->curN->next;
    }
    return value;
}*/

/*bool insertSorted(List l, int data) {
	bool inserted = false;
	if (l != NULL) {
        Node new_nod, previous = NULL, current = NULL;
        new_nod = (Node)malloc(sizeof(struct node));
        if (new_nod != NULL) {
            new_nod->data = data;
            new_nod->next = NULL;
            previous = NULL;
            current = l->head;
            while (current != NULL && data > current->data) {
                previous = current;
                current = current->next;
            }
            // Insert new node at beginning of list
            if (previous == NULL) {
                new_nod->next = l->head;
                l->head = new_nod;
            }
            else { //Insert new node between previous and current
                previous->next = new_nod;
                new_nod->next = current;
            }
            inserted = true;
        }
        else
            printf("%d not inserted. No memory available.\n", data);
	}

	return inserted;
}*/
