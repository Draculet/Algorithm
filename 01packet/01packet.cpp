#include <iostream>
#include <vector>
using namespace std;

int packet(int n, int c, vector<int>& w, vector<int>& v)
{
	vector<vector<int> > vec(n);
	for (int i = 0; i < vec.size(); i++)
		vec[i].resize(c + 1);
	for (int i = 0; i < min(c + 1, w[0]); i++)
		vec[0][i] = 0;
	if (c + 1 > w[0])
		for (int i = w[0]; i < c + 1; i++)
			vec[0][i] = v[0];
	for (int i = 1; i < vec.size() - 1; i++)
	{
		for (int j = 0; j < min(c + 1, w[i]); j++)
			vec[i][j] = vec[i - 1][j];
		if (c + 1 > w[i])
			for (int j = w[i]; j < c + 1; j++)
				vec[i][j] = max(vec[i - 1][j - w[i]] + v[i], vec[i - 1][j]);
	}
	int i = vec.size() - 1;
	int j = c;
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[0].size(); j++)
			cout << vec[i][j] << " ";
		cout << endl;
	}
	return max(vec[i - 1][j - w[i]] + v[i], vec[i - 1][j]);
}

int main(void)
{
	vector<int> w = {2, 3, 4, 5};
	vector<int> v = {3, 4, 5, 6};
	cout << packet(w.size(), 8, w, v) << endl;
	return 0;	
}
