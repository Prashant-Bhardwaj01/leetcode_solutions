class Solution {
public:
    bool canBloom(vector<int>& bloomDay, int m, int k,int mid){
        int bloomed = 0;
        int count = 0;
        for(int i:bloomDay){
            if(i<=mid){
                count++;
            }else{
                count=0;
            }if(count==k){
                bloomed = bloomed+1;
                count=0;
            }
            if(bloomed == m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int maxx = INT_MIN;
        int minn = INT_MAX;
        for(int i:bloomDay){
            maxx = max(maxx,i);
            minn = min(minn,i);
        }
        int l = minn;
        int h = maxx;
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(canBloom(bloomDay,m,k,mid)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};
