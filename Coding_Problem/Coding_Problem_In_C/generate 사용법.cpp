// 함수 객체는 작업 결과를 스스로 저장할 수 있으며 
// 매 호출마다 지역적으로 생성될 수 있으므로 
// 멀티 스레드 환경에서도 잘 동작한다.

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