class Solution {
public:
    int romanToInt(string s) {
        int size = s.length();
      unordered_map<char,int> roman = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
      int ans = roman[s[size - 1]];
      for(int i=size-2;i>=0;i--){
        if(roman[s[i]] < roman[s[i + 1]])
            ans -= roman[s[i]];
        else
            ans += roman[s[i]];
      }
      return ans;
    }
};
