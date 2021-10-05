#include <iostream>

using namespace std;

int factorial(int n);
void solution();

int Memory[13];
int main()
{
	solution();
	return 0;
}

int factorial(int n)
{
	if (n != 0 && Memory[n] != NULL)
		return Memory[n];
	else if (n == 1 || n == 0)
		return 1;
	else 
	{
		Memory[n] = n * factorial(n-1);
		return Memory[n];
	}
}

void solution()
{
	int num;
	cin >> num;
	
	num = factorial(num);

	cout << num << endl;
}