class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int l=0;
        int m = 0;
        for(int i=0;i<fruits.size();i++){
            freq[fruits[i]]++;
            while(freq.size()>2){
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0){
                    freq.erase(fruits[l]);
                }
                l++;
            }
            m = max(m,i-l+1);
        }
        return m;
    }
};
