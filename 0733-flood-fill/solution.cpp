class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        int val = image[sr][sc];
        if(color == val) return image;
        q.push({sr,sc});
        image[sr][sc] = color;
        while(!q.empty()){
            pair<int,int> front = q.front();
            int row = front.first;
            int col = front.second;
            q.pop();
            if(row-1 >= 0 && image[row-1][col] == val){
                image[row-1][col] = color;
                q.push({row-1,col});
            }
            if(row+1 < n && image[row+1][col] == val){
                image[row+1][col] = color;
                q.push({row+1,col});
            }
            if(col-1 >= 0 && image[row][col-1] == val){
                image[row][col-1] = color;
                q.push({row,col-1});
            }
            if(col+1 < m && image[row][col+1] == val){
                image[row][col+1] = color;
                q.push({row,col+1});
            }
        }
        return image;
    }
};
