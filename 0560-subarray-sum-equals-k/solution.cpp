class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum == k) ans++;
            if(prefix.find(sum - k) != prefix.end()) ans += prefix[sum - k];
            prefix[sum]++;
        }
        return ans;
    }
};
