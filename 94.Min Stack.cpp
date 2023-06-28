//https://www.codingninjas.com/studio/problems/min-stack_8230861?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>>lola;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			if(lola.empty()){
				lola.push({num,num});
			}
			else{
				lola.push({num,min(lola.top().second,num)});
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(lola.empty())return -1;
			int val=lola.top().first;
			lola.pop();
			return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(lola.empty())return -1;
			int val=lola.top().first;
			// lola.pop();
			return val;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(lola.empty())return -1;
			int val=lola.top().second;
			return val;
		}
};
