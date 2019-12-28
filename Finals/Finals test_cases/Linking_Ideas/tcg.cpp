#include <bits/stdc++.h>
#define ll long long
#define RAND(x,y) x+(rand()%(y-x+1))

using namespace std;
int main()
{
    srand(time(0));
    ll times=10;
    for(ll times=0;times<10;times++)
    {
        string sname="t";
        sname+=(times+48);
        sname+=".txt";
        fstream f(sname,ios::out);
        ll t=RAND(1,1000);
        f<<t<<endl;
        while(t--)
        {
        	ll n=RAND(1,20);
        	f<<n<<endl;
            f<<RAND(1,9)<<" ";
        	for(long long i=1;i<n;++i)
        		f<<RAND(0,9)<<" ";
            f<<'\n';
        }
        f.close();
    }
    return 0;
}