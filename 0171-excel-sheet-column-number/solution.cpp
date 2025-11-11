class Solution {
public:
    int titleToNumber(string col) {
        int ans = 0;
        for(char c : col){
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
