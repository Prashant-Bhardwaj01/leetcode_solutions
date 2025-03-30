class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> r;
        vector<int> occ(26,-1);
        for(int i=0;i<n;i++){
            int index = s[i] - 'a';
            occ[index] = i;
        }
         int start = 0;
         int i=0;
         int end = 0;
         while(i<n){
            end = max(end,occ[s[i] - 'a']);
            if(i==end){
                r.push_back(end - start + 1);
                start = end+1;
            }
            i++;
         }
         return r;
    }
};
