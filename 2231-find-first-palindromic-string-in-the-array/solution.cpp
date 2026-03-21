class Solution {
public:
    bool isvalid(string s){
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto i : words){
            if(isvalid(i)){
                return i;
            }
        }
        return "";
    }
};
