// Find Missing Observations
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sumofM = accumulate(rolls.begin(),rolls.end(),0);
        int sumofN = (n+m)*mean - sumofM;
        vector<int>ans;
        if(sumofN>6*n or sumofN<n){
            return ans;
        }
        else if(sumofN==6*n){
            while(n--)
                ans.push_back(6);
            return ans;
        }else if(sumofN%n==0){
            int val = sumofN/n;
            while(n--)
                ans.push_back(val);
            return ans;
        }else{
           while(n){
                int val = sumofN - (n-1);
                if(val>6){
                    ans.push_back(6);
                    sumofN-=6;
                    n-=1;
                }else{
                    ans.push_back(val);
                    n-=1;
                    while(n--)
                        ans.push_back(1);
                    break;

                }
               
           }
        }
        return ans;
    }
};