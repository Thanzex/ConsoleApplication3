#pragma once

class Block
{
public:
	Block();
	~Block();
	static int FindEnd(char*);

private:

};

Block::Block()
{
}

Block::~Block()
{
}

int Block::FindEnd(char* a)
 {
	int i = 0;
	for(;(std::find(end_operators.begin(), end_operators.end(), a[i + 1]) == end_operators.end()) && a[i+1] != '\0';i++)
		/*(std::find(Op::operators.begin(), Op::operators.end(), a[i + 1]) != Op::operators.end())*/
	{
	}	 
	return i+1;
 }