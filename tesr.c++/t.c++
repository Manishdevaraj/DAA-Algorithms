#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int minkey(vector<bool>&setmst,vector<int>&value,int v)
{
    int vertex;
    int min=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(setmst[i]==false&&min>value[i])
        {
            min=value[i];
            vertex=i;
        }
    }
    return vertex;
}
void prims(vector<vector<int>>&graph,int v)
{
    int parent[v];
    vector<int>value(v,INT_MAX);
    vector<bool>setmst(v,false);
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<v-1;i++)
    {
        int u=minkey(setmst,value,v);
        setmst[u]=true;
        for(int j=0;j<v;j++)
        {
            if(graph[u][j]!=0&&graph[u][j]<value[j]&&setmst[j]==false)
            {
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }

    for(int i=1;i<v;i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<graph[parent[i]][i]<<endl;
    }
}
int main()
{
   int n;
   cin>>n;
   vector<vector<int>>graph(n,vector<int>(n));
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        cin>>graph[i][j];
    }
   }
   prims(graph,n);
}