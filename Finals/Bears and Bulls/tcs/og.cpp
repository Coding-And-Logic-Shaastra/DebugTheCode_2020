#include <bits/stdc++.h>
#define ll long long
#define max(a,b) ((a>b)?a:b)
#define cin f1
#define cout f2
using namespace std;
using namespace std::chrono;
ll timet=0;


fstream f1,f2;
void solve()
{
	int n;
    cin>>n;
    int p;
    vector<int> edge[n+1];
    vector<int> oe[n+1];
    int depth[n+1]={-1};
    queue<int> q;
    for(int i=0;i<n;i++)
    {
    	int x,y;
       	cin>>x>>y;
       	edge[y].push_back(x);
       	oe[x].push_back(y);
    }
    int root=-1;
    for(int i=1;i<n+1;i++)
    {
    	if(oe[i].size()==0)
    		root=i;
    }
    q.push(root);
    depth[root]=0;
    auto start=high_resolution_clock::now();
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
	auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    timet+=duration.count();
    cout<<ans<<'\n';
}

void calc1()
{
	int t;
	cin>>t;
	timet=0;
	while(t--)
	{
		solve();
	}
	printf("%d microseconds\n",timet);
}

int main()
{
    for(int t=0;t<10;t++)
    {
    	string s1="t",s2="o";
        s1+=(t+48);
    	s2+=(t+48);
    	s1+=".txt";
    	s2+=".txt";
    	f1.open(s1,ios::in);
    	f2.open(s2,ios::out);
        calc1();
        f1.close();
        f2.close();
    }
}