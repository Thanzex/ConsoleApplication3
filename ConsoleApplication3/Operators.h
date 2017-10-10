#pragma once

class Op
{
public:
	std::vector<char> operators = { '=','+','-','*','/' };
	Op();
	
	~Op();

private:

};

Op::Op()
{
}

Op::~Op()
{
}