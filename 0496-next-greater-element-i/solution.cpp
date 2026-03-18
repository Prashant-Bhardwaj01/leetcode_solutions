class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n1 = nums1.size();
        vector<int> ans(n1,-1);
        
        int n2 = nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n1;i++){
            mp[nums1[i]] = i;
        }
        for(int i=n2-1;i>=0;i--){
            if(mp.find(nums2[i]) != mp.end()){
                while(!st.empty() && st.top() <= nums2[i]) st.pop();
                if(st.empty()){
                    int idx = mp[nums2[i]];
                    ans[idx] = -1;
                }else{
                    int idx = mp[nums2[i]];
                    ans[idx] = st.top(); 
                }
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};
