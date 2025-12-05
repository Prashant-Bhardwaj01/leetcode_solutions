class Solution {
public:
    vector<string> cellsInRange(string s) {
        char start_s = s[0];
        char end_s = s[s.length()-2];
        vector<string> ans;
        int st_int = s[1]-'0',end_int = s[s.length()-1]-'0';
        for(int i=start_s;i<=end_s;i++){
            string ss = "";            
            for(int j=st_int;j<=end_int;j++){
                ss += i;
                ss+=j+'0';
                ans.push_back(ss);
                ss = "";
            }
        }
        return ans;
    }
};
