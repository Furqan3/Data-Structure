#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "DecryptTree.h"
using namespace std;
struct tree {
	char charecter;
	tree *left = NULL, *right = NULL;
};

class decrypttree
{
	tree * root;
public:
	void make_decrypt_tree(string);
};

void decrypttree::make_decrypt_tree(string name) 
{
	name = "C:\\Users\\AhmadSanjar\\Documents\\Trees\\" + name;
	ifstream myfile(name);
	string line;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}

	else cout << "Unable to open file";
	
}