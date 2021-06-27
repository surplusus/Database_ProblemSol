#include <iostream>

template <class Derived>
struct Character
{
	// Template Mathod
	void ReadyToBattle();
	// 상속 받은 클래스에서 수정할 수 없도록 final 키워드를 붙였습니다.
	virtual void StartBodyTraining() final;
	// 무기준비
	virtual void PrepareWeapon() = 0;
	// 갑옷준비
	virtual void PrepareArmor() = 0;
	// 만약 Hook 함수에 override 가 일어나면 파생클래스 함수 실행
	void DoPrepareOther();
	// 이 메소드는 "후킹(Hooking)" 용도로 사용합니다.
	virtual void PrepareOther() {};
};

template<class Derived>
void Character<Derived>::DoPrepareOther()
{
	if (&Derived::PrepareOther != &Character::PrepareOther)
		PrepareOther();
}

struct Soldier : public Character<Soldier>
{
	virtual void PrepareWeapon();
	virtual void PrepareArmor();
	virtual void PrepareOther() override;
};

struct Archer : public Character<Archer>
{
	virtual void PrepareWeapon();
	virtual void PrepareArmor();
};

template<class Derived>
void Character<Derived>::ReadyToBattle()
{
	StartBodyTraining();
	PrepareWeapon();
	PrepareArmor();
	DoPrepareOther();
}

template<class Derived>
void Character<Derived>::StartBodyTraining()
{
	std::cout << "체력을 단련합니다." << std::endl;
}


void Soldier::PrepareWeapon()
{
	std::cout << "총을 준비합니다." << std::endl;
}

void Soldier::PrepareArmor()
{
	std::cout << "군복으로 환복합니다." << std::endl;
}

void Soldier::PrepareOther()
{
	std::cout << "눈이오니 눈을 씁니다." << std::endl;
}

void Archer::PrepareWeapon()
{
	std::cout << "활을 준비합니다." << std::endl;
}

void Archer::PrepareArmor()
{
	std::cout << "가벼운 갑옷을 입습니다." << std::endl;
}

int main() {
	Archer archer;
	Soldier soldier;

	archer.ReadyToBattle();
	std::cout << std::endl;
	soldier.ReadyToBattle();

	return 0;
}