#include<iostream>
#include<vector>
using namespace std;
bool issafe(int x,int y,int n,vector<vector<int>>&board)
{
   return (x>=0&&y>=0&&x<n&&y<n&&board[x][y]==-1);
}
bool solveboard(int x,int y,vector<vector<int>>&board,int xmove[],int ymove[],int movei,int n)
{
    if(n*n==movei)return true;

    for(int k=0;k<8;k++)
    {
        int next_x=x+xmove[k];
        int next_y=y+ymove[k];
        if(issafe(next_x,next_y,n,board))
        {
            board[next_x][next_y]=movei;
            if(solveboard(next_x,next_y,board,xmove,ymove,movei+1,n))return true;
            board[next_x][next_y]=-1;

        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,-1));
    int xmove[8]={2,1,-1,-2,-2,-1,1,2};
    int ymove[8]={1,2,2,1,-1,-2,-2,-1};
    board[0][0]=0;
    if(solveboard(0,0,board,xmove,ymove,1,n))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"nosolution exists";
    }
}