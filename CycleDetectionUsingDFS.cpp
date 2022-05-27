#include<bits/stdc++.h>
using namespace std;

bool CheckForCycle(int node,int par,vector<int> adj[],vector<int>& vis)
{
    vis[node]=true;
    for(int it:adj[node])
    {
        if(!vis[it])
        {
         if(CheckForCycle(it,node,adj,vis)) return true;//if this component have cycle then it will return true
        }
        else if(par!=it)
        return true;
    }
    return false;//if this component have do not have a cycle then it will return false
}

bool isCycle(int v,vector<int> adj[])
{
    vector<int> vis(v+1,0);
    for(int i=1;i<=v;i++)//iterating to every vertex of graph ,whether connwcted or not
    {
        if(!vis[i])
        {
            if(CheckForCycle(i,-1,adj,vis)) return true;
        }
    }
    return false;
}

int main()
{   int t;
    cin>>t;
    while(t--){
    int v;
    cout<<"\nEnter number of vertices : ";
    cin>>v;
    int m;
    cout<<"\nEnter number of edges : ";
    cin>>m;
    cout<<"\nReading adjacency list\n";
    std::vector<int>adj[v+1] ;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(v,adj))
    cout<<"\ntrue";
    else
    cout<<"\nfalse";
    }
    return 0;
}
