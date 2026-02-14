class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int l = 0;
        int r = 0;
        
        while(l<nums1.size() && r<nums2.size()){
            if(nums1[l] < nums2[r]){
                ans.push_back(nums1[l]);
                l++;
            }else{
                ans.push_back(nums2[r]);
                r++;
            }
        }
        while(l<nums1.size()){
            ans.push_back(nums1[l]);
            l++;
        }
        while(r<nums2.size()){
            ans.push_back(nums2[r]);
            r++;
        }
        // if(ans.size() == 1) return ans[0];
        int size = ans.size();
        if(size%2==0){
            double a = (ans[(size/2)-1]+ans[size/2]);
            
            return a/2.0;
        }
        else{
            
            return ans[size/2];

        }
    }
};
