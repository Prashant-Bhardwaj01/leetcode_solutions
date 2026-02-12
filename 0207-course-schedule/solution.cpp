class Solution { 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses,0);
        vector<vector<int>> child(numCourses);
        for(auto i:prerequisites){
            child[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0) q.push(i);
        }
        int c = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            c++;
            for(int i:child[front]) {
                indeg[i]--;
                if(indeg[i] == 0)q.push(i);
            }

        }
        return c!=numCourses? false:true;
    }
};
