#pragma once


std::string SingleBlocksFirstPass(std::string input)
{
	/*
		Esegue il primo passaggio racchiudendo tutti i numeri e veriabili 
		tra parentesi. Prende la stringa completa come input.
		Scorre tutta la stringa, se trova qualcosa che non � un operatore o una parentesi
		lo racchiude tra parentesi, a meno che non ci siano gi�.
		Ritorna una seconda stringa modificata.
    */
	std::string parallel;
	for (int i = 0; i< input.length(); i++)
	{
		if (std::find(end_operators.begin(), end_operators.end(), input[i]) == end_operators.end()) { // se non trova l'operatore
			int ind = Block::FindEnd(&input[i], false); // chiede, scorrendo in avanti, l'indirizo dell'ultimo carattere del numero
			if (DEBUG) cout << "\nReading " << input[i] << " at position " << i << "\tfound end at " << input[i + ind] << " position " << i + ind;
			//Aggiunge, se non presente la parentesi aperta
			if (i > 0) {
				if (input[i - 1] == '(' && input[i + ind] == ')') { if (DEBUG)  cout << "\n\tparenthesis present, skipping"; }
				else { parallel += '('; if (DEBUG) cout << "\n\tAdding parenthesis"; }
			}
			else { parallel += '('; if (DEBUG) cout << "\n\tAdding parenthesis"; }
			// inserisce nella scrtinga di ritorno tutti i caratteri tra il primo e l'ultimo carattere del numero
			for (int j = 0; j < ind; j++)
			{
				if (DEBUG) cout << "\n\t\tAdding expression character " << input[i + j] << " iter: " << i;
				parallel += input[i + j];
			}
			//Aggiunge, se non presente la parentesi chiusa
			if (i > 0) {
				if (input[i - 1] == '(' && input[i + ind] == ')') {}
				else parallel += ')';
			}
			else parallel += ')';
			if (DEBUG) cout << "\n\tAdding end";
			i += ind - 1;
			if (DEBUG) cout << "\n\tNew position " << i;
		}
		else
		{
			//Ricopia parentesi preesistenti e gli operatori
			if (DEBUG) cout << "\nFound block terminator '" << input[i] << "', ignoring and adding.";
			parallel += input[i];
		}

	}
	return parallel;
}

std::string OperandPass(std::string input,std::string operands)	//Trova inizio e fine di un blocco adiacenti ad un operatore
{
	/*
		Prende la stringa con cui si sta lavorando e gli operatori richiesti.
		cerca nella stringa gli operatori richiesti, se trovati usa 
		Block::FindBlockEnd() per trovare la fine dei blocchi adiacenti,
		aggiunge una parentesi prima del blocco a sinistra dell'operatore
		ed una dopo il blocco a destra dell'operatore.
		Ritorna la stringa modificata.
	*/
	if (DEBUG) cout << "\nOperators : " << operands << "\n";
	for (int i = 0; i < input.length(); i++)
	{
		if (DEBUG) cout << "\nAnalysing char " << input[i] << " num " << i;
		int indexa = 0;
		int indexb = 0;
		if (std::find(operands.begin(), operands.end(), input[i]) != operands.end()) // se trova un operatore
		{
			if (DEBUG) cout << "\nFound * at " << i;
			indexa = Block::FindBlockEnd(input, i, false); // riceve l'indirizzo per la prima parentesi
			if (DEBUG) cout << "\nIndexA: " << indexa << " char: " << input[indexa];
			indexb = Block::FindBlockEnd(input, i, true); // riceve l'indirizzo della seconda parentesi
			if (DEBUG) cout << "\nIndexB: " << indexb << " char: " << input[indexb];
			input.insert(indexa, 1, ')'); //inserisce la parentesi
			if (DEBUG) cout << "\nAdding parenthesis )";
			input.insert(indexb, 1, '('); //...
			if (DEBUG) cout << "\nAdding parenthesis (";
			if (DEBUG) cout << "\nResulting string: " << input;
			i++;
		}
	}
	return input;
}