#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> hallEnd;
	vector<pair<int, int> > actTime;
	int num = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int begin;
		int end;
		cin >> begin;
		cin >> end;
		actTime.push_back(pair<int, int>(begin, end));
	}
	hallEnd.push_back(actTime[0].second);//存入第一个活动的结束时间
	for (int i = 1; i < num; i++)
	{
		int j;
		for (j = 0; j < hallEnd.size(); j++)
		{
			if (actTime[i].first >= hallEnd[j])
			{
				hallEnd[j] = actTime[i].second;
				break;
			}
		}
		if (j == hallEnd.size())
		{
			hallEnd.push_back(actTime[i].second);
		}
		//for (auto n : hallEnd)
		//	cout << n << " ";
		//cout << endl;
	}
	
	cout << hallEnd.size();
	return 0;
}
