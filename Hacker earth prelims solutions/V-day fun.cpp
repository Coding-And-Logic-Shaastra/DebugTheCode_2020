#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b, int c) {
    int x=0, y=0, count=0;
    
    while(x != c && y != c) {
        if (x == 0) {
            x = a;
        } 
        else if (y == b) {
            y = 0;
        } 
        else {
            y = x + y;
            x = 0;

            if (y > b) {
                x = y - b;
                y = b;
            }
        }
        count++;
    }

    return count;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b,c;
        cin>>a>>b>>c;
        if (c > max(a,b) || c % __gcd(a,b) != 0) {
            cout<<"-1\n";
        } else {
            cout<<min(solve(a,b,c), solve(b,a,c))<<"\n";
        }
    }
    return 0;
}