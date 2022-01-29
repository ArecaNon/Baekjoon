#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstdio>
int solve(int mid,int n,int m,int *charge);
int main()
{
    int n, m, high, low, mid, ans;
    int sum = 0;
    int *charge;
    scanf(" %d %d", &n, &m);
    
    charge = new int[n];
    for (int i = 0; i < n; i++)
    {
           scanf(" %d",&charge[i]);
           sum += charge[i];
    }

    low = 1, high = sum;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(solve(mid,n,m,charge))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    printf("%d",ans);

    return 0;
}

int solve(int mid,int n,int m,int *charge)
{
    int count = 1;
    int sum = mid;
    
    for (int i = 0; i < n; i++)
    {
        if(mid < charge[i]) return false;
        if(sum - charge[i] < 0) { sum = mid; count++; }
        sum -= charge[i];
    }
    if(m>=count)
        return true;
    return false;
}
