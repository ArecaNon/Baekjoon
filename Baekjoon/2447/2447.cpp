#include <iostream>
#include <cmath>

using namespace std;

void star(int i, int j, int n);
void solution();

int main()
{
	solution();
	return 0;
}

void star(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) 
	{
		cout << " ";
	}
	else 
	{
		if (n / 3 == 0)
		{
			cout << "*";
		}
		else
			star(i, j, n / 3);
	}
}

void solution()
{
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			star(i,j,num);
		}
		cout<<""<< endl;
	}
}