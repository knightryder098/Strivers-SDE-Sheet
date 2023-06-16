//https://www.codingninjas.com/codestudio/problems/rotate-linked-list_8230752?challengeSlug=striver-sde-challenge&leftPanelTab=0


/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head)return head;
     int len=1;
     Node *curr=head,*newHead=head;
     while(curr->next){
          len++;
          curr=curr->next;
     }
     curr->next=head;
     if(k%=len){
          for(int i=0;i<len-k;i++)curr=curr->next;
     }
     newHead=curr->next;
     curr->next=NULL;
     return newHead;
}
