class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        
        for(int i=0;i<words.size();i++){
            string str = words[i];
            int flag = false;
            for(char a : str){
                if(a==x){
                    flag = true;
                    break;
                }
            }
            if(flag){
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};
