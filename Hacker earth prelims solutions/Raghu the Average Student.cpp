#include <bits/stdc++.h>

using namespace std;

int main() {
    long long i=0,j,k,m,t,n;
    cin>>t;
    while(t--)
    {
        long long start=-1,end=-1;
        cin>>m;
        cin>>n;
        vector<long long> a(n);
        for(i=0;i<n;++i)
        {
            cin>>a[i];
        }
        i=j=k=0;
        for(j=0;j<n&&k<m;++j)
        {
            k+=a[j];
            if(k==m)
            {
                start=i+1;
                end=j+1;
                break; 
            }
        }
        for(i=0;i<n;++i)
        {
            k-=a[i];
            while(k<m)
            {
                k+=a[j];
                ++j;
            }
            if(k==m)
            {
                start=i+1;
                end=j+1;
                break;
            }
        }
        cout<<start<<" "<<end<<'\n'; 
    }
    
    return 0;
}
