//============================================================================
// Name        : lab2.cpp
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
	ofstream fp(fname.c_str(),ios::app);
	fp<<buffer<<endl;
	fp.close();
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
int main() {
	student s;
	string fname;
	int choice;

		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
		s.read();
		cout<<"enter the filename";
				cin>>fname;
		s.pack(fname);
			   break;
		case 2:
			s.unpack(fname);
				break;
		}
		case
	return 0;
}
