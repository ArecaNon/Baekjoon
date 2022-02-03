#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N,temp;
	int* arr;
	scanf(" %d", &N);
	arr = new int[N] { 0, };
	for (int i = 0; i < N; i++)
	{
		int count = -1;
		scanf(" %d", &temp);
		
		int j = -1;
		while(count < temp)
		{
			j++;
			if (arr[j] > i+1 || arr[j] == 0)
			{
				count++;
			}
		}
		arr[j] = i + 1;	
	}

	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
}