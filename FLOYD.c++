#include<iostream>
#include<vector>
int INF=999;
using namespace std;
void floyd(vector<vector<int>>&graph,int d,int n);
int main()
{
    int n,d;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
    cin>>d;
    floyd(graph,d-1,n);


}
void floyd(vector<vector<int>>&graph,int d,int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
     
     if(d>=n)
     {
        cout<<"unknown vertex";
        
     }
     else if(graph[0][d]==INF)
     {
        cout<<"No path from 1 to destination vertex.";
     }
     else
     {
      cout << "Minimum distance to reach " << d + 1 << " from 1 is " << graph[0][d]; 
     }
}