#include<bits/stdc++.h>
using namespace std;
class solution {
    private:
 bool dfs(int node,vector<int> adj[],int vis[],int pathvis[]){
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathvis)==true)return true;

            }
            else if(pathvis[it])
            return true;
        }

     pathvis[node]=0;
    return false;
 }
public:
    bool cycle(int v,vector<int> adj[]){
        int vis[v]={0};
        int pathvis[v]={0};
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,pathvis)==true) return true;
            }
        }

        return false;
    }


};
int main(){
    vector<int> adj[11]={{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    int v=11;
    solution obj;
    bool  ans=obj.cycle(v,adj);

    if(ans) 
       cout<<" true";
     else cout<<"false";
    return 0;
}
