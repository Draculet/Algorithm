#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class SubArray
{
    public:
    void arrayMerge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        if (i < 0)
        {
            nums1 = nums2;
        }
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        if (i < 0)
        {
            while (j >= 0)
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
        }
        else if (j < 0)
        {
            while (i >= 0)
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
    }
};

int main(void)
{
    SubArray<int> s;


    return 0;
}
