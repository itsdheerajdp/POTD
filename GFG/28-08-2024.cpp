// Sorting Elements of an Array by Frequency


class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first; // Sort by first value in descending order
        }
        return a.second < b.second;   // Sort by second value in ascending order if first values are the same
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>freq;
        for(auto i:arr)
            freq[i]++;
        vector<pair<int,int>>tmp;
        for(auto i:freq){
            tmp.push_back({i.second,i.first});
        }
        sort(tmp.begin(),tmp.end(),customComparator);
        vector<int>ans;
        for(auto t:tmp){
            int count = t.first;
            int val = t.second;
            while(count--)
                ans.push_back(val);
        }
        return ans;
    }
};
