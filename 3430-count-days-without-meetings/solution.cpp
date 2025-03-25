class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int count = 0;
        sort(meetings.begin(),meetings.end());
        int last = 0;
        for(int i=0;i<n;i++){
            int s = meetings[i][0], e = meetings[i][1];
            if(s > last){
                count += s-last-1;
            }
            last = max(last,e);
        }
        if(days > last){
            count+= (days - last);
        }
        return count;
    }
};
