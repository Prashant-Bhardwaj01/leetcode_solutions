class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2);
        vector<int> freq(n+1,0);
        for(int i:nums){
            freq[i]++;
        }
        for(int i=0;i<=n;i++){
            if(freq[i] == 2) ans[0] = i;
            if(freq [i] == 0) ans[1] = i;
        }
        return ans;
        
        
    }
};
