class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string ans = "";
        int count = 1;
        if(n == 1) return 1;
        for(int i=1;i<n;i++){
            if(chars[i] == chars[i-1]) count++;
            else{
                if(count == 1) ans += chars[i-1];
                else{
                    ans+=chars[i-1];
                    ans+=to_string(count);
                }
                count = 1;
            }
        }
        ans+=chars[n-1];
        if(count > 1) ans+= to_string(count);
        
        for(int i=0;i<ans.size();i++) chars[i] = ans[i];
        return ans.size();
    }
};
