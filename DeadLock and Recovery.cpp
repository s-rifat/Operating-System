#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
map<int,string>m2;
vector<int> V[100],d;
int color[100],cnt;
stack<int>s;
void DFS(int u)
{
    color[u] = 1;
    d.push_back(u);
    for(int i=0;i<V[u].size();i++)
    {
        int v = V[u][i];
        if( color[v]==0 )
            DFS(v);
        else if ( color[v]==1)
        {
            cnt++;
            for(int i= d.size()-1;i>=0;i--)
            {
                s.push(d[i]);
                if(d[i]==v)
                    break;
            }
            cout<<"cycle "<<cnt<<":"<<endl;
            while(!s.empty())
            {
                cout<<m2[s.top()]<<" ";
                s.pop();
            }
            cout<<endl;
            ///recovery from a deadlock
            vector<int> v2;
            for(int i=0;i<V[u].size();i++)
            {
                if(V[u][i]!=v)
                v2.push_back(V[u][i]);
            }
            V[u].clear();
            for(int i=0;i<v2.size();i++)
            {
                V[u].push_back(v2[i]);
            }
        }
    }
    d.pop_back();
    color[u] = 2;
}
int main()
{
    cout<<"Number of nodes: "<<endl;
    int n;
    cin>>n;
    cout<<"Node names: "<<endl;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        m[s] = i;
        m2[i] = s;
    }
    cout<<"Number of edges: "<<endl;
    int E;
    cin>>E;
    cout<<"Edges: "<<endl;
    for(int i=0;i<E;i++)
    {
        string u,v;
        cin>>u>>v;
        V[m[u]].push_back(m[v]);
    }
    for(int i=0;i<n;i++)
        if(color[i]==0)
            DFS(i);
    ///checking recovery
    cout<<"checking 2nd time: "<<endl;
    d.clear();
    for(int i=0;i<n;i++)
        color[i] = 0;
    for(int i=0;i<n;i++)
        if(color[i]==0)
            DFS(i);
    return 0;
}
/*
7
1 2 3 4 5 6 7
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
