class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for(int i:nums){
            if(i%k==0) s.insert(i);
        }
        for(int i=1;;i++){
            int m = i*k;
            if(!s.count(m)) return m;
        }
        return 0;
    }
};
