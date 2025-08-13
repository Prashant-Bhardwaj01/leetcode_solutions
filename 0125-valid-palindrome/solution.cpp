class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int j = s.length()-1;
        int i = 0;
        
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
};
