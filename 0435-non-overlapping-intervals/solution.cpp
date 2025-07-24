class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int count =0;
        int last = arr[0][1];
        for(int i=1; i<arr.size(); i++){

            if(arr[i][0] < last){
                count++;
                last = min(arr[i][1],last);
            }
            else{
                last = arr[i][1];
            }
        }
        return count;
    }
};
