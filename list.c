// list/list.c
// 
// Implementation for linked list.
//
// Devin Griffin

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* newList = (list_t*)malloc(sizeof(list_t));
    if (newList == NULL) {
        perror("Memory allocation failed");
        return;
    }
    newList->head = NULL;
    return newList;

}
void list_free(list_t **l) {
    if (l == NULL || *l == NULL) {
        return; // Handle invalid input
    }

    while ((*l)->head != NULL) {
        node_t *temp = (*l)->head;
        (*l)->head = (*l)->head->next;
        free(temp);
    }
    free(*l);
    *l = NULL; 
}

void list_print(list_t *l) {
    if (list_length(l) == 0){
        printf("Empty list");
    }
    node_t* current = l->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

char* listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) { 
  int length = 0;
  node_t* current = l->head;
  while (current != NULL) {
      length++;
      current = current->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return;
    }
    newNode->value = value;
    newNode->next = NULL;

    if (l->head == NULL) {
        // If the list is empty, set the new node as the head
        l->head = newNode;
    } else {
        // Find the last node in the list and update its 'next' pointer
        node_t* current = l->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void list_add_to_front(list_t *l, elem value) {
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return;
    }
    newNode->value = value;
    newNode->next = l->head;
    l->head = newNode;
}
// add to end if index is greater than list, add to front if negative
void list_add_at_index(list_t *l, elem value, int index) {
  if (index <= 0) {
    list_add_to_front(l, value);
    return;
  }
  if (index > list_length(l)){
    list_add_to_back(l, value);
    return;
  }

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        return;
    }
    newNode->value = value;

    if (index == 1) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
        node_t* current = l->head;
        int i;
        for (i = 1; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

}

elem list_remove_from_back(list_t *l) { 
   if (l->head != NULL) {
        if (l->head->next == NULL) {
            // If there's only one node in the list, remove it
            free(l->head);
            l->head = NULL;
        } else {
            // Find the second-to-last node and remove the last node
            node_t* current = l->head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
    }
 }
elem list_remove_from_front(list_t *l) { 
   if (l->head != NULL) {
        node_t* temp = l->head;
        l->head = l->head->next;
        free(temp);
    }
 }
elem list_remove_at_index(list_t *l, int index) { 
   if (index <= 0 || index >= list_length(l)) {
        return -1 ;
    }

    if (index == 1) {
        node_t* temp = l->head;
        l->head = l->head->next;
        free(temp);
    } else {
        node_t* current = l->head;
        int i;
        for (i = 1; i < index - 1; i++) {
            current = current->next;
        }
        node_t* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

bool list_is_in(list_t *l, elem value) { 
  node_t* current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            return true; // Value found
        }
        current = current->next;
    }
    return false; // Value not found
}
elem list_get_elem_at(list_t *l, int index) { 
  if (index <= 0 || index > list_length(l)) {
        return -1;
    }
  
    node_t* current = l->head;
    int i;
    for (i = 1; i < index; i++) {
        current = current->next;
    }
    return current->value;

}
int list_get_index_of(list_t *l, elem value) { 
  int index = 1;
    node_t* current = l->head;
    while (current != NULL) {
        if (current->value == value) {
            return index; // Value found at this index
        }
        current = current->next;
        index++;
    }
    return -1; // Value not found in the list

 }

