class Solution {
public:
    int myAtoi(string s) {
       int minus = 0;
       int ans = 0;
       int i = 0;
       while(s[i]==' '){
        i++;
       } 
       if(s[i]=='-' || s[i]=='+'){
        if(s[i++]=='-')
        minus = 1;
       }
       while(s[i] >= '0' && s[i] <= '9'){
        if(ans > INT_MAX/10 || (ans == INT_MAX/10 && s[i]-'0'> 7))
        return minus == 1? INT_MIN : INT_MAX;
        ans = ans*10 + (s[i++]-'0');
       }
       return minus == 1? -ans:ans;
    }
};
