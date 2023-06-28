//https://www.codingninjas.com/studio/problems/day-25-queue-using-stack_8230722?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int>st;
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        st.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(isEmpty())return -1;
        stack<int>tmp;
        while(st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        int val=st.top();
        st.pop();
        while(tmp.size()){
            st.push(tmp.top());
            tmp.pop();
        }
        return val;
    }

    int peek() {
        // Implement the peek() function here.
        if(isEmpty())return -1;
        stack<int>tmp;
        while(st.size()>1){
            tmp.push(st.top());
            st.pop();
        }
        int val=st.top();
        while(tmp.size()){
            st.push(tmp.top());
            tmp.pop();
        }
        return val;

    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return st.size()==0;
    }
};
