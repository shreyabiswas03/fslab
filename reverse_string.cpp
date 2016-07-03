#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int main()
{
int ch,i;
char arr[100],c;
cout<<"Enter the choice to reverse\n1.standard i/o 2.file\n ";
cin>>ch;
switch(ch)
{
case 1:c='y';
       while(c=='y')
       {
       cout<<"Enter the string?:";
       cin>>arr;
       int x;
       x=strlen(arr);
       for(i=x-1;i>=0;i--)
       {
        cout<<arr[i];
       }
       cout<<endl;
       cout<<"Do you want to continue?(y/n):";
       cin>>c;
       }
       break;
case 2:fstream f1,f2;
       int x;
       char fname1[100],fname2[100];
       cout<<"Enter file with data:";
       cin>>fname1;
       cout<<"Enter file to store the reverse";
       cin>>fname2;
       f1.open(fname1,ios::in);
       f2.open(fname2,ios::out);
       while(1)
       {
        f1.getline(arr,25);
        if(f1.eof())
        break;
        x=strlen(arr);
        for(i=x-1;i>=0;i--)
        {
         f2<<arr[i];
        }
        f2<<endl;
       }
       f1.close();
       f2.close();
       break;
 
}
return 0;
}

