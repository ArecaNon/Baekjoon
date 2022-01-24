#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sorting();
void solution();

int n;
vector<int> arr;

int main() 
{
	solution();
	return 0;
}

void sorting() 
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j]) 
				arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
		}
	}
}

void solution() 
{
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sorting();

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
}