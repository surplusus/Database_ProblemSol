#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#pragma region STATEMENT
//Token type enum
typedef enum {
	TOKEN_STRING,
	TOKEN_NUMBER
} TOKEN_TYPE;
//Token struct
typedef struct {
	TOKEN_TYPE type; // sort of token
	union {			  // Make as union cuz we use one type
		string string;
		double number;
	};
	bool isArray;
} TOKEN;
#define TOKEN_COUNT 20
typedef struct {
	TOKEN tokens[TOKEN_COUNT];
} JSON;
#pragma endregion

string ReadFile(char *fileName, int *readSize);
void ParseJSON(string doc, int size, JSON *json);
int main()
{

	return 0;
}

string ReadFile(char *fileName, int * readSize)
{
	ifstream inFile(fileName);
	if (inFile.is_open() == 0)
	{
		cout << "Not exist file" << endl;
		return nullptr;
	}
	char buffer[300];
	string sbuffer;
	while (!inFile.eof())
	{
		inFile.getline(buffer, 200);
		sbuffer += buffer;
	}
	*readSize = sbuffer.size();
	return sbuffer;
}

void ParseJSON(string doc, int size, JSON * json)
{
	int tokenIndex = 0;	// token Index
	int pos = 0;		// variable

	if (doc[pos] != '{')
		return;

	pos++;		// to the next character

	while (pos < size)	//repeat as much as size of file
	{
		switch (doc[pos])
		{
		case '"' :	// start symbol of text
		{
			int quotationIdx = doc.find('"', pos+1);
			if (quotationIdx == string::npos)
				break;
			string strbuffer = doc.substr(pos, quotationIdx);
			
			// Save value into token array
			//(TOKEN_STRING)
			json->tokens[tokenIndex].type = TOKEN_STRING;
			// (save string)
			json->tokens[tokenIndex].string = strbuffer;

			// increase token index
			tokenIndex++;
			pos += strbuffer.size() + 1;
		}
		break;
		}

		// next to the other character
		pos++;
	}
}
