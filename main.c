 #include <stdio.h>
#include <stdlib.h>

#define MAX 99
int a[MAX][MAX], n, sx, sy, ex, ey;
int Dx[]={0,-1,1,0,0};
int Dy[]={0,0,0,-1,1};
int location[MAX][MAX];


void initialize();
void show_original();
void trace(int x, int y, int k);
void show_trace();
int continue_conidition(int xNow, int yNow, int x, int y);


int main()
{
    initialize();
    trace(sx, sy, 1);
    return 0;
}


void trace(int x, int y, int k)
{
    int xNow, yNow;
    location[x][y]=k;

    if(x==ex&&y==ey)
    {
        show_trace();
        return;
    }

    int i;
    for(i=1;i<=4;i++)
    {
        xNow=x+Dx[i];
        yNow=y+Dy[i];

        if(continue_conidition(xNow, yNow, x, y)) trace(xNow, yNow, k+1);
        if(i==4)location[x][y]=0;
    }
}


int continue_conidition(int xNow, int yNow, int x, int y)
{
    if(xNow>=1&&xNow<=n&&yNow>=1&&yNow<=n)
    if(a[xNow][yNow]<=a[x][y])
    if(a[xNow][yNow]>0)
    return 1;
    return 0;
}


void show_original()
{
    printf("~~~~~~~~~~~ ORIGINAL MAP ~~~~~~~~~~~~\n\n");
    int i, j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n~~~ STARTING POSITION || ENDING POSITION ~~~\n\n %d %d || %d %d \n\n\n", sx, sy, ex, ey);

}


void show_trace()
{
    printf("~~~~~ POSSIBLE ROUTE ~~~~~\n\n");
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++) printf("%d ",location[i][j]);
        printf("\n");
    }
    printf("\n");
}


void initialize()
{
    n=5;
    sx=2; sy=2; ex=5; ey=4;

    int x[]=
    {400, 1300, 1200, 900, 3400,
    -22, 2000, 3000, 880, 860,
    -22, 1400, 2400, 720, 750,
    -22, 1200, 800, 700, -22,
    300, 500, -22, 1, -22};

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            location[i][j]=0;
            a[i][j]=x[(i-1)*n+j-1];
        }

    show_original();
}
