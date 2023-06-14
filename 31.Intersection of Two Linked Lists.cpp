//https://www.codingninjas.com/codestudio/problems/intersection-of-two-linked-lists_8230688?challengeSlug=striver-sde-challenge&leftPanelTab=0
#include<bits/stdc++.h>
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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(!firstHead||!secondHead)return NULL;
    // map<Node*,int>lola;
    // while(firstHead){
    //     lola[firstHead]=1;
    //     firstHead=firstHead->next;
    // }
    // while(secondHead){
    //     if(lola.find(secondHead)!=lola.end()){
    //         return secondHead;
    //     }
    //     secondHead=secondHead->next;
    // }
    // return NULL;
    Node*x=firstHead,*y=secondHead;
    while(x!=y){
        x=(x==NULL)?secondHead:x->next;
        y=(y==NULL)?firstHead:y->next;
    }
    return x;
}
