// Sum of Digits of String After Convert
class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(auto i:s){
            int val = i-'a'+1;
            if(val>9){
                sum+=(val%10);
                val/=10;
                sum+=val;
            }else{
                sum+=val;
            }
        }
        k-=1;
        while(k--){
            int tmp = 0;
            int n = sum;
            while(n){
                tmp+=(n%10);
                n/=10;
            }
            sum = tmp;
        }
        return sum;
    }
};