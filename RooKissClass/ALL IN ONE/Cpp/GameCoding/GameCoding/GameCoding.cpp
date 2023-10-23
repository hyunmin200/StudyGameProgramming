#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>

void MergeResult(vector<int>& v, int left, int mid, int right)
{
    int leftIdx = left;
    int rightIdx = mid + 1;

    vector<int> temp;

    while (leftIdx <= mid && rightIdx <= right)
    {
        if (v[leftIdx] <= v[rightIdx])
        {
            temp.push_back(v[leftIdx]);
            leftIdx++;
        }
        else
        {
            temp.push_back(v[rightIdx]);
            rightIdx++;
        }
    }

    if (leftIdx > mid)
    {
        while (rightIdx <= right)
        {
            temp.push_back(v[rightIdx]);
            rightIdx++;
        }
    }
    else
    {
        while (leftIdx <= mid)
        {
            temp.push_back(v[leftIdx]);
            leftIdx++;
        }
    }

    for (int i = 0; i < temp.size(); i++)
        v[left + i] = temp[i];
}

void MergeSort(vector<int>& v, int left, int right)
{
    if (left >= right) // 1개 남았을 때
        return;

    int mid = (left + right) / 2;

    MergeSort(v, left, mid);
    MergeSort(v, mid + 1, right);

    MergeResult(v, left, mid, right);
}

int main()
{
    vector<int> v{1, 5, 3, 4, 2};

    MergeSort(v, 0, v.size() - 1);
}