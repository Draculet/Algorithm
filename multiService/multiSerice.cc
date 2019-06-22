#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	int s;
	cin >> n;
	cin >> s;
	vector<int> vec;
	vec.resize(n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		vec[i] = tmp;
	}
	sort(vec.begin(), vec.end());
	vector<int> service[s];
	vector<int> sum;
	for (int i = 0; i < s; i++)
		service[i].resize(n / s + 1);
	sum.resize(n / s + 1);
	int i;
	for (i = 0; i < n; i++)
	{
		service[i % s][i / s] += vec[i];
		if (i != 0)
			service[i % s][i / s] += service[i % s][i / s - 1];
		sum[i / s] += service[i % s][i / s];
		if ((i % s == s - 1 && i / s != 0) || i == n - 1)
		{
			//cout << "here" << sum[i / s] << endl;
			sum[i / s] += sum[i / s - 1];
		}
	}
	i--;
	cout << sum[i / s] << endl;
}
