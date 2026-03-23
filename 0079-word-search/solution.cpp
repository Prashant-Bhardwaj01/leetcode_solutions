class Solution {
public:
    bool dfs(int i,int j,int idx,string& word, vector<vector<char>>& arr,int m,int n){
        if(idx == word.size()) return true;
        if( i<0 || j<0 ||i>=m || j>=n || arr[i][j] == '*') return false;
        if(arr[i][j] != word[idx]) return false;
        char str = arr[i][j];
        arr[i][j] = '*';
        bool ans = dfs(i+1,j,idx+1,word,arr,m,n) || dfs(i-1,j,idx+1,word,arr,m,n) || dfs(i,j+1,idx+1,word,arr,m,n) || dfs(i,j-1,idx+1,word,arr,m,n);
        arr[i][j] = str;
        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,0,word,board,m,n) && board[i][j] == word[0]){
                    return true;
                }
            }
        }
        return false;
    }
};
