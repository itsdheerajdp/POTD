// Fraction Addition and Subtraction

class Solution {
public:
int gcd(int a, int b)
{
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else if(a==b)
        return b;
    
    if(a>b)
        return gcd(a-b,b);
    else
        return gcd(a,b-a);
   }
    string fractionAddition(string expression) {
        if(expression[0]!='-'){
            expression = '+'+expression;
        }
        vector<int>denominator;
        vector<int>numerator;
        vector<int>sign;
        int index = 0;
        int n = expression.size();
        while(index<n){
            // getting sign of fraction
            if(expression[index]=='+'){
                sign.push_back(1);
            }
            else{
                sign.push_back(0);
            }
            index++;
            // getting numerator value
            string numer = "";
            while(index<n and expression[index]!='/')
                numer+=expression[index++];
            int num = stoi(numer);
            numerator.push_back(num);
            index++;

            // getting denominator value
            string denom = "";
            while(index<n and (expression[index]!='+' and expression[index]!='-'))
                denom+=expression[index++];
            int den = stoi(denom);
            denominator.push_back(den);
        }
        n = sign.size();
        int new_numerator=0;
        int new_denominator=1;
        for(int i=0;i<n;i++){
            new_denominator*=denominator[i];
        }
        for(int i=0;i<n;i++){
            if(sign[i]==1){
                new_numerator+=(numerator[i])*(new_denominator/denominator[i]);
            }
            else{
                new_numerator-=(numerator[i])*(new_denominator/denominator[i]);
            }
        }
        if(new_numerator==0)
            return "0/1";
        else
        {
            int signn = 1;
            if(new_numerator<0)
                signn=0;
            new_numerator=abs(new_numerator);
            int hcf = gcd(new_numerator,new_denominator);
            new_numerator/=hcf;
            new_denominator/=hcf;
            string ans = to_string(new_numerator)+"/"+to_string(new_denominator);
            return signn==0?"-"+ans:ans;
        }
    }
};