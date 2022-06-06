#pragma once
#include<iostream>
#include <string>
#include <queue>
using namespace std;

struct node
{
	int freq=0;
	char charector='~';
	node *left=NULL, *right=NULL;


};

struct compare {
	bool operator()(const node& a, const node& b) {
		return a.freq < b.freq;
	}
};

class encrypt
{
public:
	encrypt();
	void compress(string);
	~encrypt();

private:
	string text;
	priority_queue <node, vector<node>, compare> tree;
};

encrypt::encrypt()
{
}

inline void encrypt::compress(string Text)
{
	node a;
	text = Text;
	while (Text.size()!=0)
	{
		a.charector = Text[0];
		for (int i=0;i<Text.size();i++)
		{
			if (a.charector==Text[i])
			{
			}
		}


	}
}

encrypt::~encrypt()
{
}


