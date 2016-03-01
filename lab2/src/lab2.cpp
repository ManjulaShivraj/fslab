//============================================================================
// Name        : fixlength.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
using namespace std;

class student{
	string name,usn,branch,sem;
	public:
	void read();
	void pack(string fname);
	void unpack(string fname);
	int search(string key,string filename);
	int modify(string key,string filename);
};
void student::read()
{
			cout<<"enter the name";
			cin>>name;
			cout<<"enter the usn";
			cin>>usn;
			cout<<"enter the branch";
			cin>>branch;
			cout<<"enter the sem";
			cin>>sem;

}
void student::pack(string fname)
{
	//fstream fp;
	string buffer;
	buffer=name+'|'+usn+'|'+branch+'|'+sem;
	buffer.resize(100,'$');
	ofstream f1(fname.c_str(),ios::app);
	f1<<buffer<<endl;
	f1.close();
}
void student::unpack(string fname)
{
	string temp;
	ifstream f1(fname.c_str());
	getline(f1,name,'|');
	getline(f1,usn,'|');
	getline(f1,branch,'|');
	getline(f1,sem,'$');

	f1.close();
}
int student::search(string key,string fname)
{
    student s[10];
    int i=0;
    ifstream f1(fname.c_str());
    while(!f1.eof())
    {
        cout<<"in search"<<endl;
        s[i].unpack(fname);
        if(key==s[i].usn)
        {
            cout<<"record found\n";
            cout<<s[i].usn<<"\t"<<s[i].name;
            break;
        }
        i++;
    }
    f1.close();
    return 0;
}
int student::modify(string key,string fname)
{
  int pos;
  int var;
  fstream f1;
  pos = search(key,fname);


  if(pos>0)
 {
   cout<<"what should be modified?"<<endl;
   cout<<"1.usn  2.name 3.branch 4.sem"<<endl;
   cin>>var;
   switch(var)
   {
     case 1:cin>>usn;
            break;
     case 2:cin>>name;
            break;
     case 3:cin>>branch;
            break;
     case 4:cin>>sem;
            break;
   }
 }

f1.open(fname.c_str(),ios::out);
f1.seekp(pos);
pack(fname);

//f1<<buf;
f1.close();
return 0;
}

int main() {
	student s;
	string fname,key;
	int choice;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
		s.read();
		cout<<"enter the filename"<<endl;
		cin>>fname;
		s.pack(fname);
			   break;
		case 2:
			cout<<"enter the usn"<<endl;
			cin>>key;
			cout<<"enter the filename"<<endl;
			cin>>fname;
			s.modify(key,fname);
			//s.search(key,fname);
			break;
		case 3:

			break;
		}
}
