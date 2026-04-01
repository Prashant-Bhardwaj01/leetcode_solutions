class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        unordered_map<int,tuple<int,char,int>> mp;
        for(int i=0;i<n;i++){
            mp[positions[i]] = {healths[i],directions[i],i};
        }
        stack<pair<int,int>> st;
        sort(positions.begin(), positions.end());
        vector<pair<int,int>> remain;
        int i = 0;
        while(i<n){
            auto [health, dir, idx] = mp[positions[i]];
            bool collide = false;
            if(dir == 'R'){
                st.push({health,idx});
            }
            else{
                while(!st.empty() && health > 0){
                    pair<int,int> top = st.top();
                    int st_top = top.first;
                    int st_idx = top.second;
                    if(st_top < health){
                        health--;
                        st.pop();
                        continue;
                    }else if(st_top == health){
                        st.pop();
                        collide = true;
                        break;
                    }else{
                        st.pop();
                        st_top--;
                        st.push({st_top,st_idx});
                        collide = true;
                        break;
                    }
                }
                if(!collide ){
                    remain.push_back({idx,health});
                }
            }
            i++;
        }
        while(!st.empty()){
            remain.push_back({st.top().second, st.top().first});
            st.pop();
        }
        vector<int> ans;
        sort(remain.begin(), remain.end());
        int idx = 0;
        while(idx<remain.size()){
            ans.push_back(remain[idx].second);
            idx++;
        }
        return ans;
    }
};
