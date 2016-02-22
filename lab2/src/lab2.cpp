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
	void pack(char *fname);
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
void student::pack(char *fname)
{
	fstream fp;
	string buffer;
	buffer=name+'|'+usn+'|'+branch+'|'+sem;
	buffer.resize(100,'$');
	fp.open(fname,ios::out);
	fp<<buffer;
	fp.close();
}
int main() {
	student s;
	char *fname;
	int choice;

		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:s.read();
			   break;
		case 2:cout<<"enter the filename";
				cin>>fname;
				s.pack(fname);
				break;
		}
	return 0;
}
