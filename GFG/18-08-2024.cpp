// Split an array into two equal Sum subarrays
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0)
            return false;
        sum/=2;
        int curr = 0;
        for(int i=0;i<arr.size();i++){
            curr+=arr[i];
            if(curr==sum)
                return true;
        }
        return false;
    }
};