#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int p;
        vector<int> edge[n+1];
        int depth[n+1]={-1};
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            cin>>p;
            if(p!=-1)
                edge[p].push_back(i+1);
            else
            {
                q.push(i+1);
                depth[i+1]=1;
            }
        }
        while(q.empty()==false)
        {
            int n1=q.front();
            q.pop();
            for(auto i=edge[n1].begin();i!=edge[n1].end();i++)
            {
                depth[*i]=depth[n1]+1;
                q.push(*i);
            }
        }
        int ans=0;
        for(int i=0;i<n+1;i++)
            if(depth[i]>ans)
                ans=depth[i];
        cout<<ans<<'\n';
    }
    return 0;
}