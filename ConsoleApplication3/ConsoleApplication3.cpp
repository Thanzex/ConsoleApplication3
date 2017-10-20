// ConsoleApplication3.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <map>

using namespace std;
float ExecuteOperation(std::string, int);

#include "Variables.h"
#include "Block.h"
#include "Operators.h"
#include "Vars.h"
#include "functions.h"
int main()
{
	std::string input;
	std::string working;
	std::string second;
	//std::vector<Block> blocks;
	//std::vector<Op> operationsVector;

	float value;

	do
	{
		if (!variablesMap.empty())
		{
			cout << "\nVariables: \n";
			for (const auto &p : variablesMap) {
				std::cout << "\n\tvariables[" << p.first << "] = " << p.second << '\n';
			}
		}
		cout << "\nType Math Expression: \n >";
		cin >> input;
		working = SingleBlocksFirstPass(input);
		working = OperandPass(working, "^");		//Raggruppa i blocchi a destra e sinistra delle operazioni in ordine di esecuzione
		working = OperandPass(working, "*/");
		working = OperandPass(working, "+-");
		cout << "\n" << working << "\n";
		if (input == "quit")
		{
			GotToExit = true;
		}
		else if (input == "clear")
		{
			system("cls");
			variablesMap.clear();
		}

		else if (std::find(working.begin(),working.end(),'=')!=working.end())	//ASSEGNAZIONE
		{
			if (!AssignVariable(variablesMap, working))
			{
				cout << "\nAssegnazione non valida";
			}
		}

		else
		{
			Block inputBlock = Block(working);
			if (inputBlock.isExpression())
			{
				value = 0;
				/*for (int i = 0; i < working.length(); i++)
				{
					value = ExecuteOperation(working,i);
				}*/

				int IndexFirstOp = Block::FindBlockEnd(working, working.length() - 2, true) - 1;
				value = ExecuteOperation(working, IndexFirstOp);
				cout << "\nFinal Result: " << value;
			}
			else
				cout << "\nError.";
		}
		
	} while (!GotToExit);

	//NOPE
	/*for (int i = 0; i < working.length(); i++)
	{
		if (std::find(operations.begin(), operations.end(), working[i]) != operations.end())
		{
			int begin = Block::FindBlockEnd(working, i, true);
			Block fblock = Block(working.substr(begin, (i)-begin));
			fblock.Evaluate();
			blocks.push_back(fblock);
			int end = Block::FindBlockEnd(working, i, false);
			Block sblock = Block(working.substr(i + 1, end - (i)));
			sblock.Evaluate();
			blocks.push_back(sblock);
			operationsVector.push_back(Op(Block(working.substr(begin, (i)-begin)), Block(working.substr(i + 1, end - (i))),working[i]));
		}
	}*/
	cout << "\n";
	return 1;
}
