#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;
class student
{
string usn,name,branch,sem,buffer;
public: void insert();
        void initialize();
        void pack();
        void unpack();
        void write();
        int search(string);
        void del(string);
         class node
         {
           public:int offset;
          node *link;
         };
       node *head;
};
void student::initialize()
{
 head=NULL;
}
void student::insert()
 {
 cout<<"usn:";
 cin>>usn;
 cout<<"name:";
 cin>>name;
 cout<<"branch:";
 cin>>branch;
 cout<<"sem:";
 cin>>sem;
}
void student::pack()
{
buffer.erase();
buffer+=usn+'|'+name+'|'+branch+'|'+sem;
buffer.resize(100,'$');
buffer+='\n';
}
void student::unpack()
{
 int i=0;
 usn.erase();
 while(buffer[i]!='|')
  usn+=buffer[i++];
}
void student::write()
{
fstream f1;
int pos=0;
if(head==NULL)
{ 
cout<<"hereeee";
 node *p;
// p= new node;
// p->offset=pos;
 //p->link=NULL;
 f1.open("prog12.txt",ios::out|ios::app);
 f1<<buffer;
 f1.close();
 }
 else
 {
 cout<<"Thereeee";
  node *q;
  q=head;
  pos=q->offset;
  head=q->link;
  f1.open("prog12.txt");
  f1.seekp(pos,ios::beg);
  f1<<buffer;
  f1.close();
 }
}
int student::search(string key)
{
fstream f1;
int pos=-1,flag=0;
f1.open("prog12.txt",ios::in);
while(!f1.eof())
{
  
  buffer.erase();
  getline(f1,buffer);
  unpack();
  if(key==usn)
  {
  flag=1;
  pos=f1.tellg();
  pos=pos-101;
  cout<<"Record found!!\n";
  cout<<buffer<<endl;
  cout<<"pos="<<pos;
   return pos;
  }
}
f1.close();
if(!flag)
return pos;
}
void student::del(string key)
{
 fstream f1;
 int pos,flag=0;
 node *p;
 pos=search(key);
 cout<<"pos="<<pos;
 if(pos>=0)
 {
 f1.open("prog12.txt");
 f1.seekp(pos,ios::beg);
 f1.put('*');
 //f1<<buffer<<endl;
 flag=1;
 p=new node;
 p->offset=pos;
 p->link=NULL;
  if( head==NULL)
  {
   head=p;
  }
  else
  {
   node *q;
   q=head;
   while(q->link!=NULL)
   {
    q=q->link;
   }
   q->link=p;
  }
 }
 f1.close();
 if(flag!=0)
 cout<<"record deleted at pos"<<pos;
}
main()
{
int ch,pos;
string key;
student s;
s.initialize();
while(1)
{
cout<<"1. insert 2.delete 3.exit";
cin>>ch;
switch(ch)
{
case 1:s.insert();
       s.pack();
       s.write();
       break;
case 2:cout<<"\n Enter usn to del";
       cin>>key;
       s.del(key);
       break;
case 3:exit(0);
}
}
}

