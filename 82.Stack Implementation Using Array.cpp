//https://www.codingninjas.com/studio/problems/stack-implementation-using-array_8230854?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int topi=-1;
    vector<int>arr;
    int max;
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr.resize(capacity);
        max=capacity;
    }

    void push(int num) {
        // Write your code here.
        if(isFull())return;
        topi++;
        arr[topi]=num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty())return -1;
        int val=arr[topi];
        topi--;
        return val;
    }
    
    int top() {
        // Write your code here.
        if(isEmpty())return -1;
        return arr[topi];
    }
    
    int isEmpty() {
        // Write your code here.
        return (topi==-1);
    }
    
    int isFull() {
        // Write your code here.
        return (topi==max-1);
    }
    
};
