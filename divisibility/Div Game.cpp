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
const int MM = 2e5+5, mod = 1e9+7;
 
ll n, cnt = 0; map<ll, ll> freq;
 
int main(){
    inputJunk
    cin>>n;
    ll cp = n;
    for(int i = 2;i<=sqrt(cp);i++){
        while(n%i==0){
            n/=i;
            freq[i]++;
        }
        if(n==1)break;
    }
    if(n!=1){
        freq[n]++;
    }
 
    for(auto it = freq.begin(); it!=freq.end();it++){
        int val = it->s;
        int i = 1;
        while(val>=0){
            val-=i;i++;
            if(val<0){break;}
            cnt++;
        }
    }
    cout<<cnt<<ell;
}
//freopen("convention2.in","r", stdin);
//freopen("convention2.out","w", stdout);
