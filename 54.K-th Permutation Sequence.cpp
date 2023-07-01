//https://www.codingninjas.com/studio/problems/k-th-permutation-sequence_8230822?challengeSlug=striver-sde-challenge&leftPanelTab=0

string kthPermutation(int n, int k) {
    // Write your code here.

    vector<int> nums;
    int fact = 1;
    
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i; // Calculate factorial of n
    }
    
    string result;
    k--; // Decrement k to fit 0-based indexing
    
    while (!nums.empty()) {
        fact /= nums.size(); // Divide factorial by remaining numbers
        
        int index = k / fact; // Calculate the index of the number to be added
        result += to_string(nums[index]); // Add the number to the result
        nums.erase(nums.begin() + index); // Remove the used number from the list
        
        k %= fact; // Update k for the next iteration
    }
    
    return result;
}
