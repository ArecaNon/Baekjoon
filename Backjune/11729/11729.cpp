#include <iostream>
using namespace std;

void hanoi(int i, int j, int k,int n);

int main()
{
	int num;
	cin >> num;

	cout << (1 << num) - 1 << endl;
	hanoi(1, 3, 2, num);
}

void hanoi(int i, int j, int k,int n)
{
	if (n == 1)
		cout << i << ' ' << j << endl;
	else 
	{
		hanoi(i, k, j, n - 1);
		cout << i << ' ' << j << endl;
		hanoi(k, j, i, n - 1);
	}
}
