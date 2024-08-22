// Number Complement

class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int pow2  = 0;
        while(num){
            int bit = num&1;
            if(bit==0){
                ans+=pow(2,pow2);
            }
            pow2++;
            num>>=1;
        }
        return ans;
    }
};