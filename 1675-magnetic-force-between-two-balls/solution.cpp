class Solution {
public:
    bool can(vector<int>& position, int m, int mid){
        int count = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i] - last >= mid){
                count++;
                last=position[i];
            }
            if(count==m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        long long l = 1;
        long long h = position[n-1]-position[0];
        int ans = -1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(can(position,m,mid)){
                ans = mid;
                l = mid+1;
                
            }else{
                h = mid - 1;
            }
        }
        return ans;
    }
};
