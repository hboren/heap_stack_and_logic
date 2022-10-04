#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	//when recursed to end of list, (aka head is null), set smaller
	//and larger to null in case they had any garbage data. return
	if(head == NULL){
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	//do head recursion
	llpivot(head->next, smaller, larger, pivot);
	//create temp so we can set head to null
	Node* temp = head;
	head = nullptr;
	//if current node is less than or equal to pivot
	if(temp->val <= pivot){
		//if smaller is empty, set smaller to current node and return up
		if(smaller == nullptr){
			smaller = temp;
			return;
		}
		//if not empty, place node at front of smaller list
		//aka create temp node, set that next to the current smaller head
		//then set smaller to the current node, return
		else{
			Node* temp1 = temp;
			temp1->next = smaller;
			smaller = temp1;
			return;
		}
	}
	//if current node value is greater than pivot
	else if(temp->val > pivot){
		//if larger is empty, set larger to current node, return
		if(larger == nullptr){
			larger = temp;
			return;
		}
		//if not empty place current node at the front of larger list
		//aka create temp node, set that next to the current smaller head
		//then set smaller to the current node, return
		else{
			Node* temp1 = temp;
			temp1->next = larger;
			larger = temp1;
			return;
		}
	}
}

