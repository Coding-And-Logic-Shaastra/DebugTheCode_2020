#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
double max_dist;
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
   return dp[m][n];

}

int main(void)
{
    string a="#include<iostream>#include<cstdlib>usingnamespacestd;#defineMAX_TREE_HT100structabc{chardata;unsignedfreq;structabc*left,*right;};structdef{unsignedsize;unsignedcapacity;structabc**array;};structabc*func1(chardata,unsignedfreq){structabc*temp=(structabc*)malloc(sizeof(structabc));temp->left=temp->right=NULL;temp->data=data;temp->freq=freq;returntemp;}structdef*func2(unsignedcapacity){structdef*nodenew=(structdef*)malloc(sizeof(structdef));nodenew->size=0;nodenew->capacity=capacity;nodenew->array=(structabc**)malloc(nodenew->capacity);returnnodenew;}voidfunc3(structabc*a,structabc*b){structabc*t=a;b=t;a=b;}voidfunc4(structdef*nodenew,intidx){intvariable=idx;intleft=2*idx;intright=2*idx+1;if(left<nodenew->size&&nodenew->array[left]->freq>nodenew->array[variable]->freq)variable=left;if(right<nodenew->size&&nodenew->array[variable]->freq>nodenew->array[right]->freq)variable=right;if(variable!=idx){func3(nodenew->array[variable],nodenew->array[idx]);func4(nodenew,variable);}}intisSizeZero(structdef*nodenew){return(nodenew->size==0);}structabc*func5(structdef*nodenew){structabc*temp=nodenew->array[0];nodenew->array[0]=nodenew->array[nodenew->size-1];--nodenew->size;func4(nodenew,0);returntemp;}voidfunc6(structdef*nodenew,structabc*nodenewNode){++nodenew->size;inti=nodenew->size;while(i&&nodenewNode->freq<nodenew->array[(i-1)/2]->freq){nodenew->array[i]=nodenew->array[(i-1)/2];i=(i-1)/2;}nodenew->array[i]=nodenewNode;}voidbuildHeap(structdef*nodenew){intn=nodenew->size-1;inti;for(i=(n-1)/2;i>=0;--i)func4(nodenew,i);}voidprintArr(intn){cout<<n;cout<<\"\\n\";}intisLeaf(structabc*root){return!(root->left)&&!(root->right);}structdef*func7(chardata[],intfreq[],intsize){structdef*nodenew=func2(size);for(inti=0;i<size;++i)nodenew->array[i]=func1(data[i],freq[i]);nodenew->size=size;buildHeap(nodenew);returnnodenew;}structabc*buildHuffmanTree(chardata[],intfreq[],intsize){structabc*left,*right,*top;structdef*nodenew=func7(data,freq,size);while(!isSizeZero(nodenew)){left=func5(nodenew);right=func5(nodenew);//\'$\'isaspecialvalueforinternalnodes,notusedtop=func1(\'$\',left->freq+right->freq);top->left=left;top->right=right;func6(nodenew,top);}returnfunc5(nodenew);}voidprintCodes(structabc*root,inttop){intx=top;if(root->left){printCodes(root->left,x++);}if(root->right){printCodes(root->right,x++);}if(isLeaf(root)){cout<<root->data<<\":\";printArr(x);}}voidHuffmanCode(chardata[],intfreq[],intsize){structabc*root=buildHuffmanTree(data,freq,size);inttop=0;printCodes(root,top);}intmain(){intsize;cin>>size;intfreq[size];chararr[size];for(inti=0;i<size;i++){chara;intb;cin>>a>>b;freq[i]=b;arr[i]=a;}HuffmanCode(arr,freq,size);return0;}";
    string b="#include<iostream>#include<cstdlib>usingnamespacestd;#defineMAX_TREE_HT100structabc{chardata;unsignedfreq;structabc*left,*right;};structdef{unsignedsize;unsignedcapacity;structabc**array;};structabc*func1(chardata,unsignedfreq){structabc*temp=(structabc*)malloc(sizeof(structabc));temp->left=temp->right=NULL;temp->data=data;temp->freq=freq;returntemp;}structdef*func2(unsignedcapacity){structdef*nodenew=(structdef*)malloc(sizeof(structdef));nodenew->size=0;nodenew->capacity=capacity;nodenew->array=(structabc**)malloc(nodenew->capacity*sizeof(structabc*));returnnodenew;}voidfunc3(structabc**a,structabc**b){structabc*t=*a;*a=*b;*b=t;}voidfunc4(structdef*nodenew,intidx){intsmallest=idx;intleft=2*idx+1;intright=2*idx+2;if(left<nodenew->size&&nodenew->array[left]->freq<nodenew->array[smallest]->freq)smallest=left;if(right<nodenew->size&&nodenew->array[right]->freq<nodenew->array[smallest]->freq)smallest=right;if(smallest!=idx){func3(&nodenew->array[smallest],&nodenew->array[idx]);func4(nodenew,smallest);}}intisSizeZero(structdef*nodenew){return(nodenew->size==1);}structabc*func5(structdef*nodenew){structabc*temp=nodenew->array[0];nodenew->array[0]=nodenew->array[nodenew->size-1];--nodenew->size;func4(nodenew,0);returntemp;}voidfunc6(structdef*nodenew,structabc*nodenewNode){++nodenew->size;inti=nodenew->size-1;while(i&&nodenewNode->freq<nodenew->array[(i-1)/2]->freq){nodenew->array[i]=nodenew->array[(i-1)/2];i=(i-1)/2;}nodenew->array[i]=nodenewNode;}voidbuildHeap(structdef*nodenew){intn=nodenew->size-1;inti;for(i=(n-1)/2;i>=0;--i)func4(nodenew,i);}voidprintArr(intn){cout<<n;cout<<\"\\n\";}intisLeaf(structabc*root){return!(root->left)&&!(root->right);}structdef*func7(chardata[],intfreq[],intsize){structdef*nodenew=func2(size);for(inti=0;i<size;++i)nodenew->array[i]=func1(data[i],freq[i]);nodenew->size=size;buildHeap(nodenew);returnnodenew;}structabc*buildHuffmanTree(chardata[],intfreq[],intsize){structabc*left,*right,*top;structdef*nodenew=func7(data,freq,size);while(!isSizeZero(nodenew)){left=func5(nodenew);right=func5(nodenew);//\'$\'isaspecialvalueforinternalnodes,notusedtop=func1(\'$\',left->freq+right->freq);top->left=left;top->right=right;func6(nodenew,top);}returnfunc5(nodenew);}voidprintCodes(structabc*root,inttop){if(root->left){printCodes(root->left,top+1);}if(root->right){printCodes(root->right,top+1);}if(isLeaf(root)){cout<<root->data<<\":\";printArr(top);}}voidHuffmanCodes(chardata[],intfreq[],intsize){structabc*root=buildHuffmanTree(data,freq,size);inttop=0;printCodes(root,top);}intmain(){intsize;cin>>size;intfreq[size];chararr[size];for(inti=0;i<size;i++){chara;intb;cin>>a>>b;freq[i]=b;arr[i]=a;}if(size==1){cout<<arr[0]<<\":1\";}else{HuffmanCodes(arr,freq,size);}return0;}";
    cout<<edit_distance(a,b);
    return 0;
}