// Count ways to N'th Stair(Order does not matter)

class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    int ans = 1;
		    for(int i=2;i<=n;i+=2){
		            ans++; // extra 2 steps can be possible
		    }
		    return ans;
		    
		}
};