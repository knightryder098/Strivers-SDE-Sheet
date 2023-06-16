//https://www.codingninjas.com/codestudio/problems/copy-list-with-random-pointer_8230734?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

map<LinkedListNode<int>*,LinkedListNode<int>*>lola;
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL)return nullptr;
    if(lola[head])return lola[head];
    LinkedListNode<int> *newHead=new LinkedListNode<int>(head->data);
    lola[head]=newHead;
    newHead->next=cloneRandomList(head->next);
    newHead->random=cloneRandomList(head->random);
    return newHead;
}
