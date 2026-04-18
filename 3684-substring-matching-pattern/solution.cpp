class Solution {
public:
    bool hasMatch(string s, string p) {
        int n = s.size();
        if(p.size() == 1 && p[0] =='*') return true;
        string str1 = "";
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(p[i] == '*')break;
            str1 += p[i];
            c++;
        }
        int n1 = c+1;
        c+=1;
        string str2 = "";
        for(int i=c;i<p.size();i++){
            str2 += p[i];
        }
        bool fh = false;
        for(int i = 0; i <= n - str1.size(); i++){
        int ok = true;
        for(int j = 0; j < str1.size(); j++){
            if(s[i + j] != str1[j]) {
                ok = false;
                break;
            }
        }

        if(ok){
            fh = true;
            bool lh = false;
            for(int k = i + str1.size(); k <= n - str2.size(); k++){
                int ok2 = true;
                for(int j = 0; j < str2.size(); j++){
                    if(s[k + j] != str2[j]){
                        ok2 = false;
                        break;
                    }
                }
                if(ok2){
                    lh = true;
                    break;
                }
            }
             if(fh && lh) return true;
        }
    }
    return false;
        
        
    }
};
