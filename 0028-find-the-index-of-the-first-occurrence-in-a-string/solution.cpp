class Solution {
public:
    int strStr(string haystack, string needle) {
        int h_size = haystack.length();
        int n_size = needle.length();
        int index = -1;
        
        for(int i=0;i<=h_size - n_size;i++){
            if(haystack.substr(i,n_size)== needle){
                index = i;
                break;
            }
        }
        return index;
    }
};
