#include <bits/stdc++.h>
using namespace std;
void dfs1(vector<int> *edges,int start,bool *visited,stack<int> &sq){
       visited[start]=true;
       for(int i=0;i<edges[start].size();i++){
            int next=edges[start][i];
            if(!visited[next]) dfs1(edges,next,visited,sq);
       }
       sq.push(start);
}
void dfs2(vector<int> *edgesT,int start,bool *visited,unordered_set<int> *component){
    visited[start]=true;
    component->insert(start);
    for(int i=0;i<edgesT[start].size();i++){
            int next=edgesT[start][i];
               if(!visited[next]) 
                   dfs2(edgesT,next,visited,component);
    }
               
}
unordered_set<unordered_set<int>*>* getComponent(vector<int> *edges,vector<int> *edgesT,int n){
       stack<int> sq;
       bool *visited=new bool[n];
       for(int i=0;i<n;i++)
            visited[i]=false;
         for(int i=0;i<n;i++)
            if(!visited[i])
                 dfs1(edges,i,visited,sq);
        unordered_set<unordered_set<int>*> *output=new unordered_set<unordered_set<int>*>();
       for(int i=0;i<n;i++)
            visited[i]=false;
        while(sq.size()!=0){
            int current=sq.top();
            sq.pop();
            if(visited[current]) continue;
            unordered_set<int> *component=new unordered_set<int>();
            dfs2(edgesT,current,visited,component);
            output->insert(component);
        }
    return output;
}

int main() {
	int n,m;
	cin>>n>>m;
	vector<int> *edges=new vector<int>[n];
	vector<int> *edgesT=new vector<int>[n];
	for(int i=0;i<m;i++){
	    int j,k;
	    cin>>j>>k;
	    edges[j-1].push_back(k-1);
	    edgesT[k-1].push_back(j-1);
	}
	unordered_set<unordered_set<int>*> *storglyCompo=getComponent(edges,edgesT,n);
	unordered_set<unordered_set<int>*>::iterator it=storglyCompo->begin();
	while(it!=storglyCompo->end()){
	    unordered_set<int> *component=*it;
	    unordered_set<int>::iterator it1=component->begin();
	    while(it1!=component->end()){
	         cout<<*it1+1<<" ";
	         it1++;
	    }
	    cout<<endl;
	    it++;
	}
	return 0;
}