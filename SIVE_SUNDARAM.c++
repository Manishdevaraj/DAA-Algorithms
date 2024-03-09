#include<iostream>
using namespace std;
void su(int n)
{
    int nnew=(n-1)/2;
    bool marked[nnew+1];
    for(int i=0;i<sizeof(marked);i++)
    {
        marked[i]=false;
    }

    for(int i=1;i<=nnew;i++)
    {
        for(int j=i;(i+j+2*i*j)<=nnew;j++)
        {
            marked[i+j+2*i*j]=true;
        }
    }
    if(n>2)
    {
        cout<<"2 ";
    }
    for(int i=1;i<=nnew;i++)
    {
        if(marked[i]==false)
        {
            cout<<2*i+1<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    su(n);
}