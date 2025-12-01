class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        int count=0;
        for(char c: chars)freq[c-'a']++;
        for(int i=0;i<words.size();i++){
            vector<int> temp = freq;
            string str = words[i];
            int f=1;
            for(char c:str){
                if(temp[c-'a']==0){
                    f=0;
                    break;
                }
                
                temp[c-'a']--;
            }
            if(f) count += str.length();
        }
        return count;
    }
};
