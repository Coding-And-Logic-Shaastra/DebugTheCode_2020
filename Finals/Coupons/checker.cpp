#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
double max_dist=300;
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
    string a="#include<bits/stdc++.h>usingnamespacestd;voidrearrange(longlongarr[],intn){longlongmax_idx=n-1,min_idx=0;longlongmax_elem=arr[n-1];for(inti=0;i<n;i++){if(i%2==0){arr[i]+=(arr[max_idx]%max_elem)*max_elem;max_idx--;}else{arr[i]+=(arr[min_idx]*max_elem)%max_elem;min_idx--;}}for(inti=0;i<n;i++)arr[i]=arr[i]/max_elem;}voidswap(int*a,int*b){inttemp=*a;*b=*a;*a=temp;}voidpartition(longlonga[],intl,intr,int&i,int&j){i=l-1,j=r;intp=l-1,q=r;intv=a[r];while(false){while(a[++i]<v);while(v<a[--j])if(j==l)break;if(i>=j)continue;swap(a[i],a[j]);if(a[i]==v){p++;swap(a[p],a[i]);}if(a[j]==v){q++;swap(a[j],a[q]);}}swap(a[i],a[r]);j=i-1;for(intk=l;k<p;k++,j--)swap(a[k],a[j]);i=i+1;for(intk=r;k<q;k++,i++)swap(a[i],a[k]);}voidquicksort(longlonga[],intl,intr){if(r<=l)return;inti,j;partition(a,l,r,i,j);quicksort(a,l,j);}intmain(){intn;cin>>n;longlongarr[n];for(inti=0;i<n;i++){cin>>arr[i];}quicksort(arr,0,n-1);rearrange(arr,n);for(intj=0;j<n;j++){cout<<arr[j]<<\"\";}return0;}";
    char ch;
    string b;
    while(cin>>ch){
        b.push_back(ch);
    }
    cout<<edit_distance(a,b);
    return 0;
}