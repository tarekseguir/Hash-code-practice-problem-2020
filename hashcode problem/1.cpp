#include <bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<long long, long long> ii; 
typedef vector<ii> vii;  
typedef vector<ll> vi;
#define endl "\n"
#define f first
#define s second 
#define pb push_back
#define pob pop_back
#define mp make_pair
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void arrayIn(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cin >> A[K]; } }
void arrayOut(ll* A,ll n){ for ( ll K = 0; K < n; K++){ cout << A[K]<<' '; } }
//declare variable----------------------------------------------------


string input[] = {"a_example.in", "b_small.in", "c_medium.in", "d_quite_big.in", "e_also_big.in"}, output[] = {"a_example.out", "b_small.out", "c_medium.out", "d_quite_big.out", "e_also_big.out"} ;


pair<int,stack<int>> f(int i, int m, int s, int hs, int *a, stack<int> st, stack<int> hst){
	if(i<0){
		if(s>hs){
			hs = s;
			hst.swap(st);
			return make_pair(hs,hst);
		}
		return make_pair(hs,hst);
	}
	if(s + a[i] == m){
		st.push(i);
		return make_pair(s+a[i],st);
	}
	else if(s+a[i]>m){
		return f(i-1,m,s,hs,a,st,hst);
	}
	else{
		st.push(i);
		pair<int,stack<int>> p1 = f(i-1,m,s + a[i], hs, a,st,hst);
		if(p1.f == m){
			return p1;
		}
		st.pop();
		pair<int,stack<int>> p2 = f(i-1,m,s, hs, a,st,hst);
		if(p2.f == m){
			return p2;
		}
		if(p2.f>p1.f) return p2;
		else return p1;
	}
}

//--------------------------------------------------------------------------
int main(){
	FASTIO;
	
	// CODE----------------------------------------------------------------------------------------
	for(int k=0;k<5;k++ ){
		ifstream cin(input[k], std::ios::binary ) ;
		ofstream cout( output[k], std::ios::binary ) ;
		//-----------------------------------------------------------------------------------------
		int m,n, a[200000];
		cin>>m;
		cin>>n;
		for ( ll i = 0; i < n; i++){ cin >> a[i]; }
		stack<int> hst,st;
		pair<int,stack<int>> ans = f(n-1,m,0,0,a,st,hst);
		cout<<ans.s.size()<<'\n';
		ll l[200000];
		
		while(!ans.s.empty()){
			cout << ans.s.top() << ' ';
			ans.s.pop();
		}
	}

//---------------------------------------------------------------------
	return 0;
}