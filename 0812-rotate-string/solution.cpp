class Solution {
public:
    vector<int> Lcp(string &s){
        int n = s.length();
        vector<int> lcp(n);
        lcp[0] = 0;
        int len = 0;
        int i = 1;
        while(i<n){
            if(s[i] == s[len]){
                lcp[i++] = ++len;
            }
            else{
                if(len != 0){
                    len = lcp[len - 1];
                }else{
                    lcp[i++] = 0;
                }
            }
        }
        return lcp;
    }
    bool rotateString(string s, string goal) {
        string str = s+s;
        int n = str.length();
        int m = goal.length();
        if(s.length() != m) return false;
        vector<int> lcp = Lcp(goal);
        int i = 0, j = 0;
        while(i<n){
            if(str[i] == goal[j]){
                i++;
                j++;
            }
            if(j == m){
                return true;
            }
            else if(i<n && str[i] != goal[j]){
                if(j != 0) j = lcp[j - 1];
                else i++;
            }
        }
        return false;
    }
};
