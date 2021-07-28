#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<conio.h>

class Employee
{
public:
char name[20];
 long int code , salary;
public:
void input()
{
cout<<"\nEnter name : ";
gets(name);
cout<<"Enter code : " ;
cin>>code;
cout<<"Enter salary : ";
cin>>salary;
}
void write()
{
Employee e;
fstream a;

a.open("mk3.dat",ios::binary|ios::out);
e.input();
a.write((char *)&e,sizeof(e));
cout<<"Data written successfully .\n";
a.close();
}
void read()
{
Employee e;
fstream a;

a.open("mk3.dat",ios::binary|ios::in);
if(!a)
{
cout<<"Error : while opening the file !!!\nFile not found !\n";
return;
}
else
{
cout<<"\n";
cout<<"Name"<<"\t"<<"Code"<<"\t"<<"Salary"<<endl;
cout<<"----"<<"\t"<<"----"<<"\t"<<"------"<<endl;
while(a.read((char *)& e,sizeof(e))){
cout<<e.name<<"\t"<<e.code<<"\t"<<e.salary<<endl;}
}

cout<<"Data read successfully .\n";
a.close();
}
void append()
{
Employee e;
fstream a;
a.open("mk3.dat",ios::app);
if(!a)
{

cout<<"Error : while opening the file !!!";
}
e.input();
a.write((char *)& e,sizeof(e));
cout<<"Data appended successfully .\n";
a.close();
}
void update()
{
Employee e;
fstream a;
int nm;
cout<<"Enter Employee code to update : ";
cin>>nm;

a.open("mk3.dat",ios::in | ios::out | ios::binary);
if(!a){
cout<<"Error : while opening the file !!!";
}
while(a.read((char *)&e, sizeof(e)))
{
if(e.code == nm)
{
cout<<"\n";
cout<<"Name"<<"\t"<<"Code"<<"\t"<<"Salary"<<endl;
cout<<"----"<<"\t"<<"----"<<"\t"<<"------"<<endl;
cout<<e.name<<"\t"<<e.code<<"\t"<<e.salary<<endl;
e.input();
int pos = sizeof(e);
a.seekp(-pos, ios::cur);
a.write((char *)&e, sizeof(e));
}
}
cout<<"Data updated successfully .\n";
a.close();
}
void search ()
{
Employee e;
fstream a;
int g;
cout<<"Enter Employee code to search : ";
cin>>g;
a.open("mk3.dat",ios::in);
if(!a)
{
cout<<"Error : while opening the file !!!";
}
while(a.read((char *)&e, sizeof(e)))
{
if(e.code == g)
{
cout<<"\n";
cout<<"Name"<<"\t"<<"Code"<<"\t"<<"Salary"<<endl;
cout<<"----"<<"\t"<<"----"<<"\t"<<"------"<<endl;
cout<<e.name<<"\t"<<e.code<<"\t"<<e.salary<<endl;
}}
cout<<"Data searched successfully .\n";
a.close();
}
void deletedata()
{
Employee e;
ofstream z;
fstream a;
int j;
cout<<"Enter Employee code to delete : ";
cin>>j;
a.open("mk3.dat",ios::in );
z.open("mk5.dat",ios::out);
if(!a)
{
cout<<"Error : while opening the file !!!";
}
else{

while(a.read((char *)&e, sizeof(e)))
{
if(e.code != j){
  z.write((char *)&e , sizeof(e));
}}
a.close();
z.close();

remove("mk3.dat");
rename("mk5.dat","mk3.dat");
cout<<"Data deleted succesfully.";
  }}

void deletefile()
{
remove("mk3.dat");
cout<<"File deleted successfully.";
}

};

void main()
{
clrscr();
Employee e;

fstream a;
fstream z;
int n;
cout<<" 1. write data in file\n";
cout<<" 2. read data in file\n";
cout<<" 3. append data in file\n";
cout<<" 4. update data in file\n";
cout<<" 5. search data in file\n";
cout<<" 6. delete data in file\n";
cout<<" 7. delete file\n";
cout<<" 8. exit..\n";

do
{
cout<<"\nEnter your choice : ";
cin>>n;

   switch(n)
   {
   case 1: e.write();
	break;
   case 2: e.read();
	break;
   case 3: e.append();
	break;
   case 4: e.update();
	break;
   case 5: e.search();
	break;
   case 6: e.deletedata();
	break;

   case 7: e.deletefile();
	  break;
   case 8: cout<<"Exit...";
	break;
   }
}
while(n<8);

getch();
}