#include <iostream>
#include <vector>

using namespace std;

int numDiv(int goal)
{
    if (goal == 1)
        return 1;
    if (goal < 1)
        return -1;
    vector<int> v(goal + 1);
    v[1] = 1;
    for (int i = 2; i < goal + 1; i++)
    {
        for (int k = i;k > 1; k--)
        {
            if (i % k == 0) 
                 v[i] += v[i / k];
        }
    }

    return v[goal];
}

int main(void)
{
    for (int i = 1; i < 25;i++)
        cout << numDiv(i) << endl;
}
