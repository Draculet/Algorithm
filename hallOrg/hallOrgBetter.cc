#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
class integer
{
	public:
	integer(int n, int f)
	{
		num = n;
		flag = f;
	}
	
	int num;
	int flag;
};

bool cmp(integer i1, integer i2)
{
	return i1.num < i2.num;
}

int main(void)
{
	vector<integer> actTime;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int begin;
		int end;
		cin >> begin;
		cin >> end;
		actTime.push_back(integer(begin, 0));
		actTime.push_back(integer(end, 1));
	}
	sort(actTime.begin(), actTime.end(), cmp);
	//for (auto i: actTime)
	//	cout << i.num << " ";
	//cout << endl;
	int count = 0;
	int max = -1;
	for (int i = 0; i < actTime.size(); i++)
	{
		if (actTime[i].flag == 0)
		{
			count++;
			if (count > max)
				max = count;
		}
		else if (actTime[i].flag == 1)
			count--;
	}
	cout << max << endl;
	
}
