#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{ 
	int n;
	while (true) 
	{
		int temp;
		int max = -2000000;
		scanf(" %d", &n);
		if(!n) break;

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf(" %d", &temp);
			sum = sum + temp > temp ? sum + temp : temp;
			if (max < sum) max = sum;
		}
		printf("%d\n", max);
	}
}