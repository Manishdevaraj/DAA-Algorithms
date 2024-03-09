// ADJACENCY LIST

#include<iostream>
#include<vector>
using namespace std;
void addedge(int a,int b,vector<vector<int>>&graph)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}
bool issafe(int v, int i, vector<vector<int>>& graph, vector<int>& color, int n) {
    for (int k : graph[v]) {
        if (color[k] == i)
            return false;
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
    int v,e,a,b,m;
    cin>>v>>e;
    vector<int>color(v,-1);
    vector<vector<int>>graph(v,vector<int>(v));
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        addedge(a,b,graph);
    }
     cin>>m;
   if(colour(graph,color,v,0,m))
   {
    cout<<"Solution Exists:\n";
    for(int i=0;i<v;i++)
    {
        cout<<color[i]<<" ";
    }
   }
   else
   {
    cout<<"No Solution Exists:";
   }

}