class Solution {
    #define ll long long
    #define pii pair<ll,ll>
    ll MOD = 1e9+7;
    void calculateScore(vector<int>& nums,vector<ll>& score){
        for(ll ele:nums){
            ll count = 0;
            for(ll i=2; i*i<ele;i++){
                if(ele%i==0)
                count++;
                while(ele%i==0)
                ele/=i;
            }
            if(ele>1) count++;
            score.push_back(count);
        }
    }
    void calc_scps(vector<ll>& score,vector<ll>& sub_count){
        vector<ll> pge;
        stack<ll> st;
        ll n=score.size();
        for(ll i=0;i<n;i++){
            while(!st.empty() and score[st.top()] < score[i]){
                st.pop();
            }
            if(st.empty()) pge.push_back(-1);
            else pge.push_back(st.top());
            st.push(i);
        }
            st = stack<ll>();
            ll count;
            for(ll i=n-1;i>=0;i--){
                count = 0;
                while(!st.empty() and score[st.top()] <= score[i])
                    st.pop();
                if(st.empty()) count = (n-i) * (i-pge[i]);
                else count = (st.top() - i)*(i-pge[i]);
                st.push(i);
                sub_count[i] = count;
            
        }
    }
    ll binary(long long a,long long b){
        ll res = 1;
        while(b){
            if(b&1) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b = b/2;
        }
        return res%MOD;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        ll n = nums.size();
        vector<ll> score;
        calculateScore(nums,score);
        vector<ll> sub_count(n);
        calc_scps(score,sub_count);
        priority_queue<pii> mx;
        for(ll i=0;i<n;++i){
            mx.push(make_pair(nums[i],i));
        }
        long long r = 1;
        while(k>0){
            pii curr = mx.top();
            mx.pop();
            r = (r * binary(curr.first,min((ll)k,sub_count[curr.second]))) % MOD;
            k -= sub_count[curr.second];
        }
        return r;
    }
};
