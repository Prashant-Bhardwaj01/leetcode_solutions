class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans = 0;
        unordered_map<string,int> mp1;
        unordered_map<string,int> mp2;
        for(string s:words1) mp1[s]++;
        for(string s:words2) mp2[s]++;
        for(auto &i: mp1){
            if(i.second == 1 && mp2[i.first]==1){
                ans++;
            }
        }
        return ans;
    }
};
