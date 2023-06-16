// https://www.codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    stack<LinkedListNode<int>*>lola;
    LinkedListNode<int>*a=head,*b=head;
    while(a){
        lola.push(a);
        a=a->next;
    }

    while(b){
        if(b->data!=lola.top()->data)return false;
        lola.pop();
        b=b->next;
    }
    return true;

}
