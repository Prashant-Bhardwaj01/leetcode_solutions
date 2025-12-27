class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;int track = 0;
        for(int x:nums){
            track += x;
            ans = max(ans,track);
            if(track<0)track=0;
        }
        return ans;
    }
};
