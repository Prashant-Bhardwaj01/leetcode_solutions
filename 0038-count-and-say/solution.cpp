class Solution {
public:
    void dfs(int n,string & base){
        for(int j=2;j<=n;j++){
            string ans = "";
            int count = 1;
            for(int i=1;i<=base.size();i++){
                if(base[i] == base[i-1]){
                    count++;
                }
                else{
                    ans += to_string(count)+base[i-1];
                    count = 1;
                }
            }
            base = ans;
        }
    }
    string countAndSay(int n) {
       
        string base = "1";
        dfs(n,base);
        return base;
    }
};
