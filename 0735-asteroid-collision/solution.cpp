class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        stack<int> st;
        int i = 0;
        st.push(arr[i++]);
        while(i<n){
            int ast = arr[i];
            bool check = false;
            while(!st.empty() && ast < 0 && st.top()>0){
                if(st.top()<abs(ast)){
                    st.pop();
                    continue;
                }
                else if(st.top() == abs(ast)){
                    st.pop();
                    check = true;
                    break;
                }else{
                    check = true;
                    break;
                }
            }
            if(!check){
                st.push(ast);
            }i++;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
