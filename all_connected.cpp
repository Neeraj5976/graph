#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> *edges,int start,unordered_set<int> *component,bool *visited){
          visited[start]=true;
          component->insert(start);
          for(int i=0;i<edges[start].size();i++){
              int next=edges[start][i];
                if( !visited[next]){
                    // cout<<start<<endl;
                      dfs(edges,next,component,visited);  
                }
                     
             } 
             
}
unordered_set<unordered_set<int>*>* getComponent(vector<int> *edges,int n){
      bool *visited=new bool[n]();
      for(int i=0;i<n;i++)
          visited[i]=false;
      unordered_set<unordered_set<int>*> *output=new unordered_set<unordered_set<int>*>();
      for(int i=0;i<n;i++)
          if(!visited[i]){
              unordered_set<int> *component=new unordered_set<int>();
              dfs(edges,i,component,visited);
              output->insert(component);
           delete component;
          }
      delete []visited;      
    return output;  
}
int main() {
	int n,m;
	cin>>n>>m;
	vector<int> *edges=new vector<int>[n];
	for(int i=0;i<m;i++){
	    int s,e;
	    cin>>s>>e;
	    edges[s-1].push_back(e-1);
	    edges[e-1].push_back(s-1);
	}
	unordered_set<unordered_set<int>*> *connected_compo=getComponent(edges,n);
	unordered_set<unordered_set<int>*>::iterator it1=connected_compo->begin();
	while(it1!=connected_compo->end()){
	    unordered_set<int> *component=*it1;
	    unordered_set<int>::iterator it2=component->begin();
	    while(it2!=component->end()){
	        cout<<*it2+1<<" ";
	        it2++;
	    }
	    cout<<endl;
	    it1++;
	    delete component;
	}
  delete []edges;
  delete connected_compo;
	return 0;
}