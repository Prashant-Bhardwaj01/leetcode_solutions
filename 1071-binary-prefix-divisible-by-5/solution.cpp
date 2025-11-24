class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int r = 0;
        for(int i : nums){
            r = (r*2 + i)%5;
            if(r == 0)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};
