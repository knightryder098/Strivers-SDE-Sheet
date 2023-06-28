//https://www.codingninjas.com/studio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge&leftPanelTab=2

#include <bits/stdc++.h> 

void insertAtCorrectPosition(stack<int> &st, int temp) {
    // Base case: if the stack is empty or the top element is smaller than the temp
    if (st.empty() || st.top() < temp) {
        st.push(temp);
        return;
    }

    // Remove the top element
    int val = st.top();
    st.pop();

    // Recursively call insertAtCorrectPosition
    insertAtCorrectPosition(st, temp);

    // Push the removed element back to the stack
    st.push(val);
}

void sortStack(stack<int> &st) {
    // Base case: if the stack is empty
    if (st.empty()) {
        return;
    }

    // Remove the top element
    int temp = st.top();
    st.pop();

    // Recursively call sortStack
    sortStack(st);

    // Insert the removed element at the correct position
    insertAtCorrectPosition(st, temp);
}
