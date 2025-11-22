class Solution {
public:
    int minimumFlips(int n) {
        string s ="";
        while(n>0){
            s.push_back((n%2) + '0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        string r = s;
        reverse(r.begin(),r.end());
        int f=0;
        int si = s.length();
        for(int i=0;i<si;i++){
            if(s[i] != r[i] ) f++;
        }
        return f;
    }
};
