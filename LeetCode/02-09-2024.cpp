// Find the Student that Will Replace the Chalks
class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int n = chalk.size();
        long long chalkNeeded = 0;
        for(int j:chalk)
            chalkNeeded+=j;
        long long K = k % chalkNeeded;
        while(chalk[i]<=K){
            K-=chalk[i];
            i=i+1;
        }
        return i;
    }
};