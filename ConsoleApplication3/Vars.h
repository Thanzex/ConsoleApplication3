#pragma once

class Var
{
public:
	Var(std::string, float);
	Var(std::string);

	float value;
	std::string name;
	~Var();

private:

};



inline Var::Var(std::string n , float v)
{
	name = n;
	value = v;
}

inline Var::Var(std::string n)
{
	name = n;
	value = NULL;
}

Var::~Var()
{
}