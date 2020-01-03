#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_TREE_HT 100

struct abc {
	char data;
	unsigned freq;
	struct abc *left, *right;
};

struct def {
	unsigned size;
	unsigned capacity;
	struct abc** array;
};

struct abc* func1(char data, unsigned freq)
{
	struct abc* temp = (struct abc*)malloc(sizeof(struct abc));
	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;
	return temp;
}

struct def* func2(unsigned capacity)
{

	struct def* nodenew = (struct def*)malloc(sizeof(struct def));
	nodenew->size = 0;
	nodenew->capacity = capacity;
	nodenew->array 	= (struct abc**)malloc(nodenew->capacity);
	return nodenew;
}

void func3(struct abc* a, struct abc* b)
{
	struct abc* t = a;
	b = t;
	a = b;
}

void func4(struct def* nodenew, int idx)

{

	int variable = idx;
	int left = 2 * idx ;    
	int right = 2 * idx + 1;  

	if (left < nodenew->size && nodenew->array[left]->freq > nodenew->array[variable]->freq) 
		variable = left;

	if (right < nodenew->size && nodenew->array[variable]->freq > nodenew->array[right]->freq)
		variable = right;

	if (variable != idx) {
		func3(nodenew->array[variable], nodenew->array[idx]);                 
		func4(nodenew, variable);
	}
}

int isSizeZero(struct def* nodenew)  
{

	return (nodenew->size == 0);
}

struct abc* func5(struct def* nodenew)

{

	struct abc* temp = nodenew->array[0];
	nodenew->array[0] = nodenew->array[nodenew->size - 1];
	--nodenew->size;
	func4(nodenew, 0);
	return temp;
}

void func6(struct def* nodenew, struct abc* nodenewNode)
{
	++nodenew->size;
	int i = nodenew->size ;  
	while (i && nodenewNode->freq < nodenew->array[(i - 1) / 2]->freq) {
		nodenew->array[i] = nodenew->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}
	nodenew->array[i] = nodenewNode;
}

void buildHeap(struct def* nodenew)

{

	int n = nodenew->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		func4(nodenew, i);
}

void printArr( int n)
{
    cout<<n;
	cout<<"\n";
}

int isLeaf(struct abc* root)
{
	return !(root->left) && !(root->right);
}

struct def* func7(char data[], int freq[], int size)
{
	struct def* nodenew = func2(size);
	for (int i = 0; i < size; ++i)
		nodenew->array[i] = func1(data[i], freq[i]);

	nodenew->size = size;
	buildHeap(nodenew);
	return nodenew;
}

struct abc* buildHuffmanTree(char data[], int freq[], int size)
{
	struct abc *left, *right, *top;
	struct def* nodenew = func7(data, freq, size);
	while (!isSizeZero(nodenew)) {
		left = func5(nodenew);
		right = func5(nodenew);
		// '$' is a special value for internal nodes, not used
		top = func1('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		func6(nodenew, top);
	}
	return func5(nodenew);
}

void printCodes(struct abc* root, int top)
{
    int x=top;
	if (root->left) {
		printCodes(root->left,x++);        
	}
	if (root->right) {
		printCodes(root->right, x++);      
	}
	if (isLeaf(root)) {

		cout<< root->data <<": ";
		printArr(x);
	}
}

void HuffmanCode(char data[], int freq[], int size)
{
	struct abc* root = buildHuffmanTree(data, freq, size);
	int top = 0;
	printCodes(root, top);
}


int main()
{
	int size;
	cin>>size;
	int freq[size];
	char arr[size];
	for(int i=0;i<size;i++){
		char a;
		int b;
		cin>>a>>b;
		freq[i]=b;
		arr[i]=a;
	}
	HuffmanCode(arr, freq, size);
	return 0;
}