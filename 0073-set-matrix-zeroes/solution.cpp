class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int r=0;r<m;r++){
                        if(matrix[i][r] != 0) matrix[i][r]='a';
                    }
                    for(int c=0;c<n;c++){
                        if(matrix[c][j] != 0) matrix[c][j]='a';
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 'a') matrix[i][j]=0;
            }
        }

    }
};
