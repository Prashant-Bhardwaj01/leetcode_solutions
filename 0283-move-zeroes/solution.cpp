class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int counter = 0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[counter++] = arr[i];
            }
        }
        while(counter<n){
            arr[counter++] = 0;
        }
    }
};
