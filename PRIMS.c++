#include<iostream>
#include<vector>
#include<climits>
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
void findMST(int v,int graph[100][100])
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
        cout<<parent[i]<<" "<<i<<" "    <<graph[parent[i]][i]<<endl;
    }
}
int main()
{
    int graph[100][100];
    int v;
    cin>>v;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>graph[i][j];
        }
    }
    findMST(v,graph);
}