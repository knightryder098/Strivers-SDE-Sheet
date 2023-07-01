//https://www.codingninjas.com/studio/problems/the-celebrity-problem_8230781?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.

	  stack<int> s;
    
    // Push all the people onto the stack
    for (int i = 0; i < n; i++) {
        s.push(i);
    }
    
    while (s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if (knows(a, b)) {
            // If a knows b, then a cannot be the celebrity
            s.push(b);
        } else {
            // If a doesn't know b, then b cannot be the celebrity
            s.push(a);
        }
    }
    
    int potential_celebrity = s.top();
    s.pop();
    
    // Check if the potential celebrity knows anyone or if someone
    // doesn't know the potential celebrity
    for (int i = 0; i < n; i++) {
        if (i != potential_celebrity && (knows(potential_celebrity, i) || !knows(i, potential_celebrity))) {
            return -1; // No celebrity found
        }
    }
    
    return potential_celebrity;
}
