/*
철수는 달리기 게임을 만들기로 했다.
게임 내용은 다음과 같다.

게임 캐릭터는 게임이 시작되면 달리기를 시작하며, 주어진 시간(x)동안 달린다.
게임 캐릭터는 처음에 맨발로 달리고 있으며, 맨발로 달릴 때 초속 1 로 달린다.
게임이 시작하고 특정 시간(a) 이 되면 바닥에 신발이 생성된다.
게임 캐릭터는 이 신발을 착용하거나 지나칠 수 있다.
지나간 신발은 다시 장착 할 수 없다.

해당 신발을 착용하려면 일정 시간 (b)의 시간이 필요하다.(즉, 해당 시간 동안 달리지 않고 제자리에 있어야 한다. )
해당 신발을 착용하면 일정시간(c) 동안 해당 신발의 속도(d)로 달릴 수 있다.
신발은 하나만 착용할 수 있고 가장 최근에 착용한 신발만 적용이 된다. 또한 신발이 없을때는 맨발로 달리게 된다.(초속 1)
(신발을 벗거나 다른 신발로 바꿔 장착할 때 추가시간은 들지 않는다 )


이때 철수는 갈 수 있는 최대 거리를 구하려고 한다.
시작 할 때 모든 신발 정보가 주어진다고 했을 때 , X초 동안 갈 수 있는 최대 거리를 출력한다.

입력 >
첫 줄에는 구하고자 하는 X(0<X<=10000) 초가 주어진다.
두번째 줄에는 신발의 개수가 주어진다.
해당 신발 정보 하나당 하나의 신발이 생성된다.
다음 줄 부터 신발 정보가 주어진다. 신발 정보는 신발이
생성되는 시간 a초 ( 0<a<10000) 와 신발을 착용하기 위한
필요시간 b초( 0<b<10000) , 신발의 지속시간 c초(0<c<10000)
그리고 신발을 장착했을 때의 속도 d(0<d<100) 가 주어진다.

출력 >
X 초 동안 갈 수 있는 최대 거리를 출력한다.

입력 ex>
20
4
3 4 10 3 ( 달리기 시작후 3초뒤에 생성되며 장착에 4초가 필요하며, 장착시 10초동안 초속 3으로 달린다.)
4 1 4 2
10 2 55
15 1 3 7

출력 ex>
50

*/

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;
size_t timeGiven = 0;

class 신발
{
private:
	size_t generatingTime;
	size_t wearingTime;
	size_t duration;
	size_t speed;
public:
	신발(size_t a, size_t b, size_t c, size_t d);
	~신발() {}
	// 신기 전시간 + 지체되는 시간
	size_t StartingTime();
	// 주어진시간동안 버프받을 수 있는 최대 시간
	size_t BuffTime();
	// 버프시간동안 버프받고 갈수 있는 최대 거리
	float BuffDistance();
	// 사용하게 된다면 점유하게 되는 특정 시각
	pair<size_t,size_t> Occupy() const;
	// 손익분기점(시간)
	float BreakEvenPointTime();
	// 이 신발만으로 갈수 있는 거리
	float DistanceByShoe();
};

/* 손익분기점보다 생성 시간이 더 늦은 신발은 하나 더 신는게 좋다


*/

신발::신발(size_t a, size_t b, size_t c, size_t d)
{
	generatingTime = a;
	wearingTime = b;
	duration = c;
	speed = d;
}

size_t 신발::StartingTime()
{
	return generatingTime + wearingTime;
}

size_t 신발::BuffTime()
{
	size_t t = timeGiven - StartingTime();
	if (t >= BuffTime())
		return BuffTime();
	else
		return t;
}

float 신발::BuffDistance()
{
	return BuffTime() * speed;
}

pair<size_t, size_t> 신발::Occupy() const
{
	pair<size_t, size_t> p =
		make_pair(generatingTime, generatingTime + wearingTime);
	return p;
}

float 신발::BreakEvenPointTime()
{
	// 그냥 갔을때 최대거리
	float maxdist = timeGiven * 1;
	// 그냥 갔을때 y = x 라면 
	// 신발을 신으면 기울기를 속도로 하는 직선에 x 축으로 생성시간, 신는시간만큼 평행이동한다
	return speed * (maxdist - generatingTime - wearingTime);
}

float 신발::DistanceByShoe()
{
	return (generatingTime * 1) - (wearingTime * 1) + BuffDistance();
}

int main()
{
	cin >> timeGiven;
	int nInput;
	cin >> nInput;
	vector<신발> shoe;
	while (nInput--)
	{
		size_t a, b, c, d;
		cin >> a >> b >> c >> d;
		신발 tmp(a, b, c, d);
		shoe.push_back(tmp);
	}
	for ( size_t i = 0; i < shoe.size(); i++)
	{

	}
	return 0;
}