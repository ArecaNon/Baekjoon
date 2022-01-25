#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>

int **map;

int main()
{
    int *color;
    int h,w,c,count;
    scanf(" %d%d%d",&h,&w,&c);

    color = new int[c];
    for(int i = 0; i<c;i++)
    {
        scanf(" %d",&color[i]);
    }

    map = new int*[h];
    map[0] = new int[h*w];
    for (int i = 1; i < h; i++)
        map[i] = map[i-1]+w;

    int idx = c-1;
    int color_num = color[idx];

    int dir = -1;
    for (int i = h-1; i >= 0; i--, dir*=-1)
    {
        count = 0;
        for (int j = (dir > 0) ? 0:w-1 ;count < w; j+=dir)
        {
            if(color_num != 0)
            {
                map[i][j] = idx+1;
                color_num--;
            }
            else
            {
                idx--;
                color_num = color[idx]-1;
                map[i][j] = idx+1;
            }
            count++;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
           printf("%d",map[i][j]);
        }
        printf("\n");
    }
    
    delete[] map[0];
    delete[] map;
}

//vector와 algorithm을 이용, int가 아닌 char을 이용해서 출력과 입력을 더 간결히 가능 