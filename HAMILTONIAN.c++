#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>>graph,vector<int>path,int pos,int v)
{
    if(graph[path[pos-1]][v]==0)return false;
    for(int k=0;k<pos;k++)
    {
        if(path[k]==v)return false;
    }
    return true;
}
bool solve(vector<vector<int>>&graph,vector<int>&path,int n,int pos)
{
    if(pos==n)return true;

    for(int v=0;v<n;v++)
    {
        if(issafe(graph,path,pos,v))
        {
            path[pos]=v;
            if(solve(graph,path,n,pos+1))return true;
            path[pos]=-1;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    vector<int>path(n,-1);
    path[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    if(solve(graph,path,n,1))
    {
        for(int i=0;i<n;i++)
        {
            cout<<path[i]<<" ";
        }
        cout<<path[0];
    }
    else
    {
        cout<<"no solution";
    }

}

