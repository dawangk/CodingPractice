#include <bits/stdc++.h>
using namespace std;
//#include <ext/rope>
//using namespace __gnu_cxx;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<int, pi> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
typedef vector<tripll> vtripll;

const ll INF = 1e17+1212;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;//99824435

int n;

template <class T> using Tree = tree<T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update>;

bool compare(int a, int b){
    if(b>a)swap(a,b);
    return (a>2*b);
}

int main(){
    inputJunk
    freopen("bphoto.in","r", stdin);
    freopen("bphoto.out","w", stdout);
    cin>>n; vi arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    vi l(n), r(n);
    Tree<pi> t1, t2;
    for(int i = 0;i<n;i++){
        l[i]+=(i-t1.order_of_key({arr[i], mod}));
        t1.insert({arr[i],i});
    }

    for(int i = n-1;i>=0;i--){
        r[i]+=(n-1-i-t2.order_of_key({arr[i], -mod}));
        t2.insert({arr[i],i});
    }

    //for(int i = 0;i<n;i++){
    //    cout<<l[i]<<" ";
    //}cout<<ell;
    //for(int i = 0;i<n;i++){
    //    cout<<r[i]<<" ";
    //}cout<<endl;
    int ans = 0;
    for(int i = 0;i<n;i++){
        if(compare(l[i], r[i]))ans++;
    }
    cout<<ans<<ell;
}
/*CUSTOM TEST CASE 1
*/

/*CUSTOM TEST CASE 2
*/

/*CUSTOM TEST CASE 3
*/

/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iteratorsf
- use long long when number is big enough
- for dp invalid cases needs to be skipped
- some base cases won't work (review cow poetry)
- always check bounds, some TLE are due to incorrect bounds!
- dont mess up return types
= RESET ARRAYS!!!!!!!!!!
- USE UR BRAIN
- INF setting problems
- push vs pb
- check if things are used properly
- read the PROBLEM (directed vs undirected graph)
*/
/*
    freopen("time.in","r", stdin);
    freopen("time.out","w", stdout);
*/
