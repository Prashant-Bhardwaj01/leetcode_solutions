class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans="";
        string helper="";
        int l=0;
        int r=n-1;
        for(int i=0;i<n;i++){
            if(s[i] == ' ') l++;
            else break;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i] == ' ') r--;
            else break;
        }
        for(int i=r;i>=l;i--){
            
            if(s[i]!=' ')
                helper+=s[i];
            else if(!helper.empty()){
                reverse(helper.begin(),helper.end());
                ans+=helper+" ";
                helper="";
            }
        }
        reverse(helper.begin(),helper.end());
        ans+=helper;
        return ans;
    }
};
