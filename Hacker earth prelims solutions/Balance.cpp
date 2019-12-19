#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;


int main() {
    char a[1000];
    long t,i;
    char ch;
    cin>>t;
    while(t--)
    {
    cin>>a;
    stack<char> b;
    long length=strlen(a);
    ch=a[0];
        b.push(ch);
     i=1;   
    while(i<length)
     {
        ch=a[i];
        if(b.empty())
            b.push(ch);
        else
        switch(ch)
        {
            case '}':{
                      if(b.top()=='{')
                      b.pop();
                          else
                              b.push(ch);
                      break;
                     }
            case ')':{
                      if(b.top()=='(')
                      b.pop();
                        else
                              b.push(ch);
                      break;
                     }
            case ']':{
                      if(b.top()=='[')
                      b.pop();
                          else
                              b.push(ch);
                      break;
                     }
            default:b.push(ch);break;
             
        }
        i++;
     }
        if(b.empty())
            cout<<"balanced\n";
        else
            cout<<"not balanced\n";
        for(i=0;i<b.size();i++)
        {
            b.pop();
        }
    }
    return 0;
}