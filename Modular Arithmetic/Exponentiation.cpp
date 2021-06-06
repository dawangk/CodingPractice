#include <bits/stdc++.h>
using namespace std;
#define inputJunk cin.sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
 
const int INF = 0x3f3f3f3f;
const ll MM = 2e5+5, mod = 1e9+7;
 
int n;
 
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        ll a, b;cin>>a>>b; ll basek = a;
        ll exp = 1;
        a = 1;
        while(b!=0){
            if((b&exp)!=0){
                a*=basek;a%=mod;
 
                b-=(b&exp);
            }
            basek*=basek;basek%=mod;
            exp*=2;exp%=mod;
        }
        cout<<a<<ell;
    }
}
