class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdeg(n,0);

        for(int i=0;i<n;i++){
            for(auto ls:graph[i]){
                rev[ls].push_back(i);
                outdeg[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(outdeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:rev[node]){
                outdeg[nbr]--;
                if(outdeg[nbr] ==0) q.push(nbr);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
