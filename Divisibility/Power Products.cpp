#include <bits/stdc++.h>
using namespace std;
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
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
 
const ll INF = 1e15+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;
 
int n, k;ull ans = 0; map<ull, int> m;
 
int main(){
    inputJunk
 
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        ull x; cin>>x;
        ull need = 1, have = 1;
        for(int i = 2;i*i<=x;i++){
            int cnt=0;
            while(x%i==0){
                x/=i;
                cnt++;
            }
            cnt%=k;
            if(cnt==0)continue;
            for(int j = 0;j<k-cnt;j++){
                need*=i;
            }
            for(int j = 0;j<cnt;j++){
                have*=i;
            }
        }
        if(x>1){
            for(int i = 0;i<k-1;i++){
                need*=x;
            }
            have*=x;
        }
        //cout<<need<<" "<<m[need]<<ell<<have<<" "<<m[have]<<ell;
        ans+=m[need];
        m[have]++;
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
- upperbound and lowerbound returns iterators
- use long long when number is big enough
*/
 
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
 
