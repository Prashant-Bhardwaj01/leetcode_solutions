class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0; i<n; i++){
            int sum = 0;
            int j =i;
            int c = 0;
            while(c<n){
                sum+=gas[j]-cost[j];
                if(sum<0) {
                    break;
                }
                j = (j+1)%n;
                c++;
            }
            if(c == n) return i;
            if(j<i) return -1;
            i = j;
        }
        return -1;
    }
};
