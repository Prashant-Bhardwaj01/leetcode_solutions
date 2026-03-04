class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size()-1;

        if(s[n] %2!=0) return s;
        string ans="";
        
        while(n>=0 && s[n]%2==0 ){
            n--;
        }
        if(n<0) return "";
        
        return s.substr(0,n+1);
    }
};
