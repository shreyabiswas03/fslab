#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;
class student
{
string usn,name,branch,sem,buffer;
public:
      int hash(string);
      void pack();
      void insert();
      void unpack(int);
      void write();
      void search(string);
};
int student::hash(string key)
{
int t;
t=(((key[7]-48)*100)+((key[8]-48)*10)+((key[9]-48)))%9;
if(t==0)
return 9;
else
return t;
}
void student::insert()
{
cout<<"Enter usn";
cin>>usn;
cout<<"Enter name:";
cin>>name;
cout<<"Enter branch";
cin>>branch;
cout<<"Enter sem";
cin>>sem;
}
void student::pack()
{
string temp;
temp+=usn+'|'+name+'|'+branch+'|'+sem;
buffer+=temp;
buffer.resize(100,'$');
buffer+='\n';
cout<<buffer<<endl;
}
void student::write()
{
 fstream f1;
 string temp;
 int pos,count=0;
 pos=hash(usn);
 pos--;
 pos=pos*304;
 f1.open("def.txt");
 f1.seekp(pos,ios::beg);
 getline(f1,temp);
 f1.close();
 count=temp[0]-48;
 f1.open("def.txt");
 if(count<0)
 {
  f1.seekp(pos,ios::beg);
  f1.put('1');
  pos=pos+1;
 }
 else if(count==1)
 {
    f1.seekp(pos,ios::beg);
  f1.put('2');
  pos=pos+102;
 }
 else if(count==2)
 {
   f1.seekp(pos,ios::beg);
  f1.put('3');
  pos=pos+203;
 }
 else
 {
  cout<<"Buffer overflow.....";
  return;
 }
  cout<<"Inserting at pos.."<<pos;
   f1.seekp(pos,ios::beg);
   f1<<buffer;
   f1.close();
}
   
void student::unpack(int flag)
{
int i=0;
if(flag==1) i++;
usn.erase();
while(buffer[i]!='|')
usn+=buffer[i++];
i++;
name.erase(); 
 while(buffer[i]!='|') 
 name+=buffer[i++]; 
i++;
branch.erase(); 
 while(buffer[i]!='|') 
 branch+=buffer[i++]; 
i++;
sem.erase(); 
 while(buffer[i]!='$') 
 sem+=buffer[i++]; 
}
void student::search(string key)
{
fstream f1;
 string temp;
 int flag=0;
 int pos,count=0,i=1;
 pos=hash(key);
 pos--;
 pos=pos*304;
 f1.open("def.txt");
 f1.seekp(pos,ios::beg);
 getline(f1,temp);
 count=temp[0]-48;
 f1.seekp(pos,ios::beg);
 while(i<=count)
 {
  buffer.erase();
  getline(f1,buffer);
  unpack(i++);
  //cout<<"......"<<usn;
  if(key==usn)
  {
  flag=1;
 cout<<"The record is...\n:";
 cout<<buffer;
 }
 }
 if(!flag)
 cout<<"Not found";
 /*else
 {
 cout<"The record is...\n:";
 cout<<buffer;
 }*/
 f1.close();
}
int main()
{
student s;
int ch;
string key;
cout<<"1.insert 2.search";
cin>>ch;
switch(ch)
{
 case 1:s.insert();
        s.pack();
        s.write();
        break;
 case 2:cout<<"Enter usn to search";
        cin>>key;
       s.search(key);
        break;
}
return 0;
}
