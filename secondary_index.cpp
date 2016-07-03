#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;
class student
{
 string name,usn,branch,sem,buffer,name_list[100];
 int add_list[100],count;
 public:
 void pack();
 string unpack();
 void insert();
 void write();
 void creat_pi();
 void sort_pi();
 int search_pi(string);
 void search(string);
 void del(string);
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
 f1.open("prog5.txt",ios::out|ios::app);
 f1<<buffer;
 f1.close();
}
string student::unpack()
{
int i=1;
usn.erase();
while(buffer[i]!='|')
usn+=buffer[i++];
i++;
name.erase();
while(buffer[i]!='|')
name+=buffer[i++];
return name ;
}
void student::creat_pi()
{
int i;
count=-1;
fstream f1;
f1.open("prog5.txt",ios::in);
while(!f1.eof())
{
 int pos;
 pos=f1.tellg();
 cout<<"position="<<pos<<endl;
 buffer.erase();
 getline(f1,buffer);
 if(buffer.empty()) break;
 if(buffer[0]=='*') continue;
 name=unpack();
 ++count;
 name_list[count]=name;
 add_list[count]=pos;
}
f1.close();
for(i=0;i<=count;i++)
 { 
   cout<<"usn list:"<<name_list[i]<<" "<<endl; 
 }
 for(i=0;i<=count;i++)
 { 
   cout<<"add list:"<<add_list[i]<<" "<<endl; 
 }
 sort_pi();
}
void student::sort_pi()
{
int temp_add,i,j;
string temp_name;
for(i=0;i<=count-1;i++)
{
 for(j=0;j<=count-1-i;j++)
   {
     if(name_list[j]>name_list[j+1])
      {
	 temp_name=name_list[j];
	 name_list[j]=name_list[j+1];
	 name_list[j+1]=temp_name;
	  temp_add=add_list[j];
	 add_list[j]=add_list[j+1];
	 add_list[j+1]=temp_add;
      }
   }

}
 for(i=0;i<=count;i++)
 { 
   cout<<"usn list after sort:"<<i<<" "<<name_list[i]<<" "<<endl; 
 }
 for(i=0;i<=count;i++)
 { 
   cout<<"add list after sort:"<<i<<" "<<add_list[i]<<" "<<endl; 
 }
}
int student::search_pi(string key)
{
 int low=0,high=count,pos,mid=0,flag=0;
 while(low<=high)
 {
 mid=(low+high)/2;
 if(name_list[mid]==key)
 {
  flag=1;
  return mid;
 }
 if(name_list[mid]>key)
  high=mid-1;
 if(name_list[mid]<key)
  low=mid+1;
 }
 if(flag!=1)
 return -1;
}
void student::search(string key)
{
 fstream f1;
 int pos,add;
 pos=search_pi(key);
 if(pos>=0)
 {
  f1.open("prog5.txt",ios::in);
  buffer.erase();
  add=add_list[pos];
  f1.seekp(add,ios::beg);
  getline(f1,buffer);
  cout<<"The record is......."<<buffer<<endl;
  f1.close();
 }
 else cout<<"record not found";
}
void student::del(string key)
{
fstream f1;
int pos,i,add;
char dch='*';
pos=search_pi(key);
if(pos>=0)
{
 f1.open("prog5.txt");
 buffer.erase();
 add=add_list[pos];
 f1.seekp(add,ios::beg);
 f1.put(dch);
 cout<<"Record deleted"<<endl;
 f1.close();
 for(i=pos;i<count;i++)
 {
  name_list[i]=name_list[i+1];
  add_list[i]=add_list[i+1];
 }
 count--;
}
else cout<<"record not found";
}
int main()
{
 int ch;
 string key;
 student s;
 s.creat_pi();
cout<<"enter choice\n1.insert 2.search 3.delete";
 cin>>ch;
 switch(ch)
 {
 case 1:s.insert();
        s.pack();
        s.write();
        break;
 case 2: cout<<"Enter name to search";
         cin>>key;
         s.search(key);
         break;
 case 3: cout<<"Enter name to delete";
         cin>>key;
        s.del(key);
         break;
 }
 return 0;
}
