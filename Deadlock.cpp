#include<bits/stdc++.h>
using namespace std;
vector<int> V[100],d;
int color[100],cnt = 0;
stack<int>s;
void DeadLockDetect(int u)
{
    color[u] = 1;
    d.push_back(u);
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if(color[v]==0)
            DeadLockDetect(v);
        else if ( color[v]==1)
        {   cnt++;
            for(int i= d.size()-1;i>=0;i--)
            {
                s.push(d[i]);
                if(d[i]==v)
                    break;
            }
            cout<<"cycle "<<cnt<<":"<<endl;
            while(!s.empty())
            {
                cout<<s.top()<<" ";
                s.pop();
            }
            cout<<endl;
        }
    }
    d.pop_back();
    color[u] = 2;
}
int main()
{
    int n,E,u,v;
    cin>>n>>E;
    for(int i=0;i<E;i++)
    {
        cin>>u>>v;
        V[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(color[i]==0)
            DeadLockDetect(i);
    return 0;
}
/*
7
8
1 2
2 3
3 1
2 4
4 5
5 6
6 7
7 5
*/
