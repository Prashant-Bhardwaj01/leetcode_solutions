class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set1(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set1.erase(beginWord);
        while(!q.empty()){
            auto front = q.front();
            string word = front.first;
            int lvl = front.second;
            q.pop();
            if(word == endWord) return lvl;
            for(int i=0;i<word.size();i++){
                string org = word;
                for(char ch = 'a'; ch<='z';ch++){
                    word[i] = ch;
                    if(set1.find(word) != set1.end()){
                        set1.erase(word);
                        q.push({word,lvl+1});
                    } 
                }
                word = org;
            }
        }
        return 0;
    }
};
