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
	vector<bool> compressed_code;
	string path;
	int extrabits;
	int size_orignal;
	double size_compresed;
	vector<char>compressed_text;
	vector<encryptstruct> detail;
public:
	void encrypt_text(string);
	void save(string,string);
	vector <char> return_compressed_text();
	int return_extrabit();
	vector<encryptstruct> return_detail();
	vector<bool>return_compressed_code();
	string return_path();
	int  return_original_size();
	int return_compresed_size();
	string return_original_text();
};

void Encrypt::encrypt_text(string text) {
	original_text = text;

	frequencytable a;
	a.table(text);
	vector<node> b = a.returnfrequencytable();
	encrytptree c;
	c.maketree(b);
	c.mytable();
	
	extrabits = 0;
	double tempa = (double)compressed_code.size() / 8;
	int tempb = compressed_code.size() / 8;
	double tempc = tempa - (double)tempb;
	while (tempc!=0)
	{
		
		compressed_code.push_back(0);
		tempa = (double)compressed_code.size() / 8;
		tempb = compressed_code.size() / 8;
		extrabits++;
		tempc = tempa - (double)tempb;
	}
	
	bool array[8];
	int check = 0;
	for (vector<bool>::iterator it=compressed_code.begin();it!=compressed_code.end();++it)
	{
		array[check] = *it;
		
		if (check==7)
		{
			int te=0;
			for (int i = 7; i >= 0; i--) {
				te = te + (2 ^ (array[i]));
			}
			check = 0;
			compressed_text.push_back(te);
		}
		else
		{
		check++;
		}
		
	}

}

void Encrypt::save(string mypath,string name) {
	path = mypath;
	mypath = mypath + name+".text";
	ofstream myfile;
	myfile.open(mypath);
	for (vector<char>::iterator i =compressed_text.begin() ; i!=compressed_text.end() ;++ i)
	{
		char a = *i;
		myfile <<a;
	}
	
	myfile.close();
	
	ofstream tree;
	mypath = "C:\\Users\\AhmadSanjar\\Documents\\Trees\\" + name + ".text";
	tree.open(mypath);
	for   (vector<encryptstruct>::iterator it=detail.begin();it!=detail.end();++it)
	{
		encryptstruct a = *it;
		tree << a.charecter;
		for (vector<bool>::iterator i=a.code.begin();i!=a.code.end();++i)
		{
			tree << *i;
		}
	

	}
	tree.close();
	mypath = "C:\\Users\\AhmadSanjar\\Documents\\Extrabit\\" + name + ".text";
	ofstream extrabit;
	extrabit.open(mypath);
	extrabit << extrabits;
	extrabit.close();

}

inline vector<char> Encrypt::return_compressed_text()
{
	return compressed_text;
}

inline int Encrypt::return_extrabit()
{
	return extrabits;
}

inline vector<encryptstruct> Encrypt::return_detail()
{
	return detail;
}

vector<bool> Encrypt::return_compressed_code()
{
	return compressed_code;
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
	size_compresed = compressed_code.size() / 8;
	return size_compresed;
}

inline string Encrypt::return_original_text()
{
	return original_text;
}



