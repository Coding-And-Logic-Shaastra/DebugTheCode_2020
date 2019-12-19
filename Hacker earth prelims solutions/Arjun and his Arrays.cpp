#include <bits/stdc++.h>
#define M (1000*1000*1000 + 7)  
typedef long long ll;
using namespace std;

int power(int a,int b)
{
    if(b == 1)
      return a;
    else if(b % 2 == 0)
     {
        ll x = power(a,b/2);
        return ((x * x)%M);
     }
    else
    {
        ll x = power(a,b/2);
        return ((((x*x)%M)*a)%M);
    }
}
int max(int a,int b)
{
  return (a>b)?a:b;
}
int solve(int n,vector<int> v)
{
  int i;
  int answer = 1;
  for(i = 0;i+1 < v.size();i++)
 {
    int possible_answer = power(v[i],v[i+1]);
    answer = max(answer,possible_answer);
 }
  return answer;    
}
int main(void)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(i = 0;i < n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(n,v);
    return 0;
}
