//create 8 files with data
#include <iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std;
string merge(vector<string>fname,int left,int right)// vector is similar to arrays but that their size is allocated dynamically
{
if(left==right)
return fname[left];
else if((right-left)==1)
{
ifstream if1(fname[left].c_str());
ifstream if2(fname[right].c_str());
ofstream of((fname[left]+"a").c_str());
string s1,s2;
getline(if1,s1);
getline(if2,s2);
while(!(if1.eof()) && !(if2.eof()))
{
if(s1==s2)
{
     if(s1!="")
        {
	of<<s1<<endl;
	}
	getline(if1,s1);//since s1 and s2 are equal ,if s1="" then s2 also ""
	getline(if2,s2);
	}
	else if(s1<s2)
	{
	if(s1!=""){
	of<<s1<<endl;
	}
	getline(if1,s1);
	}
	else
	{
	if(s2!="")
	{
	  of<<s2<<endl;
	}
	getline(if2,s2);
	}
	}
	while(!(if1.eof()))
	{ if(s1!=""){
	of<<s1<<endl;
	}
	getline(if1,s1);
	}
while(!(if2.eof()))
{ if(s2!=""){
    of<<s2<<endl;
}
    getline(if2,s2);
}
if1.close();
if2.close();
of.close();
return fname[left]+"a";
}
else
{
 int mid=(left+right)/2;
 string f1,f2;
 f1=merge(fname,left,mid);
 f2=merge(fname,mid+1,right);
 vector<string>str;
 str.push_back(f1);// push back adds contents of f1 into the vector so that it can continue with merging files
 str.push_back(f2);
  merge(str,0,1);
 return merge(str,0,1);
}
}
int main()
{
vector<string>v;
v.push_back("/home/shreya/tryingfs/1.txt");
v.push_back("/home/shreya/tryingfs/2.txt");
v.push_back("/home/shreya/tryingfs/3.txt");
/*v.push_back("/home/shreya/tryingfs/4.txt");
v.push_back("/home/shreya/tryingfs/5.txt");
v.push_back("/home/shreya/tryingfs/6.txt");
v.push_back("/home/shreya/tryingfs/7.txt");
v.push_back("/home/shreya/tryingfs/8.txt");*/
cout<<merge(v,0,2);
}
