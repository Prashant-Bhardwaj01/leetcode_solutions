class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int cdt = nums[0],c = 0,tc = 0,n = nums.size();
        for(int i:nums){
            if(i == cdt) c++;
            else c--;
            if(c==0){
                cdt = i;
                c=1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==cdt) tc++;
        }
        int pc = 0;
        for(int i=0;i<n-1;i++){
            if(nums[i] == cdt) pc++;
            if(pc*2 > i+1 && (tc - pc)*2 > n-i-1) return i;
        }
        return -1;
    }
};
