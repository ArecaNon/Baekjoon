#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <cstdio>
int map[21][21][21] = {{0,}};
int w(int a,int b,int c);
int main ()
{   
    while(true)
    {
        int a,b,c;
        scanf(" %d %d %d",&a,&b,&c);
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
    return 0;
}

int w(int a,int b,int c)
{
    int temp1,temp2,temp3,temp4;
    if(a <= 0 or b <= 0 or c <= 0)
    {
        return 1;
    }
    else if(a > 20 or b > 20 or c > 20)
    {
        if(map[20][20][20] != 0)
            return map[20][20][20];
        else
        {
            temp1 = w(20, 20, 20);
            map[20][20][20] = temp1; 
            return temp1;
        }
    }
    else if(a < b && b < c)
    {
        if(map[a][b][c-1] != 0) 
            temp1 = map[a][b][c-1];
        else
        {
            temp1 = w(a, b, c-1);
            map[a][b][c-1] = temp1;
        }
        if(map[a][b-1][c-1] != 0)
            temp2 = map[a][b-1][c-1];
        else
        {
            temp2 = w(a, b-1, c-1);
            map[a][b-1][c-1] = temp2;
        }
        if(map[a][b-1][c] != 0)
            temp3 = map[a][b-1][c];
        else
        {
            temp3 = w(a, b-1, c);
            map[a][b-1][c] = temp3;
        }
        return temp1 + temp2 - temp3;
    }
    else
    {
         if(map[a-1][b][c] != 0) 
            temp1 = map[a-1][b][c];
        else
        {
            temp1 = w(a-1, b, c);
            map[a-1][b][c] = temp1;
        }

        if(map[a-1][b-1][c] != 0)
            temp2 = map[a-1][b-1][c];
        else
        {
            temp2 = w(a-1, b-1, c);
            map[a-1][b-1][c] = temp2;
        }
        if(map[a-1][b][c-1] != 0)
            temp3 = map[a-1][b][c-1];
        else
        {
            temp3 = w(a-1, b, c-1);
            map[a-1][b][c-1] = temp3;
        }
        if(map[a-1][b-1][c-1] != 0)
            temp4 = map[a-1][b-1][c-1];
        else
        {
            temp4 = w(a-1, b-1, c-1);
            map[a-1][b-1][c-1] = temp4;
        }
        return temp1 + temp2 + temp3 - temp4;
    }
}