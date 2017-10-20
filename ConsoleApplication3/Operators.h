#pragma once

class Op
{
	Block firstBlock;
	Block secondBlock;
	char action;
public:
	Op();
	Op(Block, Block, char);
    ~Op();
	float Execute();	
private:
};

Op::Op()
{
}

Op::Op(Block a, Block b, char c)
{
	firstBlock = a;
	secondBlock = b;
	action = c;
	if (DEBUG) cout << "\n\tNew operation " << a.rawText << action << secondBlock.rawText;
}

Op::~Op()
{
}

float Op::Execute()
{
	if (DEBUG2) cout << "\n\t\tExecuting Internal";
	if (DEBUG2) cout << "\n\t\tEvaluating First Block...";
	firstBlock.Evaluate();
	if (DEBUG2) cout << "\n\t\tEvaluating Seond Block...";
	secondBlock.Evaluate();
	float result;
	switch (action)
	{
	case '+':
		if (DEBUG) cout << "\nExecuting "<<firstBlock.value <<"+" <<secondBlock.value;
		result = firstBlock.value + secondBlock.value;
		break;
	case '-':
		if (DEBUG) cout << "\nExecuting " << firstBlock.value << "-" << secondBlock.value;
		result = firstBlock.value - secondBlock.value;
		break;
	case '*':
		if (DEBUG) cout << "\nExecuting " << firstBlock.value << "*" << secondBlock.value;
		result = firstBlock.value * secondBlock.value;
		break;
	case '/':
		if (DEBUG) cout << "\nExecuting " << firstBlock.value << "/" << secondBlock.value;
		result = firstBlock.value / secondBlock.value;
		break;
	case '^':
		cout << "\nExecuting " << firstBlock.value << "^" << secondBlock.value;
		if (DEBUG) result = pow(firstBlock.value, secondBlock.value);
		break;
	default:
		break;
	}

	return result;
}
