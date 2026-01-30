class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int l =0 ;
        int h = n-1;
        while(l<h){
            int sum = arr[l] + arr[h];
            if(sum == target) return {l+1,h+1};
            if(sum > target) h--;
            else l++;
        }
        return {-1,-1};
    }
};
