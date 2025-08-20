class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> c(nums1.begin(),nums1.end());
        for(int i=0;i<nums2.size();i++){
            if(c.find(nums2[i]) != c.end()){
                ans.push_back(nums2[i]);
                c.erase(nums2[i]);
            }
        }
        return ans;
    }
};
