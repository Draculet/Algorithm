#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> arr;
	int row, col, num;
	cin >> row;//n个数
	cin >> col;//m段
	vector<vector<int> > vec(row + 1);
	for (int i = 0; i <= vec.size(); i++)
		vec[i].resize(col + 1);
	arr.push_back(0);
	for (int i = 1; i <= row; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 1; i <= row; i++)
	{
		vec[i][1] = vec[i - 1][1] + arr[i];
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 2; j <= col; j++)
		{
			int min = 99999;
			for (int k = 1; k < i; k++)
			{
				int tmp = max(vec[k][j - 1], vec[i][1] - vec[k][1]);
				cout << "here tmp" << " " << tmp << endl;
				if (tmp < min)
					min = tmp;
			}
			vec[i][j] = min;
		}
	}
	cout << vec[row][col];
	return 0;
}
