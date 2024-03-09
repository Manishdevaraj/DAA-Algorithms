#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int minkey(vector<bool>&setmst,vector<int>&value,int v)
{
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<v;i++)
    {
       if(setmst[i]==false&&value[i]<min)
       {
        vertex=i;
        min=value[i];
       }
    }
    return vertex;
}
void primeMST(int graph[100][100],int v)
{
    vector<bool>setmst(v,false);
    vector<int>value(v,INT_MAX);
    int parent[v];
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<v-1;i++)
    {
        int u=minkey(setmst,value,v);
        setmst[u]=true;
        for(int j=0;j<v;j++)
        {
            if(graph[u][j]!=0&&graph[u][j]<value[j]&&setmst[u]==false)
            {
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
}
int main()
{
    int graph[100][100];
    int v;
    cin>>v;
    primeMST(graph,v);
}