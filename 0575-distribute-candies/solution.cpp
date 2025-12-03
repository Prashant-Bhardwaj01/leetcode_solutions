class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        unordered_map<int,int> mp;
        for(int i:candyType) mp[i]++;
        if(n/2==mp.size()) return n/2;
        else if(n/2<mp.size()) return n/2;
        else return mp.size();
    }
};
