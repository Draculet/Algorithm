class Solution {
public:
    int climbStairs(int n) {
        vector<int> v;
        v.resize(n + 1);
        v[1] = 1;
        v[2] = 2;
        for (int i = 3; i < n; i++)
        {
            v[i] = v[n - 1] + v[n - 2];
        }
        return v[n];
    }
};
