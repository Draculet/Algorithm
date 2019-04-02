#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class SubArray
{
    public:
    //时间O(n^2)空间O(1)
    void swapSub(vector<T> &vec, int k)
    {
        if (k < 0 || k > vec.size())
            exit(-1);
        T tmp;
        for (int i = 0 ; i < k; i++)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (j == 0)
                    tmp = vec[0];
                vec[j] = vec[j + 1];
            }
            vec[vec.size() - 1] = tmp;
        }
    }
    //时间O(n)(3次交换,每次T = n),空间O(1)
    void swapSub2(vector<T> &vec, int k)
    {
        if (k < 0 || k > vec.size())
            exit(-1);
        pswap(vec, 0, k - 1);
        pswap(vec, k, vec.size() - 1);
        pswap(vec, 0 , vec.size() - 1);
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
    vector<int> v = {9, 8 ,7 , 1, 2, 3, 4, 10, 23, 43};
    vector<int> v2 = {9, 8 ,7 , 1, 2, 3, 4, 10, 23, 43};
    for (auto &iter: v)
        cout << iter;
    cout << endl;
    s.swapSub(v, 10);
    s.swapSub2(v2, 10);
    for (auto &iter: v)
        cout << iter;
    cout << endl;

    for (auto &iter: v2)
        cout << iter;
    cout << endl;

    return 0;
}
