class Solution {
public:
    bool check(vector<vector<int>>& mat, int target, int row){
        int n = mat[0].size();
        int st = 0;
        int end = n-1;
        while(st<=end){
            int mid = st + (end -st)/2;
            if(mat[row][mid] == target) return true;
            else if(target > mat[row][mid]) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int st = 0;
        int end = n-1;
        while(st<=end){
            int mid = st + (end -st) /2;
            if(target >= mat[mid][0] && target <= mat[mid][m-1]) return check(mat,target,mid);
            else if(target >= mat[mid][m-1]) st = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};
