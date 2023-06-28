//https://www.codingninjas.com/studio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Queue {
    vector<int>q;
    int tail=-1,head=-1;
public:
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (head==-1 and tail==-1);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(isEmpty()){
            tail=head=0;
        }
        else{
            tail++;
        }
        q.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty())return -1;
        else if(head==tail){
            int tmp=q[head];
            q.resize(0);
            head=tail=-1;
            return tmp;
        }
        else{
            int tmp=q[head];
            head++;
            return tmp;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty())return -1;
        return q[head];
    }
};
