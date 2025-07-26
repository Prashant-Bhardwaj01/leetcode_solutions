class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }
        int count = freq.begin()->second;
        
        for(auto it : freq) {
            if(it.second != count)
                return false;
        }
        
        return true;
    }
    
};
