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