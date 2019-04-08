#include <iostream>
#include <vector>

using namespace std;

int count = 0;
template<typename T>
void perm(vector<T>& vec, int k)
{
    int m = vec.size();
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << vec[i] << " ";
        cout << endl;
        count++;
    }
    else
    {
        for (int i = k; i < m; i++)
        {
            swap(vec[k], vec[i]);
            perm(vec, k + 1);
            swap(vec[k], vec[i]);
        }
    }
}

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    b = a;
    a = tmp;
}

int main(void)
{
    vector<char> v = {'A', 'B', 'C', 'D'};
    perm(v, 0);
    cout << "Total count " << count << endl;
}
