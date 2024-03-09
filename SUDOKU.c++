#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
void print(vector<vector<int>>board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool issafe(int i,int j,vector<vector<int>>board,int n,int num)
{
    for(int k=0;k<n;k++)
    {
        if(board[i][k]==num)return false;
        if(board[k][j]==num)return false;
    }

    int s=3; 
    int s_row=i-i%s;
    int s_col=j-j%s;
    for(int r=s_row;r<s_row+s;r++)
    {
        for(int c=s_col;c<s_col+s;c++)
        {
            if(board[r][c]==num)return false;
        }
    }
 
    return true;
}

bool solvesudoku(vector<vector<int>>&board,int n)
{
    int i,j;
    bool flag=false;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(board[i][j]==0)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            break;
            }
    }
    if(i==n&&j==n)return true;

    for(int num=1;num<=n;num++)
    {
        if(issafe(i,j,board,n,num))
        {
            board[i][j]=num;
            if(solvesudoku(board,n)) 
            {
                return true;
            }       
            board[i][j]=0;
        }
    }
    return false;

}
int main()
{
    int n=9;
    
    vector<vector<int>>board(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }
   
   if(solvesudoku(board,n))
   {
    cout<<"\n\n";
    print(board);
   }
   else
   {
    cout<<"no solution exists";
   }
}