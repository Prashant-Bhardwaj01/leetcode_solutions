class Solution {
public:
    int dp[201][20001];
    bool solve(vector<int>& n,int x,int i){
        if(x==0){
            return true;
        }
        if(i>=n.size()){
            return false;
        }
        if(dp[i][x]!=-1)return dp[i][x];
        bool take=false;
        if(x >= n[i]){
            take = solve(n,x-n[i],i+1);
        }
        bool skip = false;
        skip = solve(n,x,i+1);
        return dp[i][x] = take || skip;
    }
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);
        memset(dp,-1,sizeof(dp));
        if(sum%2!=0) return 0;
        int x=sum/2;
        return solve(nums,x,0);
       
    }
};
