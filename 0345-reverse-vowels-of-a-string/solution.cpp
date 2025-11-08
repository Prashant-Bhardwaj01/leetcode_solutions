class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        string str = "";
        for(int i=0;i<n;i++){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I'||s[i] == 'i' || s[i] == 'O'||s[i] == 'o'||s[i] == 'U'||s[i] == 'u') str+=s[i];
        }
        int size = str.length()-1;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == 'A' || s[i] == 'a' || s[i] == 'E' || s[i] == 'e' || s[i] == 'I'||s[i] == 'i' || s[i] == 'O'||s[i] == 'o'||s[i] == 'U'||s[i] == 'u'){
                ans+=str[size--];
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};
