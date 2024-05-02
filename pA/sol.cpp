#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n,d;
    ll cnt = 0;
    cin >> n >> d;
    while(n--){
        ll x;
        cin >> x;
        set<ll> s;
        while(!s.count(x)){
            cnt++;
            s.insert(x);
            string a;
            while(x){
                a.push_back('0'+x%10);
                x/=10;
            }
            while(a.size()<d) a.push_back('0');
            sort(a.begin(),a.end());
            ll u = stoll(a);
            reverse(a.begin(),a.end());
            ll v = stoll(a);
            x = v-u;
        }
        cout << x << "\n";
    }
    assert(cnt <= 100000);
}
