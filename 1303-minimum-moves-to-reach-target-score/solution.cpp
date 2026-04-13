class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles == 0) return target-1;
        int ans = 0;
        while(target>1){
            if(maxDoubles>0){
                if(target%2 == 0){
                    target = target/2;
                    maxDoubles--;
                }else{
                    target = target-1;;
                }
                ans++;
                continue;
            }
            target = target - 1;
            ans++;
        }
        return ans;
    }
};
