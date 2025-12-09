class Solution {
public:
    int x = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        unordered_map<long long,long long> left;
        unordered_map<long long,long long> right;
        for(int i:nums) right[i]++;
        for(int i:nums){
            right[i]--;
            int l = left[2*i];
            int r = right[2*i];
            ans = (ans+((long long )l*r)) % x;
            left[i]++;
        }
        
        return ans;
    }
};
