#include<iostream>
#include<string.h>

using namespace std;

string longestSubword(string s) {
    int n = s.length();
    if(n == 1){
        return s.substr(0,1);
    }
    int dp[1001][1001];
    memset(dp,0,sizeof(dp));
    int maxl = 1,maxind = 0;
    for(int i = 0;i < n;i++){
        dp[i][i] = 1;
        if(i < n-1){
            dp[i][i+1] = (s[i] == s[i+1])?2:0;
            if(dp[i][i+1] > maxl){
                maxl = dp[i][i+1];
                maxind = i;
            }
        }
    }
    
    for(int l = 3;l <= n;l++){
        for(int i = 0;i < n-l+1;i++){
            int j = i+l-1;
            if(s[i] == s[j]){
                dp[i][j] = (dp[i+1][j-1]>0)?(dp[i+1][j-1]+2):0;
            }
            if(dp[i][j] > maxl){
                maxl = l;
                maxind = i;
            }
        }
    }
    return s.substr(maxind,maxl);
    
}

int main() {
    string s;
    cin>>s;
    cout<<longestSubword(s)<<"\n";
}

