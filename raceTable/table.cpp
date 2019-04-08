#include <iostream>
#include <vector>
using namespace std;

void talbe(int k, vector<vector<int> > &v)
{
    int n = 1;
    for (int i = 1; i <= k; i++)
        n *= 2;
    for (int i = 1; i <= n; i++)
        v[1][i] = i;
    int m = 1;
    for (int s = 1; s <= k; s++)
    {
        n /= 2;
        for (int t = 1; t <= n; t++)
            for (int i = m + 1; i <= 2 * m; i++)
                for (int j = m + 1; j <= 2 * m; j++)
                {
                    v[i][j + (t - 1) * m * 2] = v[i - m][j + (t - 1) * m * 2 - m];
                    v[i][j + (t - 1) * m * 2 - m] = v[i - m][j + (t - 1) * m * 2];
                }
        m *= 2;
    }
}

int main(void)
{
    vector<vector<int> > v(9);
    for (int i = 0; i < v.size(); i++)
        v[i].resize(9);
    talbe(3, v);//k=3 矩阵就是2^3+1 * 2^3+1的
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
        
}
