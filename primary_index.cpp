/* PRIMARY INDEX
-creat_pri()
   -read lines 1 by 1,usn=unpack
   -++count
   -usn_list[count]=usn;
   -add_list[count]=pos;
-sort()
   -bubble sort
-search_pri(string)
   -binary search
-search(string)
   -call search_pri(key) to get position in the usn list
   -calculate address using add_list[pos]
   -finally seek the record
-del(string)
   -call search_pri(key) to get position in the usn list
   -calculate address using add_list[pos]
   -finally put '*'
   -using for(i=pos;i<count;i++)
         -usn_list[i]=usn_list[i+1];
         -add_list[i]=add_list[i+1];
         count--;
*/
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;
class student
{
string usn,name,branch,sem,buffer;
string usn_list[100];
int add_list[100],count;
public:
       void insert();
       void pack();
       void write();
       string unpack();
       void sort();
       void creat_pri();
       void del(string);
       void search(string);
       int search_pri(string);
};
void student::insert()
{
cout<<"usn";
cin>>usn;
cout<<"name";
cin>>name;
cout<<"branch";
cin>>branch;
cout<<"sem";
cin>>sem;
}
void student::pack()
{
buffer.erase();
buffer+=usn+'|'+name+'|'+branch+'|'+sem+'$';
buffer+='\n';
}
void student::write()
{
fstream f1;
f1.open("sample2.txt",ios::out|ios::app);
f1<<buffer;
f1.close();
}
string student::unpack()
{
 int i=0;
 usn.erase();
 while(buffer[i]!='|')
  usn+=buffer[i++];
  return usn;
}
void student::creat_pri()
{
fstream f1;
int pos,i;
count=-1;
f1.open("sample2.txt",ios::in);
while(!f1.eof())
{
 pos=f1.tellg();
 buffer.erase();
 getline(f1,buffer);
 if(buffer.empty()) break;
 if(buffer[0]=='*') continue;
  usn=unpack();
  ++count;
  usn_list[count]=usn;
  add_list[count]=pos;
}
f1.close();
for(i=0;i<=count;i++)
{
 cout<<usn_list[i]<<"........"<<add_list[i]<<endl;
}
sort();
}
void student::sort()
{
int i,j;
int temp_add;
string temp_usn;
for(i=0;i<=count;i++)
for(j=i+1;j<=count;j++)
 if(usn_list[i]>usn_list[j])
 {
  temp_usn=usn_list[i];
  usn_list[i]=usn_list[j];
  usn_list[j]=temp_usn;
  temp_add=add_list[i];
  add_list[i]=add_list[j];
  add_list[j]=temp_add;
 }
 cout<<"\nsorted\n";
for(i=0;i<=count;i++)
{
 cout<<usn_list[i]<<"........"<<add_list[i]<<endl;
}

}
int student::search_pri(string key)
{
int mid,low=0,high=count;
while(low<=high)
{ 
 mid=(low+high)/2;
  if(usn_list[mid]==key)
   return mid;
  if(usn_list[mid]>key)
   high=mid-1;
  else
   low=mid+1;
}
return -1;
}
void student::search(string key)
{
fstream f1;
int pos,add;
pos=search_pri(key);
if(pos>=0)
{
add=add_list[pos];
f1.open("sample2.txt",ios::in);
f1.seekp(add,ios::beg);
buffer.erase();
getline(f1,buffer);
cout<<"Record found:\n"<<buffer<<endl;
cout<<"at pos="<<add;
}
else
cout<<"Record not found!!";
}
void student::del(string key)
{
fstream f1;
int pos,add,i;
pos=search_pri(key);
add=add_list[pos];
f1.open("sample2.txt");
f1.seekp(add,ios::beg);
f1.put('*');
f1.close();
for(i=pos;i<count;i++)
{
usn_list[i]=usn_list[i+1];
add_list[i]=add_list[i+1];
}
count--;
}
main()
{
student s;
int ch;
string key;
s.creat_pri();
cout<<"1.insert 2.search with primary 3.del 4.exit";
cin>>ch;
switch(ch)
{
case 1:s.insert();
       s.pack();
       s.write();
       break;
case 2:cout<<"Enter the key";
       cin>>key;
       s.search(key);
       break;
case 3:cout<<"Enter the key";
       cin>>key;
       s.del(key);
       break;
case 4: exit(0);
        break;
}
}
