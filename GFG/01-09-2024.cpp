// Max sum path in two arrays
class Solution {
  public:
 int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int ans = 0;
        int i = 0,j=0,sum1=0,sum2=0;
        while(i<arr1.size() and j<arr2.size()){
            if(arr1[i]<arr2[j]){
                sum1+=arr1[i++];
            }else if(arr2[j]<arr1[i]){
                sum2+=arr2[j++];
            }else{
                ans+=max(sum1,sum2)+arr1[i];
                i++;j++;sum1=0;sum2=0;
            }
        }
        while(i<arr1.size()){
            sum1+=arr1[i++];
        }
        while(j<arr2.size()){
            sum2+=arr2[j++];
        }
        ans+=max(sum1,sum2);
        return ans;
    }
};