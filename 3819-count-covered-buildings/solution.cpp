class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& building) {
        unordered_map<int,pair<int,int>> xtoy;
        unordered_map<int,pair<int,int>> ytox;
        for(auto& i:building){
            int x = i[0];
            int y = i[1];
            if(!xtoy.count(x))
            xtoy[x] = {INT_MAX,INT_MIN};
            if(!ytox.count(y))
            ytox[y] = {INT_MAX,INT_MIN};
            xtoy[x].first = min(xtoy[x].first,y);
            xtoy[x].second = max(xtoy[x].second,y);
            ytox[y].first = min(ytox[y].first,x);
            ytox[y].second = max(ytox[y].second,x);
        }
        int ans = 0;
        for(auto& i:building){
            int x = i[0];
            int y = i[1];
            if(y<xtoy[x].second && xtoy[x].first<y && x<ytox[y].second && x>ytox[y].first)ans++;
        }
        return ans;
    }
};
