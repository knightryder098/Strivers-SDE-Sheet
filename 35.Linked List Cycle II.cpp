//https://www.codingninjas.com/codestudio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

Node *firstNode(Node *head)
{
    //    Write your code here.
    map<Node*,bool>lola;
    while(head){
        if(lola[head])return head;
        lola[head]=true;
        head=head->next;
    }
    return nullptr;
}
