class Solution {
    #define pii pair<int,int>
    bool countIntersections(vector<pii>& coordinates){
        int line = 0;
        int overlap = 0;
        for(int i=0;i<coordinates.size();++i){
            if(coordinates[i].second==0) overlap--;
            else overlap++;
            if(overlap == 0){
                line++;
            }
           
        }
         return line>=3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pii> y_c,x_c;
        for(auto& rectangle: rectangles){
            y_c.push_back(make_pair(rectangle[1],1));
            y_c.push_back(make_pair(rectangle[3],0));
            x_c.push_back(make_pair(rectangle[0],1));
            x_c.push_back(make_pair(rectangle[2],0));
        }
        sort(y_c.begin(),y_c.end());
        sort(x_c.begin(),x_c.end());
        return (countIntersections(y_c) or countIntersections(x_c));
    }
};
