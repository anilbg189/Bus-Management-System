#include<iostream>
using namespace std;
int main()
{
int test;
cin>>test;
int b[100];
for(int i=0;i<test;i++)
    cin>>b[i];
for(int i=0;i<test;i++)
    {
    int pow=1;
    int a=2;
    while ( ((a)-1)<b[i])
    {
			a=1;
        pow=pow+1;
        for(int i=0;i<pow;i++)
          a=a*2;
    
    }
    cout<<pow<<endl;
   }
   return 0;
}
