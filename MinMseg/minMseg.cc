#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	while(1)
	{
	vector<int> arr;
	int row, col, num;
	cin >> row; //n个数
	cin >> col; //m段
	vector<vector<int> > vec(row + 1);
	for (int i = 0; i < vec.size(); i++)
		vec[i].resize(col + 1);
	for (int i = 0; i < row; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 1; i <= row; i++)
	{
		vec[i][1] = vec[i - 1][1] + arr[i - 1];
	}
	for (int i = 2; i <= row; i++)
	{
		for (int j = 2; j <= min(i, col); j++)
		//j不能大于i和分段数中最小的一个
		{
			int min = 99999;
			for (int k = j - 1 ; k <= i - 1; k++)
			{
				int tmp = max(vec[k][j - 1], vec[i][1] - vec[k][1]);
				//k从j-1开始是为了至少保留j-1个数可分为j-1段
				//k在i-1结束是为了至少保留1个数作为最后一个分组
				//其他k都是无效的
				if (tmp < min)
					min = tmp;
			}
			vec[i][j] = min;
			cout << "vec" << i << " " <<  j  << " " <<  min << endl;
		}	
	}
	cout << "Result: " << vec[row][col] << endl;
	}
	return 0;
}
