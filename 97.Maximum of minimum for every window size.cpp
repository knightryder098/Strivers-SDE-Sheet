//https://www.codingninjas.com/studio/problems/maximum-of-minimum-for-every-window-size_8230783?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 

vector<int> previousSmaller(vector<int> &arr, int n) {
    vector<int> prev(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            prev[i] = -1;
        } 
        else {
            prev[i] = s.top();
        }
        s.push(i);
    }
    return prev;
}

vector<int> nextSmaller(vector<int> &arr, int n) {
    stack<int> s;
    vector<int> next(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            s.pop();
        }   
        if (s.empty()) {
            next[i] = n;
        } 
        else {
            next[i] = s.top();
        }
        s.push(i);
    }
    return next;
}



vector<int> maxMinWindow(vector<int> arr, int n) {
    vector<int> answer(n, INT_MIN);
    vector<int> next = nextSmaller(arr, n);
    vector<int> prev = previousSmaller(arr, n);
     for (int i = 0; i < n; i++) {
        // Length of the window in which a[i] is minimum
        int length = next[i] - prev[i] - 1;

        // Update the answer
        answer[length - 1] = max(answer[length - 1], arr[i]);
    }

	// Some places in answer[] may not be filled yet.
	// so fill them by taking maximum 
    for (int i = n - 2; i >= 0; i--) 
    {
        answer[i] = max(answer[i], answer[i + 1]);
    }
    return answer;
}
