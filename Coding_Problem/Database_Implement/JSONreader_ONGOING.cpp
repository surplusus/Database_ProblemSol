#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Token type enum
typedef enum {
	TOKEN_STRING,
	TOKEN_NUMBER
} TOKEN_TYPE;
//Token struct
typedef struct _TOKEN{
	TOKEN_TYPE type; // sort of token
	union {			  // Make as union cuz we use one type
		string string;
		double number;
	};
	bool isArray;
} TOKEN;
#define TOKEN_COUNT 20
typedef struct _JSON{
	TOKEN tokens[TOKEN_COUNT];
} JSON;
//File Size
const int FILE_SIZE = 500;


string ReadFile(const char *fileName, int * readSize)
{
	ifstream inFile(fileName);
	if (inFile.is_open() == 0)
	{
		cout << "Not exist file" << endl;
		return nullptr;
	}
	string tmp;
	string sbuffer;
	while (!inFile.eof())
	{
		inFile >> tmp;
		sbuffer += tmp;
	}
	*readSize = sbuffer.size();
	return sbuffer;
}

JSON * ParseJSON(string doc, int size)
{
	int tokenIndex = 0;	// token Index
	int pos = 0;		// string index position variable
	pos = doc.find('{', 0);
	if (pos == string::npos)
		return nullptr;

	pos++;		// to the next character
	JSON * json = new JSON;
	while (pos < size)	//repeat as much as size of file
	{
		switch (doc[pos])
		{
		case '"' :	// start symbol of text
		{
			int quoNextIdx = doc.find('\"', pos+1); // find '"' starting from pos+1
			if (quoNextIdx == string::npos)  // if not found '"', return string::npos
				break;
			string strbuffer = doc.substr(pos + 1, quoNextIdx - (pos + 1)); // substr = return substring(extract from string)
			
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
	return json;
}

void freeJSON()	// WE DON'T USE C, WE USE C++. SO WE DON'T NEED THIS LINE
{
	//void freeJSON(JSON *json)	// free JSON
	//{
	//	for (int i = 0; i < TOKEN_COUNT; i++)
	//	{
	//		if (json->tokens[i].type == TOKEN_STRING) // if TOKENTYPE is string
	//			free(json->tokens[i].string);	// dynamic memory off
	//	}
	//}
}

int main()
{
	int size; // file size

	// read from JSON file, get the size of JSON
	string doc = {};
	doc = ReadFile("example.json", &size);
	if (doc[0] == '\0')
		return -1;

	// JSON struct declaration & initiation

	JSON * json = ParseJSON(doc, size);

	cout << "Title: " << json->tokens[1].string << endl;
	cout << "Genre: " << json->tokens[3].string << endl;
	cout << "Director: " << json->tokens[5].string << endl;

	return 0;
}