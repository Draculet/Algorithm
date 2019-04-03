#include <iostream>
#include <vector>

using namespace std;

void MatrixChain(vector<int>& p, int n, vector<vector<int> >& m, vector<vector<int> >& s)
{
	for (int i = 0; i < n; i++)
		m[i][i] = 0;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j + i < n; j++)
		{
			int min = 9999999;
			int kpos = -1;
			for (int k = j; k < j + i; k++)
			{
				if ( (m[j][k]+m[k+1][j + i] + p[j]*p[k + 1]*p[j + i + 1]) < min)
				{
					min = m[j][k]+m[k + 1][j + i] + p[j]*p[k + 1]*p[j + i + 1];
					kpos = k;
				}
			}
			m[j][j + i] = min;
			s[j][j + i] = kpos;
		}
	}
}

int main(void)
{
	vector<int> p = {4, 8, 12, 7, 9, 30, 4, 65, 52};
	int n = p.size() - 1;
	vector<vector<int> > m(n);
	for (int i = 0; i < n; i++)
		m[i].resize(n);
	vector<vector<int> > s(n);
	for (int i = 0; i < n; i++)
		s[i].resize(n);
	MatrixChain(p, n, m, s);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << s[i][j] << " ";
		cout << endl;
	}
}

