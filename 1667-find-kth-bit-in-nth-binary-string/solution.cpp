class Solution {
public:
    string inv(string s){
        for(int i =0; i<s.size();i++){
            if(s[i] == '0')s[i] = '1';
            else s[i] = '0';
        }
        string str = s;
        return str;

    }
    string rev(string s){
        int l = 0;
        int r = s.length()-1;
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
        string rever = s;
        return rever;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        
        for(int i=1;i<n;i++){
            s = s+"1"+rev(inv(s));
        }
        
        return s[k-1];
    }
};
