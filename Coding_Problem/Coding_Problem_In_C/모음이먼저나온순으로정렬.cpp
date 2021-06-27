#include <iostream>
#include <tuple>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <hash_map>

using namespace std;

char vowels(string a)
{
	for (const char it : a)
	{
		if (it == 'a' || it == 'i' || it == 'u' || it == 'e' || it == 'o')
			return it;
	}
	return NULL;
}

string findBest(string a, string b, string c)
{
	// ���� ������ ������ ����
	// �� ������ ���ٸ� ���̰� �� ����
	auto q = min({
		make_tuple(vowels(a), -(int)a.size(), a),
		make_tuple(vowels(b), -(int)b.size(), b),
		make_tuple(vowels(c), -(int)c.size(), c)
		});
	return get<2>(q);
}

int main()
{

	cout << findBest("sdass", "fdas", "qwer") << endl;
	
	return 0;
}