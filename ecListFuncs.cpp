/*  Name:Yangping Zheng
 *  loginid:yangpinz
 *  CS 455 Fall 2015
 *
 *  See ecListFuncs.h for specification of each function.
 */

#include <iostream>

#include <cassert>

#include "ecListFuncs.h"

using namespace std;


int numRuns(ListType list) {
  if(list == NULL) return 0;
  int runCounter = 0;  //count the number of runs
  int prevValue = list->data;  //save the previous node's data
  bool running = false;        //a flag indicating whether currently in a run. If so the runCounter won't add 1 if we find the same adjacent nodes
  Node *p = list->next;
  while (p != NULL) {
    if (p -> data == prevValue) {
      if(!running) runCounter++;
      running = true;
    }
    else{
      running = false;
    }
    prevValue = p->data;
    p = p->next;
  }
  
  return runCounter;
  
}



ListType reverseCopy(ListType list) {
  ListType rtn = NULL;
  if (list == NULL) return rtn;
  Node *p = list;
  while (p != NULL) {
    rtn = new Node(p->data, rtn);//insert a new node into return list with the value of end nodes of original list
    p = p->next;
  }
  
  return rtn;
  
}



void removeMiddleElmt(ListType &list) {
  Node *p = list;
  int len = 0;
  while (p != NULL) {
    len ++;
    p = p->next;
  }
  p = list;
  if(len == 0) return;
  int midPos = (len-1)/2; //get the index of the node in the linkedlist to be deleted
  int i = 0;
//  len = 0;//reset the len
  if (len < 3) {
    Node* tmp = p;
    list = p->next;
    delete tmp;
  }
  else {
    while (p!=NULL) {
      if (i == midPos-1) {
        Node *tmp = p->next;
        p->next = p->next->next;
        delete tmp;
        break;
      }
      i++;
      p = p->next;
    }
    
  }
}




void swapLast2(ListType &list) {
  if(list==NULL||list->next==NULL)return;  //list with 0 or 1 nodes, do nothing
  if (list->next->next==NULL) {             //list with 2 nodes, swap them.
    Node* tmp = list;
    list = list->next;
    list->next = tmp;
    list->next->next = NULL;
    return;
  }
  Node *p = list;
  while (p->next->next->next!=NULL) {   //list with 3 or more nodes, we need to save 3 nodes to complete the swapping.
    p = p->next;
  }
  Node *former = p->next;
  Node *later = p->next->next;
  p->next = later;
  p->next->next = former;
  p->next->next->next=NULL;
  
}
