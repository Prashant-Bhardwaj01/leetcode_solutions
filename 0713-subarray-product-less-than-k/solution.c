int numSubarrayProductLessThanK(int* nums, int n, int k) {
    int l = 0;
    int r = 0;
    int c = 0;
    if(k==0) return 0;
    long long prod = 1;
    while(r<n){
        prod*=nums[r];
        while(l<=r&&prod>=k){
            prod /=nums[l];
            l++;
        }
        c += r-l+1;
        r++;
    }
    return c;
}
