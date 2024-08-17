// Product array puzzle
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        int n = nums.size();
        vector<long long int>left(n,1);
        vector<long long int>right(n,1); 
        long long int mul = 1;
        for(int i=0;i<n;i++){
            left[i] = mul;
            mul*=nums[i];
        }
        mul = 1;
        for(int i=n-1;i>=0;i--){
            right[i] = mul;
            mul*=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = left[i]*right[i];
        }
        return nums;
    }
};