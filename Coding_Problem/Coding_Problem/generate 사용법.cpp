// �Լ� ��ü�� �۾� ����� ������ ������ �� ������ 
// �� ȣ�⸶�� ���������� ������ �� �����Ƿ� 
// ��Ƽ ������ ȯ�濡���� �� �����Ѵ�.

#include <algorithm>
#include <vector>
using namespace std;

struct fibo {

private:
	int i1, i2;
public:
	fibo() : i1(1), i2(1) { }
	int operator()() {
		int t;
		t = i1 + i2;
		i1 = i2;
		i2 = t;
		return t;
	}
};

int main()
{
	vector<int> vi;
	generate(vi.begin(), vi.end(), fibo());
	return 0;
}