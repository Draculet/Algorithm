#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class SubArray
{
    public:
    //时间O(n)(3次交换,每次T = n),空间O(1)
    void swapSub(vector<T> &vec, int i, int j, int k)
    {
        pswap(vec, i, k - 1);
        pswap(vec, k, j);
        pswap(vec, i , j);
    }

    void sortArray(vector<T> &vec, int k)
    {
        int i = 0;
        while (k < vec.size() && i <= k)
        {
            if (vec[i] > vec[k])
            {
                swapSub(vec, i, k, k);
                k++;
            }
            else
                i++;
        }
    }
    private:
        void pswap(vector<T> &vec, int i, int j)
        {
            while (i < j)
            {
                T tmp;
                tmp = vec[i];
                vec[i] = vec[j];
                vec[j] = tmp;
                i++;
                j--;
            }
        }
};

int main(void)
{
    SubArray<int> s;
    vector<int> v = {2, 3, 4, 9, 1, 5, 5, 5};
    for (auto &iter: v)
        cout << iter;
    cout << endl;
    //s.swapSub(v, 3,4,4);
    s.sortArray(v, 4);
    for (auto &iter: v)
        cout << iter;
    cout << endl;

    return 0;
}
