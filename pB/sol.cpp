#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll m,n,k,r,e;
    cin >> m >> n >> e >> k >> r;
    vector<ll> c(e);
    for(ll &i : c) cin >> i;
    ll low = max(1ll,r-k+1);
    ll high = min(m-k+1,r);
    ll dh = high-low+1;
    ll ans = 0;
    vector<ll> v; // 收集關鍵點
    for(ll i : c){
        v.push_back(i);
        v.push_back(i+k);
    }
    v.push_back(k);
    v.push_back(n+1);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    v.erase(upper_bound(v.begin(),v.end(),n+1),v.end()); // 前面不檢查，在這裡刪掉超出去的
    v.erase(v.begin(),lower_bound(v.begin(),v.end(),k));
    for(ll i = 0;i<v.size()-1;i++){
        ll width = v[i+1]-v[i]; // k*k框框最右方點，左閉右開，1-base
        ll L = v[i]-k+1;
        ll R = v[i];
        ll cur = upper_bound(c.begin(),c.end(),R) - lower_bound(c.begin(),c.end(),L);
        if(cur&1) ans+=width;
    }
    ans*=dh;
    if(k&1) ans = (m-k+1)*(n-k+1) - ans;
    cout << ans << "\n";
}
