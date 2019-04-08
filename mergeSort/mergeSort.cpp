#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& v, int i1, int j1, int i2, int j2);
void mergeSort(vector<int>& v)
{
    vector<int> grp;
    grp.push_back(0);
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i + 1] < v[i])
        {
            grp.push_back(i);
            grp.push_back(i + 1);
        }
    }
    grp.push_back(v.size() - 1);
    
    int grpnum = grp.size() / 2;//组数
    int grpsize = grp.size();//组数组元素个数
    
    cout << "grpnum :" << grpnum << endl;
    cout << "grpsize :" << grpsize << endl;
    while (grpnum > 1)
    {
        int k = 0;
        int i;
        for (i = 0; i + 3 < grpsize; i+=4)
        {
            merge(v, grp[i], grp[i + 1], grp[i + 2], grp[i + 3]); 
            
            for (auto i: v)
            {
                 cout << i << " ";
            }
            cout << endl;
            for (int i = 0; i < grpsize; i++)
            {
                 cout << grp[i] << " ";
            }
            cout << endl;
            //部分排序后更新组下标
            grp[k] = grp[i];
            grp[k + 1] = grp[i + 3];
            k += 2;
        }
        //多余组下标更新
        while (i < grpsize)
        {
            grp[k] = grp[i];
            i++;
            k++;
        }
        //更新组数
        grpnum = (grpnum / 2 + grpnum % 2);
        //由于数组是重复利用的,所以需要更新数组的边界
        grpsize = grpnum * 2;
    }
}

void merge(vector<int>& v, int i1, int j1, int i2, int j2)
{
    vector<int> tmp(j2 - i1 + 1);
    int begin = i1;
    int k = 0;
    while (i1 <= j1 && i2 <= j2)
    {
        if (v[i1] < v[i2])
        {
            tmp[k] = v[i1];
            i1++;
            k++;
        }
        else
        {
            tmp[k] = v[i2];
            i2++;
            k++;
        }
    }
    if (i1 > j1)
    {
        while (i2 <= j2)
        {
            tmp[k] = v[i2];
            i2++;
            k++;
        }
    }
    else
    {
        while (i1 <= j1)
        {
            tmp[k] = v[i1];
            i1++;
            k++;
        }
    }
    k = begin;
    for (int i = 0; i < tmp.size(); i++)
    {
        v[k] = tmp[i];
        k++;
    }
}

int main(void)
{
    vector<int> v = {3,3,3,5,2,5,4,1,0,-1,5,2,2,3,2};
    mergeSort(v);
    for (auto i: v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
    vector<int> v2 = {3,3,3,5,2,5,4,1,0,-1,5,2,2,3,2,1,5};
    mergeSort(v2);
    for (auto i: v2)
    {
        cout << i << " ";
    }
}
