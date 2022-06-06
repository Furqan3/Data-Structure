#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include<fstream>
#include "FrequencyTable.h"
#include "Tree.h"
using namespace std;
struct encryptstruct
{
	int frequency = 0;
	char charecter = '\n';
	vector<bool> code;
};
class Encrypt {
	string original_text;
	vector<bool> compressed_text;
	string path;
	int size_orignal;
	int size_compresed;
	vector<encryptstruct> detail;
public:
	void encrypt_text(string);
	void save(string);
	vector<encryptstruct> return_detail();
	vector<bool>return_compressed_text();
	string return_path();
	int return_original_size();
	int return_compresed_size();
	string return_original_text();
};

void Encrypt::encrypt_text(string text) {
	original_text = text;
	size_orignal = text.size();
	frequencytable a;
	a.table(text);
	vector<node> b = a.returnfrequencytable();
	encrytptree c;
	c.maketree(b);
	c.mytable();
	vector<code> mycode = c.returncode();
	for (vector<node>::iterator it =b.begin();it!=b.end(); ++it)
	{
		node a = *it;
		encryptstruct b;
		b.charecter = a.value;
		b.frequency = a.frequency;
		cout << a.value << "->" << a.frequency << "->";
		detail.push_back(b);
		for (vector<code>::iterator i = mycode.begin(); i != mycode.end(); ++i)
		{
			code f = *i;
			if (a.value==f.charecter)
			{
				vector<bool> a = f.path;

				for (vector<bool>::iterator i = a.begin(); i != a.end(); ++i) {
					b.code.push_back(*i);
					cout << *i;
				}
			}
			
			

		}
		cout << "\n";
	}
	
	for (int  i = 0; i < text.size(); i++)
	{
		for (vector<code>::iterator it = mycode.begin(); it != mycode.end(); ++it) {
			code a=*it;

			if (a.charecter==text[i])
			{
				for (vector<bool>::iterator ij = a.path.begin(); ij != a.path.end(); ++ij)
				{
					compressed_text.push_back(*ij);
					cout << *ij;
				}
			}
		}
	}
}

void Encrypt::save(string mypath) {
	path = mypath;
	bool a[3] = { 0, 1, 1 };

	path = path + ".bin";
	ofstream myfile;
	myfile.open("E:\exam.BIN");
	for (int i = 0; i < 3; i++)
	{
		myfile << a[i];
	}
	myfile.close();

	cout << "\n Display";
	bool line;
	ifstream myfile("E:\exam.BIN");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> line;
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";

}

inline vector<encryptstruct> Encrypt::return_detail()
{
	return detail;
}

vector<bool> Encrypt::return_compressed_text()
{
	return compressed_text;
}

inline string Encrypt::return_path()
{
	return path;
}

inline int Encrypt::return_original_size()
{
	size_orignal = original_text.size();
	return size_orignal;
}

inline int Encrypt::return_compresed_size()
{
	size_compresed = compressed_text.size() / 8;
	return size_compresed;
}

inline string Encrypt::return_original_text()
{
	return original_text;
}



