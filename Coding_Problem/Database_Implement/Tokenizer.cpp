#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;

vector<string> tokenize_getline(const string& data, const char delimiter = ' ') {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) {
		result.push_back(token);
	}
	return result;
}

vector<string> tokenize_operator(const string& data) {
	vector<string> result;
	string token;
	stringstream ss(data);

	while (ss >> token) {
		result.push_back(token);
	}
	return result;
}

vector<string> tokenize_boost(const string& data, const string& dropped_delim = " ", const string& kept_delim = "") {
	boost::char_separator<char> sep(dropped_delim.c_str(), kept_delim.c_str(), boost::keep_empty_tokens);
	boost::tokenizer<boost::char_separator<char>> tokens(data, sep);

	vector<string> result{ begin(tokens), end(tokens) };
	return result;
}

int main() {
	std::string data = "Data1,Data2,Data3,Data4";
	vector<string> result = tokenize_getline(data, ',');
	for (auto& elem : result) {
		cout << elem << endl;
	}

	cout << endl;

	data = "Data1\nData2\nData3\nData4";
	result = tokenize_operator(data);
	for (auto& elem : result) {
		cout << elem << endl;
	}

	cout << endl;

	data = "Data1\nData2\n\tData3|Data4";
	result = tokenize_boost(data, "\n\t", "|");
	for (auto& elem : result) {
		cout << elem << endl;
	}

	return 0;
}