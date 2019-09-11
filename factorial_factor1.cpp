#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 500001
#define pb push_back
#define MOD  1000000007
vector<int>* sieve(){
    bool *arr=new bool[MAX];
    vector<int>* v=new vector<int>();
    for(int i=2;i<MAX;i++)
       arr[i]=true;
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<MAX;i++){
          if(arr[i]){
              for(int j=i*i;j<MAX;j+=i)
                    arr[j]=false;
          }
    }
    v->pb(2);
    for(int i=3;i<MAX;i+=2)
         if(arr[i])
            v->pb(arr[i]);
            
    return v;
}
ll find_diviser(int n,vector<int>* &v){
     ll total=1;
     for(int i=0;v->at(i)<=n;i++){
         int x=v->at(i);
         ll count=0;
         int curr_n=n;
         while(curr_n!=0){
             count=(count+((ll)(n/x))%MOD)%MOD;
             x=x*v->at(i);
             curr_n=curr_n/x;
         }
         total=(total * ((count+1)%MOD))%MOD;
     }
     return total;
}
int main() {
	vector<int>* v=sieve();
	int n;
	cin>>n;
    cout<<find_diviser(n,v);
	return 0;
}