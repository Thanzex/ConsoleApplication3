// ConsoleApplication3.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;


#include "Variables.h"
#include "Block.h"
#include "Operators.h"
#include "Vars.h"
int main()
{
	std::string input;
	std::string parallel;
	int pos = 0;
	cout << "Insert Math Expression: \n >";
	cin >> input;

	for (int i =0 ; i< input.length() ; i++)
	{
		int ind = Block::FindEnd(&input[i]);
		cout << "\n" << ind;
		parallel += '(';
		for (int j = 0; j < ind; j++)
		{
			parallel += input[i + j];
		}
		parallel += ')'; 
		parallel += input[i+ind];
		i +=ind;

	}

	cout << "\n" << parallel;

	
    
}

