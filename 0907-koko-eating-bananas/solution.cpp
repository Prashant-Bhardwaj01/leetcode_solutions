class Solution {
public:
    bool canEat(vector<int>& piles, int h,int mid){
        long long time = 0;
        for(int i:piles){
            time += (i+mid-1)/mid ;
        }
        if(time<=h)return true;
        return false; 
    }
    int minEatingSpeed(vector<int>& piles, int t) {
        int n = piles.size();
        int l = 1;
        int mx = INT_MIN;
        for(int i=0;i<n;i++) if(mx<piles[i]) mx = piles[i];
        int h = mx;
        int ans = 1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(canEat(piles,t,mid)==true){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
