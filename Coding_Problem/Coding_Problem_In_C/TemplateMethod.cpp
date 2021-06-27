#include <iostream>

template <class Derived>
struct Character
{
	// Template Mathod
	void ReadyToBattle();
	// ��� ���� Ŭ�������� ������ �� ������ final Ű���带 �ٿ����ϴ�.
	virtual void StartBodyTraining() final;
	// �����غ�
	virtual void PrepareWeapon() = 0;
	// �����غ�
	virtual void PrepareArmor() = 0;
	// ���� Hook �Լ��� override �� �Ͼ�� �Ļ�Ŭ���� �Լ� ����
	void DoPrepareOther();
	// �� �޼ҵ�� "��ŷ(Hooking)" �뵵�� ����մϴ�.
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
	std::cout << "ü���� �ܷ��մϴ�." << std::endl;
}


void Soldier::PrepareWeapon()
{
	std::cout << "���� �غ��մϴ�." << std::endl;
}

void Soldier::PrepareArmor()
{
	std::cout << "�������� ȯ���մϴ�." << std::endl;
}

void Soldier::PrepareOther()
{
	std::cout << "���̿��� ���� ���ϴ�." << std::endl;
}

void Archer::PrepareWeapon()
{
	std::cout << "Ȱ�� �غ��մϴ�." << std::endl;
}

void Archer::PrepareArmor()
{
	std::cout << "������ ������ �Խ��ϴ�." << std::endl;
}

int main() {
	Archer archer;
	Soldier soldier;

	archer.ReadyToBattle();
	std::cout << std::endl;
	soldier.ReadyToBattle();

	return 0;
}