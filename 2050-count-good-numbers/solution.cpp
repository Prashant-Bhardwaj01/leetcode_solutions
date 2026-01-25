class Solution {
public:
    const long long MOD = 1e9+7;
    long long power(long long base, long long expo){
        long long ans = 1;
        while(expo){
            if(expo&1) ans = (ans*base)%MOD;
            base = (base*base)%MOD;
            expo = expo>>1; 
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        double even = (n+1)/2;
        double odd = n/2;
        return (power(5,even)*power(4,odd))%MOD;
    }
};
