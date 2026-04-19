class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mx = INT_MIN;
        int i=0;int j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                mx=max(mx,j-i);
                j++;
            }else{
                i++;
            }
        }
        
        return mx<0?0:mx;
    }
};
