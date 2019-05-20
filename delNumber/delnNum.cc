#include <iostream>
using namespace std;

int main(void)
{
	string num;
	string res;
	cin >> num;
	int n;
	cin >> n;
	int dn = n;
	int size = num.size();
	int i = 0;
	while (i < num.size())
	{
		if (i+1 == num.size())
		//如果剩下数是全部递增的,那么直接取前size-n位数即可
		{
			if (num.size() >= size - n)
			{
				res = string(num.c_str(), size - dn);
				cout << res << endl;
				return 0;
			}
			else
			{
				num.erase(i, 1);
				n--;
				if (n == 0)
				{
					res = num;
					cout << res << endl;
					return 0;
				}
				i-=2;
			}
		}
		
		else if (num[i + 1] < num[i])
		{
			num.erase(i, 1);
			n--;
			if (n == 0)
			//减的位数达到目标
			{
				res = num;
				cout << res << endl;
				return 0;
			}
			i-=2;
			if (i < 0)
				i = -1;
		}
		i++;
	}
}
