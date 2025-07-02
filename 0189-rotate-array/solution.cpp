class Solution {
public:
    void rotate(vector<int>& arr, int d) {
        int n = arr.size();
        d%=n;
        vector<int> temp(n);
        
        for(int i=0;i<d;i++){
            temp[i] = arr[n-d+i];
        }
        
        for(int i=0;i<n-d;i++){
            temp[d+i] = arr[i];
        }
        
        for(int i=0;i<n;i++){
            arr[i] = temp[i];
        }
    }
    

    
};
