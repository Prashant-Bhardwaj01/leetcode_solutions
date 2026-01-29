class Solution {
public:
    bool canShip(vector<int>& weights, int days,int mid){
        int sum = 0;
        int count = 1;
        for(int i:weights){
            if(i>mid) return false;
            if(sum + i <= mid){
                sum+=i;
            }else{
                count++;
                sum=i;
            }
            if(days < count) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0; 
        for(int i:weights) sum+=i;
        int ans=0;
        int l = 0;
        int h= sum;
        while(l<=h){
            int mid = l+(h-l) / 2;
            if(canShip(weights,days,mid)){
                ans = mid;
                h = mid -1;
            } else{
                l = mid+1;
            }
        }
        return ans;
    }
};
