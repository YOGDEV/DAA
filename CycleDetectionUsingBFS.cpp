#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Sol
{
 public:
 bool CheckForCycle(int s,int v,vector<int> adj[],vector<int>& visited)
 {
  queue<pair<int,int>> q;
  
  visited[s]=true;
  q.push({s,-1});
  
  while(!q.empty()){
  int node=q.front().first;
  int par=q.front().second;
  q.pop();
  
  for(auto it:adj[node]){
    if(!visited[it]){
    visited[it]=true;
    q.push({it,node});
    }
    else if(par!=it)
    return true;
    
  }
  
  }
  return false;
 }
   
   bool isCycle(int v,vector<int> adj[])
   {
   vector<int> visited(v+1,0);
   for(int i=1;i<=v;i++){
   if(!visited[i]){
    if(CheckForCycle(i,v,adj,visited)) return true;
   }
   }
   return false;
   } 
    
};

int main()
{
Sol s;//object of class Sol...
int v,m;//number of vertices and edges..
cout<<"Enter number of vertices : ";
cin>>v;
cout<<"\nEnter number of Edges ";
cin>>m;
vector<int> adj[v+1];//adjacency list...

for(int i=1;i<=m;i++)//reading edges...
{
int u,v;
cin>>u>>v;
adj[u].push_back(v);
adj[v].push_back(u);
}
 
bool b=s.isCycle(v,adj);//function return's true if cycle exits otherwise false...
if(b==true)
cout<<"\ncycle detected ";
else
cout<<"\ncycle not present";

}    
