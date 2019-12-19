#include <bits/stdc++.h>

#define num 1000000007
#define formn(i,m,n) for(i=m;i<n;i++)
#define forn(i,n) for(i=0;i<n;i++)
#define fmno(i,m,n,o) for(i=m;i<n;i+=o)
#define ll long long

using namespace std;


int main() {
    long long i=0,j,k,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        k=0;
        vector<string> a(n);
        vector<ll> f;
        set<string> b;
        ll lol=-1;
        forn(i,n)
        {
            cin>>a[i];
            b.insert(a[i]);
            if(b.size()==lol)
            {
                f.push_back(i);
            }
            lol=b.size();
        }
        ll ini=b.size();
        k = f.size();
        forn(ini,k)
        {
            i=b.size();
            char ch='0';
            while(b.size()<=i)
            {
                a[f[ini]][3]= ch;
                b.insert(a[f[ini]]);
                ch = ch + 1;
                //cout<<ch;
            }
        }
        cout<<k<<'\n';
        forn(i,n)
        {
            cout<<a[i]<<" ";
        }
        cout<<'\n';

    }
    
    return 0;
}
