#include<iostream>
#include<vector>
const int INF = 999;

using namespace std;

void floyd(vector<vector<int>>& graph, int n);
int main()
{
    int n, d;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    floyd(graph, n);

    return 0;
}

void floyd(vector<vector<int>>& graph, int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int s = 0;
    int sum = 0;

    for(int i = 1; i < n; i++)
    {
       
            int sd = graph[s][i];
            if(sd == INF)
            {
                cout << "Vertex " << i + 1 << " is not reachable from vertex " << s + 1 << endl;
            }
            else
            {
                sum += sd;
            }
        
    }

    cout << "The sum is " << sum << endl;
}
