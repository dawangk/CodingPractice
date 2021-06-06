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
const ll MM = 2e5+5; ull mod = 1e9+7;
 
int n;
ull modexp(ull a, ull b, ull mod){
    if(b==0)return 1;
    if(a==0)return 0;
    ull basek = a;
    ull exp = 1;
    ull num = 1;
    while(b!=0){
        if((b&exp)!=0){
            num*=basek;num%=mod;
 
            b-=(b&exp);
        }
        basek*=basek;basek%=mod;
        exp*=2;exp%=mod;
    }
    return num%mod;
}
 
ull exp(ull a, ull b){
    if(b==0)return 1;
    if(a==0)return 0;
    ull basek = a;
    ull exp = 1;
    ull num = 1;
    while(b!=0){
        if((b&exp)!=0){
            num*=basek;num%=mod;
 
            b-=(b&exp);
        }
        basek*=basek;basek%=mod;
        exp*=2;exp%=mod;
    }
    return num%mod;
}
bool isPrime(ull n){
    for(int i = 2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    inputJunk
    //freopen("diamond.in","r", stdin);
    //freopen("diamond.out","w", stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        ull a, b,c;cin>>a>>b>>c;
        ull bpc = modexp(b,c, mod-1);
        ull apbpc = exp(a, bpc);
        cout<<apbpc<<ell;
    }
}
