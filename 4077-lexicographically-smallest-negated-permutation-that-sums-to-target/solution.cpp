class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long s = 1LL *n*(n+1) / 2;
        long long d = s -target;
        if(d < 0 || d % 2 != 0) return {};
        long long f = d/2;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i] = i+1;
        }
        for(int i=n;i>=1 && f > 0;i--){
            if(i<=f){
                ans[i-1] *= -1;
                f = f-i;
            }
        }
        if(f!=0) return {};
        sort(ans.begin(),ans.end());
        return ans;
    }
};
