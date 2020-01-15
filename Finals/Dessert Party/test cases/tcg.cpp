#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<stack>
#include<cstring>


using namespace std;

int solve(int t,int a, int b, int c) {
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



int main()
{
	ofstream f,f2;
	int i,j,c=0,k;
	string input;
	string fp = "C:\\Users\\HP\\Documents\\CnL\\Debug the code\\test_cases\\Q4\\tc",s;
	c=0;
	while(c<=9)
	{

				ostringstream str1;
				str1<<c;
				s=str1.str();
				string fp2 = fp+ s+ ".txt",fp3 = "C:\\Users\\HP\\Documents\\CnL\\Debug the code\\test_cases\\Q4\\output-"+s+".txt";
				f2.open(fp3);
				f.open(fp2);
				/*cin>>input;
				f<<input;
				cout<<(longestSubword(input));*/
				f<<s1[c];
				f2<<s2[c];
				f.close();
				f2.close();
				++c;

	}
	return 0;
}