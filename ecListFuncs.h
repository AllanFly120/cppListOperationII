// ecListFuncs.h
// CSCI 455 Fall 2015, Extra Credit assignment
// You do not need to modify or submit this file.

#ifndef EC_LIST_FUNCS_H
#define EC_LIST_FUNCS_H

#include <iostream>
#include <cctype>
#include <string>

using namespace std;


//*************************************************************************
// Node type used for lists
struct Node {
  int data;
  Node *next;

  Node(int item);
  Node(int item, Node *n);

};


typedef Node * ListType;

//*************************************************************************
// Utility functions used by the test driver code
//    (these are defined in ectest.cpp)

// inserts val at the front of list
// PRE: list is a well-formed list
void insertFront(Node *&list, int val);

// makes list into an empty list
//   reclaiming memory used by nodes 
// PRE: list is a well-formed list
// POST: list' is NULL
void clearList(Node * &list);

// prints list elements, space separated, ending with '\n'
// prints empty list as "<empty>"
// PRE: list is a well-formed list
void printList(Node *list);



//*************************************************************************
// Functions you need to write for this assignment:
//   (implementations go in ecListFuncs.cpp)



/*
 * numRuns
 *
 * PRE: list is a well-formed list.
 *
 * returns the number of runs in the list.
 *   A run is an ajacecent sequence two or more of the same values all in a row.
 *
 * Examples:
 *  list                   numRuns(list)
 *
 *    ()                    0
 *    (2 7 3)               0
 *    (2 2 7 3)             1
 *    (2 2 7 2 2 2 2)       2
 *    (2 2 3 3 3 4 4 4 4)   3
 *  
 */
int numRuns(ListType list);



/*
 * reverseCopy
 *
 * PRE: list is a well-formed list.
 *
 * returns a copy of the list, but with the elements in reverse order.
 * The original list is unchanged.
 *
 * Examples:
 *
 *  list              reverseCopy(list)
 *    ()                ()
 *    (7)               (7)
 *    (4 2 5 1)         (1 5 2 4)
 *    (1 2 2 3)         (3 2 2 1)
 *
 */
ListType reverseCopy(ListType list);



/* 
 * removeMiddleElmt
 *
 * PRE: list is a well-formed list
 * 
 * removes the middle element from the list.
 * If the list has an even number of elements, returns the one just left of the middle.
 * If the list is empty, does nothing.
 *
 * Examples:
 *
 *  list before         list
 *  before call:        after call to removeMiddleElmt:
 *    ()                ()
 *    (7)               ()
 *    (6 5 2 3)         (6 2 3)
 *    (5 2)             (2)
 *    (1 2 3 4 5)       (1 2 4 5)
 */
void removeMiddleElmt(ListType & list);



/*
 * swapLast2
 *
 * PRE: list is a well formed list
 *
 * swaps the last two nodes in the list.
 *  If there are less than two nodes in the list, list remains unchanged.
 *
 * NOTE: this function does not create or destroy any nodes.
 * It also may not change any data values in nodes:
 * it just relinks the list in a different way.
 *
 * Examples:
 *
 *    list                 list
 *   before call           after call to swapLast2
 *   (1 2 3 23 87)         (1 2 3 87 23)
 *   (1 2)                 (2 1)
 *   (7 4 6)               (7 6 4)
 *   (3)                   (3)
 *   ()                    ()
 */
void swapLast2(ListType &list);

//*************************************************************************

#endif
