#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> vec;
	vector<int> arr;
	vec.resize(n + 1);
	arr.push_back(-1);
	vec[0] = -1;
	vec[1] = 1;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] <= arr[i])
				vec[i] = max(vec[i], vec[j] + 1);
		}
	}
	int maxn = -1;
	int maxpos = -1;
	for (int i = n; i >= 1; i--)
	{
		if (vec[i] > maxn)
		{
			maxn = vec[i];
			maxpos = i;
		}
	}
	cout << "最大子序列数字个数: ";
	cout << maxn << endl;
	cout << "子序列: ";
	--maxn;
	while (maxn >= 1)
	{
		int before = maxpos;
		cout << arr[maxpos] << endl;
		for (int i = arr.size(); i >=1; i--)
		{
			if (vec[i] == maxn && arr[i] < arr[maxpos])
			{
				cout << arr[i] << endl;
				maxn--;
				maxpos = i;
			}
			
		}
	}
	
	return 0;
}


