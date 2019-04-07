class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> vec;
        if (nums.size() == 0)
            return 0;
        int n = nums.size();
        vec.resize(nums.size());
        vec[0] = nums[0];
        if (nums.size() > 1)
            vec[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            int max = -1;
            for (int j = 0; j < i - 1; j++)
                if (vec[j] > max)
                    max = vec[j];
            vec[i] = max + nums[i];
        }
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            if (vec[i] > max)
                max = vec[i];
        }
        return max;
    }
};
