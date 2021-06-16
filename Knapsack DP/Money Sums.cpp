#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
 
const ll INF = 1e15+1;
const int MM = 1e5+5; ull mod = 1e9+7;
 
int n; set<int> s;
 
int main(){
    inputJunk
    cin>>n;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k; vector<int>v;
 
        for(int x: s){
            v.pb(k+x);
        }
        for(int x:v){
            s.insert(x);
        }
        s.insert(k);
    }
    cout<<s.size()<<ell;
    for(int x: s){
        cout<<x<<" ";
    }cout<<ell;
}
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
