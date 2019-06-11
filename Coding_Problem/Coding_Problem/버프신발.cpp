/*
ö���� �޸��� ������ ������ �ߴ�.
���� ������ ������ ����.

���� ĳ���ʹ� ������ ���۵Ǹ� �޸��⸦ �����ϸ�, �־��� �ð�(x)���� �޸���.
���� ĳ���ʹ� ó���� �ǹ߷� �޸��� ������, �ǹ߷� �޸� �� �ʼ� 1 �� �޸���.
������ �����ϰ� Ư�� �ð�(a) �� �Ǹ� �ٴڿ� �Ź��� �����ȴ�.
���� ĳ���ʹ� �� �Ź��� �����ϰų� ����ĥ �� �ִ�.
������ �Ź��� �ٽ� ���� �� �� ����.

�ش� �Ź��� �����Ϸ��� ���� �ð� (b)�� �ð��� �ʿ��ϴ�.(��, �ش� �ð� ���� �޸��� �ʰ� ���ڸ��� �־�� �Ѵ�. )
�ش� �Ź��� �����ϸ� �����ð�(c) ���� �ش� �Ź��� �ӵ�(d)�� �޸� �� �ִ�.
�Ź��� �ϳ��� ������ �� �ְ� ���� �ֱٿ� ������ �Ź߸� ������ �ȴ�. ���� �Ź��� �������� �ǹ߷� �޸��� �ȴ�.(�ʼ� 1)
(�Ź��� ���ų� �ٸ� �Ź߷� �ٲ� ������ �� �߰��ð��� ���� �ʴ´� )


�̶� ö���� �� �� �ִ� �ִ� �Ÿ��� ���Ϸ��� �Ѵ�.
���� �� �� ��� �Ź� ������ �־����ٰ� ���� �� , X�� ���� �� �� �ִ� �ִ� �Ÿ��� ����Ѵ�.

�Է� >
ù �ٿ��� ���ϰ��� �ϴ� X(0<X<=10000) �ʰ� �־�����.
�ι�° �ٿ��� �Ź��� ������ �־�����.
�ش� �Ź� ���� �ϳ��� �ϳ��� �Ź��� �����ȴ�.
���� �� ���� �Ź� ������ �־�����. �Ź� ������ �Ź���
�����Ǵ� �ð� a�� ( 0<a<10000) �� �Ź��� �����ϱ� ����
�ʿ�ð� b��( 0<b<10000) , �Ź��� ���ӽð� c��(0<c<10000)
�׸��� �Ź��� �������� ���� �ӵ� d(0<d<100) �� �־�����.

��� >
X �� ���� �� �� �ִ� �ִ� �Ÿ��� ����Ѵ�.

�Է� ex>
20
4
3 4 10 3 ( �޸��� ������ 3�ʵڿ� �����Ǹ� ������ 4�ʰ� �ʿ��ϸ�, ������ 10�ʵ��� �ʼ� 3���� �޸���.)
4 1 4 2
10 2 55
15 1 3 7

��� ex>
50

*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
size_t timeGiven = 0;

class �Ź�
{
private:
	size_t generatingTime;
	size_t wearingTime;
	size_t duration;
	size_t speed;
public:
	�Ź�(size_t a, size_t b, size_t c, size_t d);
	~�Ź�() {}
	// �ű� ���ð� + ��ü�Ǵ� �ð�
	size_t StartingTime();
	// �־����ð����� �������� �� �ִ� �ִ� �ð�
	size_t BuffTime();
	// �����ð����� �����ް� ���� �ִ� �ִ� �Ÿ�
	float BuffDistance();
	// ����ϰ� �ȴٸ� �����ϰ� �Ǵ� Ư�� �ð�
	pair<size_t,size_t> Occupy() const;
	// ���ͺб���(�ð�)
	float BreakEvenPointTime();
	// �� �Ź߸����� ���� �ִ� �Ÿ�
	float DistanceByShoe();
};

/* ���ͺб������� ���� �ð��� �� ���� �Ź��� �ϳ� �� �Ŵ°� ����


*/

�Ź�::�Ź�(size_t a, size_t b, size_t c, size_t d)
{
	generatingTime = a;
	wearingTime = b;
	duration = c;
	speed = d;
}

size_t �Ź�::StartingTime()
{
	return generatingTime + wearingTime;
}

size_t �Ź�::BuffTime()
{
	size_t t = timeGiven - StartingTime();
	if (t >= BuffTime())
		return BuffTime();
	else
		return t;
}

float �Ź�::BuffDistance()
{
	return BuffTime() * speed;
}

pair<size_t, size_t> �Ź�::Occupy() const
{
	pair<size_t, size_t> p =
		make_pair(generatingTime, generatingTime + wearingTime);
	return p;
}

float �Ź�::BreakEvenPointTime()
{
	// �׳� ������ �ִ�Ÿ�
	float maxdist = timeGiven * 1;
	// �׳� ������ y = x ��� 
	// �Ź��� ������ ���⸦ �ӵ��� �ϴ� ������ x ������ �����ð�, �Ŵ½ð���ŭ �����̵��Ѵ�
	return speed * (maxdist - generatingTime - wearingTime);
}

float �Ź�::DistanceByShoe()
{
	return (generatingTime * 1) - (wearingTime * 1) + BuffDistance();
}

int main()
{
	cin >> timeGiven;
	int nInput;
	cin >> nInput;
	vector<�Ź�> shoe;
	while (nInput--)
	{
		size_t a, b, c, d;
		cin >> a >> b >> c >> d;
		�Ź� tmp(a, b, c, d);
		shoe.push_back(tmp);
	}
	for ( size_t i = 0; i < shoe.size(); i++)
	{

	}
	return 0;
}