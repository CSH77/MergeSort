#include <iostream>
#include <vector>

using namespace std;

void MergeTwoArea(vector<int>& vec, int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;

    vector<int> sortVec;
    sortVec.resize(vec.size());

	int sIdx = left;

	while(fIdx <= mid && rIdx<=right)
	{
		if(vec[fIdx] <= vec[rIdx])
			sortVec[sIdx] = vec[fIdx++];
		else
			sortVec[sIdx] = vec[rIdx++];

		sIdx++;
	}

	if(fIdx > mid)
	{
		for(int i = rIdx; i <= right; i++, sIdx++)
			sortVec[sIdx] = vec[i];
	}
	else
	{
		for(int i = fIdx; i<=mid; i++, sIdx++)
			sortVec[sIdx] = vec[i];
	}

	for(int i = left; i<=right; i++)
		vec[i] = sortVec[i];

}

void MergeSort(vector<int>& vec, int left, int right)
{
	int mid;

	if(left < right)
	{
		//중간 지점을 계산한다.
		mid = (left+right) / 2;

		//둘로 나눠서 각각을 정렬한다.
		MergeSort(vec, left, mid);
		MergeSort(vec, mid+1, right);

		//정렬된 두 배열을 병합한다.
		MergeTwoArea(vec, left, mid, right);
	}
}

int main(void)
{
    vector<int> vec = {3, 2, 4, 1, 7, 6, 5};

	MergeSort(vec, 0, vec.size() - 1);

    for(auto iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

	return 0;
}
