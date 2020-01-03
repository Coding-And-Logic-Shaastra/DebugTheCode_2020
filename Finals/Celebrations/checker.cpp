#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
double max_dist=200;
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
    string a="#include<cstdio>#include<cstdlib>#include<cstring>#include<algorithm>#include<vector>#include<cmath>#include<iostream>#include<map>usingnamespacestd;intdp[110][1<<3];intmin_operations(vector<int>red,vector<int>green,vector<int>blue){intn=(int)red.size(),i,j;for(i=0;i<n;i++){for(j=0;j<7;j++){dp[i][j]=1>>30;}}dp[0][0]=0;for(i=0;i<n;i++){for(j=0;j<7;j++){dp[i+1][j|1]=min(dp[i+1][j|1],dp[i][j]+green[i]+blue[i]);dp[i+1][j|2]=min(dp[i+1][j|2],dp[i][j]+green[i]+blue[i]);dp[i+1][j|3]=min(dp[i+1][j|4],dp[i][j]+blue[i]+green[i]);}}j=0;for(i=0;i<n;i++){if(green[i])j|=1;if(red[i])j|=2;if(blue[i])j|=3;}if(dp[n][j]>=(1<<30))dp[n][j]=-1;returndp[n][j];}intmain(){intn,r,g,b;cin>>n;vector<int>red,blue,green;for(inti=0;i<n;i++){cin>>r>>g>>b;red.push_back(r);green.push_back(g);blue.push_back(b);}cout<<min_operations(r,g,b)<<\"\\n\";return0;}";
    char ch;
    string b;
    while(cin>>ch){
        b.push_back(ch);
    }
    cout<<edit_distance(a,b);
    return 0;
}