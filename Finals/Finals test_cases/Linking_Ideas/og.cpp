#include <bits/stdc++.h>
#define ll long long
#define max(a,b) ((a>b)?a:b)
#define cin f1
#define cout f2
using namespace std;
using namespace std::chrono;
ll timet=0;


fstream f1,f2;
typedef struct LLNode {
    int val;
    struct LLNode* next;
} node;

class LinkedList {
    node* first;

public:
    LinkedList(){
      first = NULL;
    }
    void append(int i){
        node* lol=first;
                node* lol2=new node;
                lol2->val=i;
        lol2->next=NULL;
            if(lol==NULL)   
            first=lol2;
                else                  
        {
                 while(lol->next!=NULL)
                {
                  lol=lol->next;
                } 
              
        lol->next=lol2;   
        } 
                
    }

    int get(int n){
      node* lol=first;
      while((n--)&&(lol->next!=NULL))
             {
                  lol=lol->next;
              }
           int num= lol->val;
       return num;
           
          
    }

    void insert(int n, int i){
            node* lol=first;
            if(n)
            while(--n)
             {
                  lol=lol->next;
              }
       node* lol2= new node;
           lol2->val=i;
           lol2->next=lol->next;
           lol->next=lol2;
            
            
        
    }

    int del(int n){
          node* lol=first;
          if(n==0)
            {first=first->next;
              delete lol;
              return 0;
            }
              while(--n)
             {
                  lol=lol->next;
              }
          node* lol2=lol->next;
                  lol->next=lol2->next;
          delete lol2;
          return 0; 

    }

    int search(int i){
     node* lol=first;
     int num=-1;
     while((lol->next!=NULL))
       {
         ++num; 
            if(lol->val==i)
           return num;         
             lol=lol->next;

       }    
     return -1;
          
    }

};
void solve()
{
    LinkedList l;
    int i,j,n,t,m,lol;
    timet=0;
    cin>>t;
    cin>>n;
        auto start=high_resolution_clock::now();
    for(i=0;i<n;i++)
        {
            cin>>lol;
            l.append(lol);
        }
    --t;

    while(t--)
    {
        cin>>m;
        LinkedList k,r;
        for(i=0;i<m;i++)
        {
            cin>>lol;
            r.append(lol);
        }
        if(m>n)
        {
            LinkedList temp;
            temp=l;
            l=r;
            r=temp;
            int tem;
            tem=m;
            m=n;
            n=tem;
        }
        i=n-1;
        j=0;
        while(i>=(n-m))
        {
            j+=l.get(i)+r.get(i-(n-m));
            if(j>=10)
            {
                j-=10;
                k.append(j);
                j=1;
            }
            else
            {
              k.append(j);
              j=0;
            }   
            i--;
        }
        while(i>=0)
        {
            j+=l.get(i);
            if(j>=10)
            {
                j-=10;
                k.append(j);
                j=1;
            }
            else
            {
              k.append(j);
              j=0;
            }   
            i--;
        }
         for(i=m-1;i>=0;i--)
           r.del(i);
         for(i=n-1;i>=0;--i)
         {
          l.del(i);
         }
        if(j>0)
        {
          k.append(j);
          n++;
        }
    for(i=n-1;i>=0;i--)
    {
      l.append(k.get(i));
      k.del(i);
    }        

    }
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<microseconds>(stop-start);
    timet+=duration.count();
    for(i=0;i<n;++i)
     cout<<int(l.get(i))<<" ";

    printf("%d microseconds\n",timet);
    for(i=n-1;i>=0;--i)
    {
        l.del(i);
    }
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
        solve();
        f1.close();
        f2.close();
    }
}