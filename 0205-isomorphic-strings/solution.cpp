class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int sm[256] = {0};
        int tm[256] = {0};
        for(int i=0;i<s.length();i++){
            if(sm[s[i]] != tm[t[i]]) return false;
            sm[s[i]] = i+1;
            tm[t[i]] = i+1;
        }
        return true;
    }
};
