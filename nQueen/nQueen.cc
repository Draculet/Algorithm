#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
bool place(int k, vector<int> x);

int main(void)
{
	while(1)
	{
	int n;
	int sum = 0;
	cin >> n;
	vector<int> x;
	x.resize(n + 1);
	x[0] = -1;
	x[1] = 0;
	int k = 1;
	while (k > 0)
	{
		x[k]++;
		while ((x[k] <= n) && !place(k, x))
			x[k]++;
			
		if (x[k] > n)
			k--;//回溯
		else
		{
			if (k == n)
				sum++;
			else
			{
				k++;//下一层
				x[k] = 0;//列数置0,由新0列开始
			}
		}
	}
	cout << n << "皇后问题有" << sum << "种解法"<< endl;
	}
}
bool place(int k, vector<int> x)//判断能否放置
{
	for (int i = 1; i < k; i++)
	{
		if ( (abs(k - i) == abs(x[i] - x[k])) || (x[i] == x[k]))
			return false;
	}
	return true;
}
