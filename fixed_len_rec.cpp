/*things to note: FIXED LEN
 -simple insert,pack,write,unpack
 - int search(key)
    -continue when '*' found
    -return pos inside if statement also
 -delete(key) has search inside it
 -modify(key) had delete inside it
*/
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class student
{
 string usn,name,branch,sem,buffer;
 public:void insert();
        void pack();
        void write();
        void unpack();
        int search(string);
        void modify(string);
       int del(int);
       void average();
       void del_field();
};
void student::del_field()
{
 int ch,i;
 fstream f1,f2;
 f1.open("prog2.txt");
 f2.open("prog21.txt",ios::out);
 cout<<"select the field \n 1.name 2.branch 3.sem";
 cin>>ch;
 switch(ch)
 {
 case 1:while(!f1.eof())
        {
        buffer.erase();
        getline(f1,buffer);
        i=0;
 	usn.erase();
 	while(buffer[i]!='|')
 	usn+=buffer[i++];
 	i++;
 	f1.seekp(i,ios::beg);
 	f1.put('*');
	name.erase();
 	while(buffer[i]!='|')
          name+=buffer[i++]; 
        f2<<name<<endl;
       }
       f1.close();
       f2.close();
       break;
}
}
void student::average()
{
fstream f1,f2;
int value=0;
int numb,count=1;
f1.open("prog2.txt",ios::in);
f2.open("prog1o.txt",ios::out);
while(!f1.eof())
{
 getline(f1,buffer);
 unpack();
 istringstream(sem)>>numb;
 value+=numb;
 count++;
}
value=(value-numb)/count;
f1.close();
f2<<"sum is ="<<value;
f2.close();
}
void student::insert()
{
 cout<<"usn:";
 cin>>usn;
 cout<<"name:";
 cin>>name;
 cout<<"branch:";
 cin>>branch;
 cout<<"semester:";
 cin>>sem;
};
void student::pack()
{
string temp;
temp.erase();
temp+=usn+'|'+name+'|'+branch+'|'+sem;
temp.resize(100,'$');
buffer+=temp+'\n';
};
void student::write()
{
    fstream f1;
    f1.open("prog2.txt",ios::out|ios::app);
    f1<<buffer;
    f1.close();   
};   
 
void student::unpack()
{
 int i=0;
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
int student::search(string key)
{
 int pos,flag;
 fstream f1;
 f1.open("prog2.txt",ios::in);
 while(!f1.eof())
 {
  buffer.erase();
  getline(f1,buffer);
  unpack();
  if(key==usn)
  { 
   flag=1;
   pos=f1.tellg();
   pos-=101;
   cout<<"The record is :\n"<<buffer<<endl<<"The pos is :"<<pos<<endl;
  }
 }
 f1.close();
 if (flag==1)
  return pos;
 else
 {
 cout<<"record not found";
  exit(0);
}
}
int student::del(int pos)
{
 fstream f1;
 int flag;
 char symb='*';
 f1.open("prog2.txt");
 f1.seekp(pos,ios::beg);
 f1.put(symb);
 flag=1;
 f1.close();
 return 1;
}
void student::modify(string key)
{
 int ch,pos,x;
  pos=search(key);
  if(del(pos))
  {
  cout<<"Field to modify?: "<<"1.usn 2.name 3.branch 4.sem"<<endl;
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Usn ?:\n";
          cin>>usn;
          break;
   case 2:cout<<"name ?:\n";
          cin>>name;
           usn=key;
          break;
   case 3:cout<<"branch ?:\n";
          cin>>branch;
           usn=key;
          break;
   case 4:cout<<"Semester ?:\n";
          cin>>sem;
           usn=key;
          break;
  }
  buffer.erase();
   pack();
   write();
  }
}       
int main()
{
student s;
int ch;
string key;
while(1)
{
cout<<"Enter your choice\n 1.insert 2.search 3.modify 4.delete a field";
cin>>ch;
switch(ch)
{
 case 1: 
         s.insert();
         s.pack();
         s.write();
         break;
case 2: cout<<"Enter usn to search";
        cin>>key;
        s.search(key);
        break;
case 3: cout<<"Enter usn to modify";
        cin>>key;
        s.modify(key);
        break; 
case 4: s.del_field();
break;
default:s.average();    
}
}
return 0;
}

