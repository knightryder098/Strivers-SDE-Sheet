//https://www.codingninjas.com/studio/problems/stack-using-queue_8230715?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return getSize()==0;
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty())return -1;
        queue<int>tmp;
        while(getSize()>1){
            tmp.push(q.front());
            q.pop();
        }
        int res=q.front();
        q.pop();
        q=tmp;
        return res;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty())return -1;
        return q.back();
    }
};
