class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        if(n == 1) return 0;
        for(char c: s){
            freq[c]++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]]==1) return i;
        }
        return -1;
    }
};
