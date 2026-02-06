class TriesNode{
    public:
    char val;
    vector<TriesNode*> children;
    bool isWord;
    TriesNode(){
        children.resize(26,nullptr);
        isWord = false;
    }
    TriesNode(char v){
        val = v;
        children.resize(26,nullptr);
        isWord = false;
    }

};
class Trie {
public:
    TriesNode* root ;
    Trie() {
        root = new TriesNode();
    }
    void insert(string word) {
        TriesNode* helper = root;
        for(char ch : word){
            if(helper->children[ch-'a']==nullptr){
                TriesNode* node = new TriesNode(ch);
                helper->children[ch-'a'] = node;
            }
            helper = helper->children[ch-'a'];
        }
        helper->isWord = true;
    }
    bool search(string word) {
        TriesNode* helper = root;
        for(char ch : word){
            while(helper->children[ch-'a'] == nullptr) return false;
            helper = helper->children[ch-'a'];
        }
        return helper->isWord;
    }
    bool startsWith(string prefix) {
        TriesNode* helper = root;
        for(char ch : prefix){
            while(helper->children[ch-'a'] == nullptr) return false;
            helper = helper->children[ch-'a'];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
