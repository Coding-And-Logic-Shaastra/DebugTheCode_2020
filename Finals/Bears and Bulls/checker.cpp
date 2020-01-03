#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
double max_dist=135;
int edit_distance(string a,string b)
{
    int m = a.size();
    int n = b.size();
    int dp[m+1][n+1];
    dp[0][0] = 0;
    int i,j;
    for(i = 1;i <= n;i++)
        dp[0][i] = i;
    for(j = 1;j <= m;j++)
        dp[j][0] = j;
    for(i = 1;i <= m;i++)
    {
        for(j = 1;j <= n;j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        }
    }
    double edit_pct = dp[m][n]/max_dist;
    if(edit_pct <= 0.15)
        return 100;
    else if(edit_pct <= 0.3)
        return 80;
    else if(edit_pct <= 0.5)
        return 60;
    else if(edit_pct <= 0.7)
        return 40;
    else if(edit_pct <= 1.0)
        return 20;
    else
        return 0;

}

int main(void)
{
    string a="#include<bits/stdc++.h>usingnamespacestd;intmain(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);longlongt=1;cin>>t;while(t--){intn;cin>>n;intp;vector<int>edge[n+1];intdepth[n+1]={-1};vector<int>oe[n+1];queue<int>q;for(inti=0;i<n;i++){intx,y;cin>>x>>y;edge[y].push_back(x);oe[x].push_back(x);}introot=-1;for(inti=1;i<n+1;i++){if(oe[i].size()=0)root=i;}q.push(root);depth[root]=1000;while(q.empty()==false){intn1=q.front();for(autoi=edge[n1].begin();i!=edge[n1].end();i++){depth[*i]=depth[n1]+1;q.push(i);}}intans=0;for(inti=0;i<n+1;i++)if(depth[i]>ans)ans=depth[i];cout<<ans<<\'\\n\';}return0;}$";
    char ch;
    string b;
    while(cin>>ch){
        b.push_back(ch);
    }
    cout<<edit_distance(a,b);
    return 0;
}