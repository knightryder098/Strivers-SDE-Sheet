
//https://www.codingninjas.com/codestudio/problems/reverse-nodes-in-k-group_8230709?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* reversal(Node* head, int n, int b[], int i){
    while(b[i]==0 && i<n){
        i++;
    }
    if(!head || !head->next || i == n)
        return head;

    int counter = b[i];
    Node* prev=NULL, *curr=head, *ahead;
    while(curr!=NULL && counter--){
        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }
    head->next = reversal(curr, n, b, i+1);
    return prev;
}

 

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(!head)
        return NULL;
    return reversal(head, n, b, 0);

}
