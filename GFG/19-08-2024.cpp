// Kth Smallest


class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        int l = 0;
        int r = arr.size()-1;
        if(l==0 && r==0)return arr[0];
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(int i=l;i<=r;i++)minHeap.push(arr[i]);
        for(int i=1;i<k;i++){
            minHeap.pop();
        }
        return minHeap.top();
    }
};