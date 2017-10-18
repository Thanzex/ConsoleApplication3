#pragma once

class Block
{
public:
	Block(std::string);
	void Evaluate();
	~Block();
	static int FindEnd(char*, int);
	static int FindBlockEnd(std::string, int, int);

	std::string rawText;
	float value = NULL;
	char content;
	std::string name;

private:

};

Block::Block(std::string a) // Crea un blocco passando il testo
{
	rawText = a;
}

inline void Block::Evaluate()
{
	
}

Block::~Block()
{
}

int Block::FindEnd(char* a, int c) // trova inizio e fine di numero
 {
	int i = 0;
	//magia
	for (; (std::find(end_operators.begin(), end_operators.end(), a[(c) ? i - 1 : i + 1]) == end_operators.end()) && a[(c) ? i - 1 : i + 1] != '\0'; (c) ? i-- : i++) {}
	return (c) ? i - 1 : i + 1;
 }

inline int Block::FindBlockEnd(std::string a, int b,int c)  // Trova parentesi iniziali e finai di blocco
{

	/*
	 prende la stringa e la posizione corrente come parametri a e b,
	 inizia a scorrere avanti o indietro in base al flag c ( true = indietro )
	 conta il numero di paretesi aperte e chiuse che trova, quando si eguagliano 
	 allora ha raggiunto la la fine del blocco desiderato
	*/
	if (DEBUG) cout << "\n\tgot string, char num " << b << " = " << a[b] << " backwards: " << c;
	int nopen = 0;
	int nclose = 0;
	int i = b;
	for (; i<a.length()&&i>=0 ; (c) ? i-- : i++)	//scorre fino alla fine del vettore
	{
		if (DEBUG) cout << "\n\t\tIter " << i << " : char " << a[i];
		if (a[i] == '(') {							//conta parentesi aperta
			nopen++; 
			if (DEBUG) cout << "\n\t\tfound open, incrementing";
		}
		else if (a[i] == ')') {						//conta parentesi chiusa
			nclose++;
			if (DEBUG) cout << "\n\t\tfound close, incrementing";
		}
		if (DEBUG) cout << "\n\t\tnopen: " << nopen << " nclose:" << nclose;
		//controlla se si eguagliano
		if (nopen!=0 || nclose !=0) if (nopen == nclose) { if (DEBUG) cout << "\n\tBreaking"; break; }
	}
	if (DEBUG) cout << "\n\treturn "<< i;
	return i;
}
