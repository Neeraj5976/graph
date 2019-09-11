#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(int start, vector<int>* edges, int n, unordered_set<int>& visited, unordered_set<int> * component) {
	visited.insert(start);
	component->insert(start);
	vector<int>::iterator it = edges[start].begin();
	for (;it != edges[start].end(); it++) {
		int i = *it;
		if (visited.count(i) > 0) {
			continue;
		}
		dfs(i, edges,n, visited, component);
	}
}

unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n) {
	unordered_set<int> visited;
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			unordered_set<int> * component = new unordered_set<int>();
			dfs(i, edges,n, visited, component);
			output->insert(component);
		}
	}
	return output;
}

int main() {
    int t,n;
    int m;
    cin>>t;
    while(t--){
	cin >> n>>m;
     int *p=new int[n];
     int *q=new int[n];
     for(int i=0;i<n;i++)
         cin>>p[i];
     for(int j=0;j<n;j++)
         cin>>q[j];
	vector<int>* edges = new vector<int>[n];
	for (int i = 0; i < m; i++) {
		int j, k;
		cin >> j >> k;
		edges[j - 1].push_back(k - 1);
		edges[k - 1].push_back(j - 1);
	}
	unordered_set<unordered_set<int>*>* components = getComponents(edges, n);    
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
    unordered_set<unordered_set<int>*>* set_p = new unordered_set<unordered_set<int>*>();  
  unordered_set<unordered_set<int>*>* set_q = new unordered_set<unordered_set<int>*>();  
	while (it != components->end()) {
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
        unordered_set<int> *p1 = new unordered_set<int>();
        unordered_set<int> * q1 = new unordered_set<int>();
		while (it2 != component->end()) {
		   p1->insert(p[*it2]);
		    q1->insert(q[*it2]);
            it2++;
		}
        set_p->insert(p1);
		set_q->insert(q1);
		delete component;
		it++;
	}
     bool flag=true;
        unordered_set<unordered_set<int>*>::iterator it_p=set_p->begin();
        unordered_set<unordered_set<int>*>::iterator it_q=set_q->begin();
      while (it_p != set_p->end()) {
		unordered_set<int>* set1 = *it_p;
         unordered_set<int>* set2 = *it_q; 
		unordered_set<int>::iterator it_sp = set1->begin();
        unordered_set<int>::iterator it_sq = set2->begin();
		while (it_sp != set1->end()) {
		   if(*it_sp!=*it_sq)
		      flag=false;
		    it_sp++;
            it_sq++;
		}
		delete set1;
		delete set2;
		it_p++;
		it_q++;
	}  
	if(flag)
	   cout<<"YES";
	else
	   cout<<"NO";
	   cout<<endl;
	delete components;
	delete edges;
   }
}






