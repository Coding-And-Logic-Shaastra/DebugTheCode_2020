#include <bits/stdc++.h>
#define ll long long
#define RAND(x,y) x+(rand()%(y-x+1))

using namespace std;
int main()
{
    srand(time(0));
    ll times=10;
    for(ll times=0;times<1;times++)
    {
        ll t=1;
        cout<<t<<endl;
        while(t--)
        {
        	ll n=6;
        	cout<<n<<endl;
        	int a[n];
        	for(ll i=0;i<n;i++)
        		a[i]=i+1;
        	vector<pair<ll,ll>> e;
        	for(ll i=0;i<n;i++)
        	{
        		ll p=RAND(0,i-1);
        		e.push_back(make_pair(i,p));
        	}
        	random_shuffle(a,a+n);
        	for(auto i:e)
        		cout<<a[i.first]<<" "<<a[i.second]<<endl;
        }
    }
    return 0;
}