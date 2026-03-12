class Solution {
public:
    bool isValid(int l, int r, string& s){
        while(l<=r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ans = 0;
        string str = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isValid(i,j,s) && (j-i+1 > ans)){
                    ans = j-i+1;
                    str = s.substr(i , j-i+1);
                }
            }
        }
        return str;
    }
};
