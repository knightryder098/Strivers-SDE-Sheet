
// https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge&leftPanelTab=0

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node *a, Node*b){
	Node *tmp=new Node(0);
	Node *ans=tmp;
	while(a!=NULL and b!=NULL){
		if(a->data<b->data){
			tmp->child=a;
			tmp=tmp->child;
			a=a->child;
		}
		else{
			tmp->child=b;
			tmp=tmp->child;
			b=b->child;
		}
	if(a!=NULL)tmp->child=a;
	if(b!=NULL)tmp->child=b;
	}
	return ans->child;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL || head->next==NULL)return head;
	Node *root=head->next;
	head->next=NULL;
	root=flattenLinkedList(root);
	head=merge(head,root);
	return head;
}
