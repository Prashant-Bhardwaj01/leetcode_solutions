class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n/rows;
        if(n==0 || rows==0) return "";
        string ans = "";
        int i = 0;
        int iteration = 1;
        vector<vector<char>> mat(rows, vector<char>(cols));
        int idx=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[i][j] = encodedText[idx++];
            }
        }
        for(int i=0;i<cols;i++){
            int r=0;
            int c = i;
            while(r<rows && c<cols){
                ans += mat[r][c];
                r++;
                c++;
            }
        }
        int as = ans.size()-1;

        while(ans[as--] == ' ')ans.pop_back();
        return ans;
    }
};
