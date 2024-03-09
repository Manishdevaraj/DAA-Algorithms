// ADJACENCY MATRIX
#include<iostream>
#include<vector>
using namespace std;
bool issafe(int v,int i,vector<vector<int>>graph,vector<int>color,int n)
{
    for(int k=0;k<n;k++)
    {
        if(graph[v][k]==1&&color[k]==i)return false;
    }
    return true;
}
bool colour(vector<vector<int>>&graph,vector<int>&color,int n,int v,int m)
{
    if(v==n)return true;

    for(int i=1;i<=m;i++)
    {
        if(issafe(v,i,graph,color,n))
        {
            color[v]=i;
            if(colour(graph,color,n,v+1,m))return true;
            color[v]=-1;
        }
    }
    return false;
}
int main()
{
    int n=4,m;
    vector<vector<int>>graph(n,vector<int>(n));
    vector<int>color(n,-1);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
   cin>>m;
   if(colour(graph,color,n,0,m))
   {
    cout<<"Solution Exists:\n";
    for(int i=0;i<n;i++)
    {
        cout<<color[i]<<" ";
    }
   }
   else
   {
    cout<<"No Solution Exists:";
   }
}
