#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
class student
{
 string usn,name,branch,sem,buffer;
 int rrn_list[100];
 public:
        void pack();
        void write();
        void insert();
        int search(int);
};
int main()
{
int pos, ch;
student s;
int key;
cout<<"Enter your choice?:\n 1.insert 2.search";
cin>>ch;
switch(ch)
{
case 1:s.insert();
       s.pack();
       s.write();
       break;
case 2:cout<<"Enter rrn to search";
       cin>>key;
       s.search(key);
       break;
}
return 0;
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
buffer+='0'+usn+'|'+name+'|'+branch+'|'+sem+'$'+'\n';
}
void student::write()
{
 fstream f1;
 f1.open("prog4.txt",ios::out|ios::app);
 f1<<buffer;
 f1.close();
}
int student::search(int rrn)
{
fstream f1;
int pos,count=0;
f1.open("prog4.txt",ios::in);
while(!f1.eof())
{
 pos=f1.tellg();
 buffer.erase();
 getline(f1,buffer);
 if(buffer.empty()) continue;
 rrn_list[++count]=pos;
}
f1.close();
if(rrn>count)
exit(0);
f1.open("prog4.txt");
pos=rrn_list[rrn];
f1.seekp(pos,ios::beg);
buffer.erase();
getline(f1,buffer);
cout<<"the record is....\n"<<buffer<<endl;
}

