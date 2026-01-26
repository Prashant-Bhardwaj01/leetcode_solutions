class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int diff = arr[1]-arr[0];
        int j=0;
        for(int i=0;i<n-1;i++)
            if((abs(arr[i] - arr[i+1])) < diff) 
                diff = abs(arr[i] - arr[i+1]);
                
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(abs(arr[j]-arr[i])==diff) 
                ans.push_back({arr[j],arr[i]});
            j++;
        } return ans;
    }
};
