class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> occ;
        for( int i:nums){
            occ[i]++;
        }
        int max = 0;
        int ele =-1;
        for(auto pair:occ){
            if(pair.second > max){
                max = pair.second;
                ele = pair.first;
            }
        }
        return ele;
    }
};
