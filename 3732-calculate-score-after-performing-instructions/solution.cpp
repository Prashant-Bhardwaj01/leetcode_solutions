class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = values.size();
        long long ans = 0;
        int i = 0;
        vector<bool> visjump(n,false); 
        vector<bool> visadd(n,false);
        if(n == 1){
            if(instructions[0] == "jump"){
                return ans;
            }else{
                return values[0];
            }
        }
        while(i>=0 && i<n){
            if(instructions[i] == "jump"){
                if(!visjump[i]){
                    visjump[i] = true;
                    i = i+values[i];
                }else{
                    break;
                }
                
            }
            else{
                if(!visadd[i]){
                    ans += values[i];
                    visadd[i] = true;
                    i++;
                }else{
                    break;
                }  
            }
        }
        return ans;
    }
};
