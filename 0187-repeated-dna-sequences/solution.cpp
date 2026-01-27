class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.size();
        int l = 0, r = 10;;
        unordered_map<string, int> mp;
        while(r<=n){    
            string str = s.substr(l++, 10);
            r++;
            mp[str]++;
        }

        for(auto i: mp){
            if(i.second >1)
                ans.push_back(i.first);
        }
        return ans;
    }
};
