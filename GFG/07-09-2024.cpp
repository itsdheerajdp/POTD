// Nth Natural Number

class Solution {
  public:
    long long findNth(long long n) {
        // here i need to simply convert the given decimal integer into base 9 integer because base 9 integer will never have 9 as digit because max posible digit should be 8 in base 9 (0 to 8)
        long long  base9Num = 0;
        int pow10 = 0;
        while(n){
            long long rem = n%9;
            base9Num+=rem*pow(10,pow10++);
            n/=9;
            
        }
        return base9Num;
    }
};