class Solution {
public:
    int pivotInteger(int n) {
        vector<int> pre(n+1,0);
        int sum=(n*(n+1))/2;
        for(int i=1;i<=n;i++) pre[i] = i;
        for(int i = 2;i<n;i++){
            pre[i] = pre[i-1]+pre[i];
        }
        int leftSum = 0;
        int rightSum = 0;
        for(int i=1;i<=n;i++){
            leftSum = pre[i];
            rightSum = sum - leftSum + i;
            if(leftSum == rightSum) return i; 
        }
        return -1; 
    }
};
