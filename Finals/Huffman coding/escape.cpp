#include<bits/stdc++.h>
#include<fstream>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;


int main(void)
{
    string a;
    char ch;
    fstream f1,f2;
    //f1.open("lol.txt",ios::in);
    f2.open("buggy.txt",ios::out);
    while(ch!='~'){
        cin>>ch;
        if(ch=='\''||ch=='\"'||ch=='\\')
            a.push_back('\\');
        a.push_back(ch);
    }
    string b;
    f2<<a;
   // f1.close();
    f2.close();
    return 0;
}