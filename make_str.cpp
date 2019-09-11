#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007;
int main() {
	int t,n;
	int k;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    char group[k];
	    /*for(int i=0;i<k;i++)
	       cin>>group[i];*/
	   ll ans1=1;
	   ll ans2=1;
	   for(int i=0;i<n/2;i++){
	       ans1=(ans1*k)%MOD;
	       ans2=(ans2*(26-k))%MOD;
	   }
	   ans1=(ans1*ans2)%MOD;
	   ll ans=0;
	   if(n%2!=0) {
	       ans1=(ans1*k)%MOD;
	   }
	   ans2=1;
	   if(n!=1){
	       for(int i=0;i<n-1;i++)
	         ans2=(ans2*(k-1))%MOD;
	       ans2=(ans2*k)%MOD;
	      ans+=ans2;  
	    }
	   ans=(ans+ans1)%MOD;
	   cout<<ans;
	}
	return 0;
}