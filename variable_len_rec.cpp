#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
class student
{
 string usn,name,branch,sem,buffer;
 public:void insert();
        void pack();
        void unpack();
        void write();
        int search(string);
        int del(int);
        void modify(string);
};
void student::insert()
{
 cout<<"usn?:";
 cin>>usn;
 cout<<"name?:";
 cin>>name;
 cout<<"branch?:";
 cin>>branch;
 cout<<"sem?:";
 cin>>sem;
}
void student::pack()
{
buffer.erase();
buffer+='0'+usn+'|'+name+'|'+branch+'|'+sem+'$'+'\n';
}
void student::write()
{
fstream f1;
f1.open("prog3.txt",ios::out|ios::app);
f1<<buffer;
f1.close();
}
void student::unpack()
{cout<<"hello un";
 int i=1;
usn.erase();
while(buffer[i]!='|');
usn+=buffer[i++];
i++;
name.erase();
while(buffer[i]!='|');
name+=buffer[i++];
i++;
branch.erase();
while(buffer[i]!='|');
branch+=buffer[i++];
i++;
sem.erase();
while(buffer[i]!='$');
sem+=buffer[i++];
}
int student::search(string key)
{ cout<<"hello";
 int pos,flag;
 fstream f1;
 f1.open("prog3.txt",ios::in);
 while(!f1.eof())
 {
 buffer.erase();
 getline(f1,buffer);
 unpack();
 if(key==usn)
 {
  flag=1;
  pos=f1.tellg();//gives currect pos of file 
  pos=pos-(buffer.size()+1);
  cout<<"The record found at :"<< pos;
 }
 }
 f1.close();
 if (flag==1)
  return pos;
 else
 {
  cout<<"Not found record";
  exit(0);
 }
}
int student::del(int pos)
{
 fstream f1;
 f1.open("prog3.txt");
 f1.seekg(pos,ios::beg);
 f1.put('*');
 return 1;
}
void student::modify(string key)
{
 int pos,ch;
 pos=search(key);
 if(del(pos))
 {
  cout<<"Enter usn to modify?:\n 1.usn 2.name 3.branch 4.sem";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<"usn?:";
          cin>>usn;
          break;
   case 2: cout<<"name?: ";
           cin>>name;
           usn=key;
   case 3: cout<<"branch?: ";
           cin>>branch;
           usn=key;
   case 4: cout<<"sem?: ";
           cin>>sem;
           usn=key;
  }
 }
 pack();
 write();
}
int main()
{
 int ch;
 string key;
 student s;
 cout<<"Enter your choice?\n1.insert 2.Search 3.modify";
 cin>>ch;
 switch(ch)
 {
  case 1: s.insert();
          s.pack();
          s.write();
          break;
  case 2:cout<<"Enter usn to search:";
         cout<<"hello";
         cin>>key;
         cout<<"Key is "<<key;
         cout<<"hello";
         s.search(key);
         break;
  case 3: cout<<"Enter usn to modify";
          cin>>key;
          s.modify(key);
          break;
 }
return 0;
}
