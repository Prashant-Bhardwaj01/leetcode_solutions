class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, h = n - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (matrix[mid][0] <= target && matrix[mid][m - 1] >= target) {
                int start = 0, end = m - 1;

                while (start <= end) {
                    int midCol = start + (end - start) / 2;
                    if (matrix[mid][midCol] == target) return true;
                    else if (matrix[mid][midCol] > target) end = midCol - 1;
                    else start = midCol + 1;
                }
                return false;
            }
            else if (matrix[mid][m - 1] > target) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};

