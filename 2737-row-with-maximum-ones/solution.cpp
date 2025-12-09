class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans(2);
        int big = 0;
        for(int i=0;i<mat.size();i++){
            int ones = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1) ones++;
            }
            if(big<ones){
                ans[0] = i;
                ans[1] = ones;
            }
            big = max(big,ones);
        }
        return ans;
    }
};
