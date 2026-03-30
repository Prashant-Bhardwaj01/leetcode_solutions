class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lm = height[0];
        int rm = height[n-1];
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<r){
            lm = max(lm, height[l]);
            rm = max(rm, height[r]);
            if(lm < rm){
                ans += lm - height[l];
                l++;
            }else{
                ans+= rm - height[r];
                r--;
            }
        }
        return ans;
    }
};
