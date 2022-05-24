#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}

//bfs
void bfs(int s,vector<int>adj[],bool visit[]){
  queue<int>q;//queue in STL
  q.push(s);
  visit[s]=true;
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
//traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
//dfs traversal
void dfs(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;//stack in STL
  stk.push(s);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
//traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
int main(){
  vector<int>adj[7];
  bool visit[7];
  
  for(int i=0;i<7;i++){
    visit[i]=false;
  }
 
  edge(adj,1,2);
  edge(adj,1,3);
  edge(adj,3,6);
  edge(adj,2,4);
  edge(adj,2,5);
  cout<<"BFS traversal is"<<"  ";
  
  bfs(1,adj,visit);
  cout<<endl;
  
  for(int i=0;i<7;i++){
    visit[i]=false;
  }
  cout<<"DFS traversal is"<<"  ";
  
  dfs(1,adj,visit);//1 is a starting point
}

