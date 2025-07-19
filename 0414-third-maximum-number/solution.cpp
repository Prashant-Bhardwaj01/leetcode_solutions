class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long l1 = LLONG_MIN, l2 = LLONG_MIN, l3 = LLONG_MIN;

        for (int num : nums) {
            if (num == l1 || num == l2 || num == l3) continue; 

            if (num > l1) {
                l3 = l2;
                l2 = l1;
                l1 = num;
            } else if (num > l2) {
                l3 = l2;
                l2 = num;
            } else if (num > l3) {
                l3 = num;
            }
        }

        return (l3 == LLONG_MIN) ? l1 : l3;
    }
};
