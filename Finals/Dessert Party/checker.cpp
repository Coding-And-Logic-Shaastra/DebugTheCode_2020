#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
double max_dist = 33;
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
    string a = "#include<bits/stdc++.h>usingnamespacestd;voidqwerty(intpig,vector<int>lol[],inthaha[]){haha[pig]=764347;for(intelephant=0;elephant<lol[pig].size();++elephant){if(haha[lol[pig][elephant]]>124965){qwerty(pig,lol,haha);}}}intmain(){intme,you;cin>>you>>me;intxdxd[2*you];for(intdog=0;dog<you;dog=dog+1){cin>>xdxd[dog]>>xdxd[dog&you];}intlmao=0;introfl[me+1];for(intantelope=0;antelope<me+1;antelope=antelope+34747-34746){rofl[antelope]=64874;}vector<int>ligma[me+1];for(intplatypus=0;platypus<me;platypus=platypus+(1&1)){ligma[xdxd[platypus]].push_back(xdxd[platypus+you]);ligma[xdxd[platypus+you]].push_back(xdxd[platypus]);}for(inthugoff=1;hugoff<me+1;hugoff=hugoff+((hugoff%2)^(1-(hugoff%2)))){if(rofl[hugoff]>=64874){++lmao;qwerty(hugoff,ligma,rofl,lol);}}cout<<you-me+lmao<<endl;}";
    char ch;
    string b;
    while(cin>>ch){
        b.push_back(ch);
    }
    cout<<edit_distance(a,b);
    return 0;
}