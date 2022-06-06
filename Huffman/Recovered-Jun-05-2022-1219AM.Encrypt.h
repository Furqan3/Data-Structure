#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "FrequencyTable.h"
#include "Tree.h"
using namespace std;

struct encryptdata
{
	int frequency = 0;
	char value='\n';
	vector<bool>code;
};
class encrypt {
	vector<>
};

void encrypt(string text){
	frequencytable a;
	cout << "Original text:"<< text << endl;
	cout<< "Size->"<<text.size()<<" Bytes\n" ;
	a.table(text);
	vector<node> x=a.returnfrequencytable();
	encrytptree b;
	b.maketree(x);	
	b.mytable();
	vector<code> mycode=b.returncode();
	int Size=0;
	cout << "Compressed :\n" ;
	for (int i = 0; i <text.size(); i++)
	{
		for (vector<code>::iterator it = mycode.begin(); it !=mycode.end(); ++it)
		{
			code a = *it;
			if (a.charecter==text[i])
			{
				for (vector<bool>::iterator ij = a.path.begin(); ij != a.path.end(); ++ij)
				{
					Size++;
					cout << *ij;
				}
			}

		}

	}
	cout << "\nSize->" << Size/8<< " Bytes";
}

