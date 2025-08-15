class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        int col = m-1;
        while(row<n && col>=0){
            if(target == mat[row][col])return true;
            else if(target < mat[row][col]) col--;
            else row++;
        }
        return false;
    }
};
