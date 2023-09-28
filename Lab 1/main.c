#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main() {
  int x;
  printf("General Tests\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED\n");
  }
  else {
      printf("list_add_to_front: SUCCESSFUL\n");
  }

  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  if(strcmp("100->90->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }
  else {
    printf("list_remove_at_index: SUCCESSFUL\n");
  }

  list_remove_at_index(mylist, 20);
  list_print(mylist);
  list_remove_at_index(mylist, 1);
  list_print(mylist);
  list_remove_at_index(mylist, 6);
  list_print(mylist);

  
  if(strcmp("90->70->60->50->40->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }
  else {
    printf("list_remove_at_index: SUCCESSFUL\n");
  }
  

  printf("The list length is %d\n", list_length(mylist));

  list_add_to_back(mylist, 39);
  list_print(mylist);
  list_add_to_back(mylist, 18);
  list_add_to_back(mylist, 42);
  list_add_to_back(mylist, 190);
  list_print(mylist);
  
  

  list_add_to_front(mylist, 81);
  list_add_to_back(mylist, 4);
  list_add_to_front(mylist, 308);
  list_add_to_back(mylist, 70);
  list_add_to_front(mylist, 290);
  list_print(mylist);
  printf("The list length is %d\n", list_length(mylist));
  
  list_add_at_index(mylist, 21, 1);
  list_add_at_index(mylist, 65, 0);
  list_add_at_index(mylist, 10, 8);
  list_print(mylist);
  list_add_at_index(mylist, 10, 7);
  list_print(mylist);

  list_remove_from_back(mylist);
  list_print(mylist);
  list_remove_from_front(mylist);
  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  printf("Is %d in the list?: %d\n", 21, list_is_in(mylist, 21));
  printf("Value at %d in the list?: %d\n", 3, list_get_elem_at(mylist, 3));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", -2, list_get_elem_at(mylist, -2));
  printf("Value at %d in the list?: %d\n", 12, list_get_elem_at(mylist, 12));
  printf("Value at %d in the list?: %d\n", 7, list_get_elem_at(mylist, 7));
  printf("Index of %d?: %d\n", 70, list_get_index_of(mylist, 70));
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 0, list_get_index_of(mylist, 0));
  printf("Index of %d?: %d\n", 10, list_get_index_of(mylist, 10));
  printf("Index of %d?: %d\n", 90, list_get_index_of(mylist, 90));
  printf("Index of %d?: %d\n", 81, list_get_index_of(mylist, 81));
  
  
  list_t *mylist2;
  mylist2 = list_alloc();
  list_print(mylist2);
  list_add_at_index(mylist2, -1, -1);
  printf("List after adding at negative index\n");
  list_print(mylist2);
  list_add_to_front(mylist2, 23);
  list_add_to_back(mylist2, 87);
  list_add_at_index(mylist2, 100, 100);
  list_print(mylist2);
  list_remove_from_back(mylist2);
  list_print(mylist2);
  list_remove_from_front(mylist2);
  list_print(mylist2);
  printf("list length is %d\n", list_length(mylist2));
  printf("%d\n", list_get_elem_at(mylist2, 2));
  

  int i;
  for (i = 0; i < 30; i++){
    list_add_to_front(mylist2, i);
    list_print(mylist2);
  }
  for (i = 0; i < 35; i++){
    list_remove_from_back(mylist2);
    list_print(mylist2);
  }
  list_add_at_index(mylist2, -1, -1);
  list_print(mylist);
  list_add_at_index(mylist2, 10, 0);
  list_print(mylist);
  list_add_at_index(mylist2, 20, 1);
  list_print(mylist2);
  printf("The list length is %d\n", list_length(mylist2));
  list_print(mylist2);

  list_remove_from_back(mylist);
  list_remove_from_front(mylist);
  list_remove_at_index(mylist, -3);
  list_remove_at_index(mylist, 0);
  list_remove_at_index(mylist, 2);
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 60);
  list_add_at_index(mylist, 50, 1);
  list_add_at_index(mylist, 0, 6);
  list_add_at_index(mylist, 70, 0);
  list_add_at_index(mylist, 80, 12);
  list_print(mylist);

  // list_alloc stress test
  list_t* lists[1000];
  for (i = 0; i < 1000; i++) {
      lists[i] = list_alloc();
      assert(lists[i] != NULL);
      assert(lists[i]->head == NULL);
  }
  // Deallocate all the lists
  for (i = 0; i < 1000; i++) {
      list_free(&lists[i]);
}

// list_free stress test
list_t* list = list_alloc();
for (i = 0; i < 1000; i++) {
    list_add_to_front(list, i);
}
list_free(&list);
assert(list == NULL);

// list_print edge cases
list_t* list2 = list_alloc();
list_add_to_front(list2, 1000000);
list_add_to_back(list2, 10000000);
list_print(list2); 
list_free(&list2);
  

// list_length edge cases
list_t* list3 = list_alloc();
int length = list_length(list3);
assert(length == 0); 
list_free(&list3);
list_t* list4 = list_alloc();
list_add_to_front(list4, -5);
list_add_to_front(list4, -10);
int length2 = list_length(list4);
assert(length2 == 2); 
list_free(&list4);

// listToString tests
list_t* list5 = list_alloc();
list_add_to_front(list5, 1000000);
list_add_to_front(list5, 10000000);
list_add_to_front(list5, -10000000);
list_add_to_front(list5, 5500);
list_add_to_front(list5, -90452);
assert(strcmp(listToString(list5), "1000000->10000000->-10000000->5500->-90452NULL") != 0); 
list_free(&list5);


// list_add_to_back tests
list_t* list6 = list_alloc();
list_add_to_back(list6, 42);
assert(list_get_elem_at(list6, 1) == 42); 
list_add_to_back(list6, 10);
list_add_to_back(list6, 20);
assert(list_get_elem_at(list6, 2) == 10); 
assert(list_get_elem_at(list6, 3) == 20);
list_free(&list6);

//list_add_to_front tests
list_t* list7 = list_alloc();
list_add_to_front(list7, 42);
assert(list_get_elem_at(list7, 1) == 42); 
list_add_to_front(list7, 10);
list_add_to_front(list7, 20);
assert(list_get_elem_at(list7, 1) == 20); 
assert(list_get_elem_at(list7, 2) == 10); 
list_free(&list7);

// list_add_at_index tests
list_t* list8 = list_alloc();
list_add_at_index(list8, 42, -1);
assert(list_get_elem_at(list8, 1) == 42); // Element added to the beginning
list_add_at_index(list8, 10, 5);
assert(list_get_elem_at(list8, 2) == 10); // Element added at the end
list_add_at_index(list8, 20, 2);
assert(list_get_elem_at(list8, 2) == 20); // Element added at a specific index
list_free(&list8);

// list_remove_from_back tests
list_t* list9 = list_alloc();
list_remove_from_back(list9); // Remove from an empty list, no effect
list_add_to_back(list9, 42);
list_add_to_back(list9, 10);
list_remove_from_back(list9);
assert(list_length(list9) == 1); // Last element removed
list_free(&list9);

// list_remove_from_front tests
list_t* list10 = list_alloc();
list_remove_from_front(list10); // Remove from an empty list, no effect
list_add_to_back(list10, 42);
list_add_to_back(list10, 10);
list_remove_from_front(list10);
assert(list_length(list10) == 1); // First element removed
list_free(&list10);

// list_remove_at_index tests
list_t* list11 = list_alloc();
list_add_to_back(list11, 42);
list_add_to_back(list11, 10);
list_add_to_back(list11, 20);
assert((list_remove_at_index(list11, -10)) == -1); 
assert((list_remove_at_index(list11, 100)) == -1);
assert(list_length(list11) == 3); 
list_remove_at_index(list11, 2); 
assert(list_length(list11) == 2); 
list_remove_at_index(list11, 1); 
assert(list_length(list11) == 1); 
list_free(&list11);

// list_is_in tests
list_t* list12 = list_alloc();
list_add_to_back(list12, 42);
list_add_to_back(list12, 10);
assert(list_is_in(list12, 42) == true); // Element exists
assert(list_is_in(list12, 20) == false); // Element doesn't exist
list_free(&list12);

// list_get_elem_at tests
list_t* list13 = list_alloc();
list_add_to_back(list13, 42);
list_add_to_back(list13, 10);
assert(list_get_elem_at(list13, 1) == 42); // Valid index
assert(list_get_elem_at(list13, -100) == -1); // Negative index
assert(list_get_elem_at(list13, 500) == -1); // Index greater than length
list_free(&list13);


// list_get_index_of tests
list_t* list14 = list_alloc();
list_add_to_back(list14, 4200);
list_add_to_back(list14, 1000);
assert(list_get_index_of(list14, 4200) == 1); // Element exists at index 1
assert(list_get_index_of(list14, 2000) == -1); // Element doesn't exist
list_free(&list14);


  return 0;
}
