class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1;
        int ans = 0;
        int c = 0;
        for(int i = n;i>=0;i--){
            if(s[i]==' ')c++;
            else break;
        }
        for(int i=n-c;i>=0;i--){
            if(s[i] == ' ') break;
            else ans++;
        }
        return ans;
    }
};
