// Missing in Array

class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Your code goes here
        int sum = (n*(n+1))/2;
        int curr = accumulate(arr.begin(),arr.end(),0);
        return sum-curr;
    }
};