class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n  = weights.size();
        vector<int> s(n-1,0);
        for(int i =0 ;i < n-1;i++){
            s[i] = weights[i] + weights[i+1];
        }
        sort(s.begin(),s.end());
        long max = 0;
        long min = 0;
        for(int i=0;i<k-1;i++){
            min += s[i];
            max += s[(n-1) - 1 - i];
        }
        return max-min;
    }
};
