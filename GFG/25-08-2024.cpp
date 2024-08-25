// Number of pairs


class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        vector<double>a,b;
        for(int i:arr){
            a.push_back(log(i)/i);
        }   
        for(int i:brr){
            b.push_back(log(i)/i);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        long long ans = 0;
        int j = 0;
        for(int i=0;i<a.size();i++){
            while(j<b.size() and b[j]<a[i])
                j++;
            ans+=j;
            
        }
        return ans;
        
    }
};