#pragma once
 
class Block
{
public:
	Block();
	~Block();
	char& FindEnd(char&);

private:

};

Block::Block()
{
}

Block::~Block()
{
}

char& Block::FindEnd(char& a)
 {
	 int i=0;
	 while(std::find(Op::operators[0],Op::operators[4],a[i+1]))
	 {}	 
 }