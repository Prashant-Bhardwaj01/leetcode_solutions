class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m*m;
        vector<int> c(n+1,0);
        for(vector<int> i:grid){
            for(int j:i){
                c[j]++;
            }
        }
        int a=0;
        int b=0;
        for(int i=1;i<=n;i++){
            if(c[i] == 2) a = i;
            if(c[i] == 0) b = i;
        }
        return {a,b};
        
    }
};
