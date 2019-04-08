#include <iostream>
#include <vector>

using namespace std;

int numDiv(int goal)
{
    if (goal == 1)
        return 1;
    if (goal < 1)
        return -1;
    vector<vector<int> > v(goal + 1);
    for (int i = 0; i < goal + 1; i++)
        v[i].resize(goal + 1);
    for (int i = 0; i < goal + 1; i++)
    {
        v[i][1] = 1;
        v[0][i] = 1;
    }
    for (int i = 1; i < goal + 1; i++)
    {
        for (int j = 2; j < i + 1; j++)
        {
            for (int k = j; k > 0; k--)
                v[i][j] += v[i - k][min(i-k, k)];
        }
    }
    cout << v[5][4] << endl;
    cout << v[5][3] << endl;
    cout << v[5][2] << endl;
    
    return v[goal][goal];
}

int main(void)
{
    cout << numDiv(5);
}
