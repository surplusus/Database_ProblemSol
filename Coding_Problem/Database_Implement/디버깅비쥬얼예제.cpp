#pragma once
#include <assert.h>

template<typename T>
class HARR
{
private:
	unsigned int m_Size;
	T* Data;

public:
	T& operator[](unsigned int _Index)
	{
		if (m_Size <= _Index)
		{
			assert(false);
		}

		return Data[_Index];
	}

	HARR& operator=(const HARR& _Other)
	{
		if (m_Size != _Other.m_Size)
		{
			Clear();
			m_Size = _Other.m_Size;
			Data = new T[_Other.m_Size];
		}

		for (unsigned int i = 0; i < _Other.m_Size; i++)
		{
			Data[i] = _Other.Data[i];
		}

		return *this;
	}

public:
	int Size() const
	{
		return m_Size;
	}

	void Resize(int _Value)
	{
		Clear();
		m_Size = _Value;
		Data = new T[_Value]();
		return;
	}

	void Clear()
	{
		if (nullptr != Data)
		{
			delete[] Data;
			Data = nullptr;
			m_Size = 0;
		}
	}

public:
	HARR() : m_Size(0), Data(nullptr)
	{
	}

	HARR(const HARR& _Other)
	{
		Size(_Other.m_Size);
		for (unsigned int i = 0; i < _Other.m_Size; i++)
		{
			Data[i] = _Other.Data[i];
		}
	}

	HARR(int _Size) : m_Size(0), Data(nullptr)
	{
		Resize(_Size);
	}

	~HARR()
	{
		Clear();
	}
};

class HPOINT
{
public:
	int X;
	int Y;

public:
	int HX() {
		return (int)(X * 0.5F);
	}
	int HY() {
		return (int)(Y * 0.5F);
	}

public:
	HPOINT() : X(0), Y(0) {}
	HPOINT(int _X, int _Y) : X(_X), Y(_Y) {}
};

class HGAMERECT
{
public:
	HPOINT Postion;
	HPOINT Scale;

private:
	HPOINT  LeftTop()
	{
		return HPOINT{ Postion.X - Scale.HX() , Postion.Y - Scale.HY() };
	}

	HPOINT  RightTop()
	{
		return HPOINT{ Postion.X + Scale.HX() , Postion.Y - Scale.HY() };
	}

	HPOINT  LeftBot()
	{
		return HPOINT{ Postion.X - Scale.HX() , Postion.Y + Scale.HY() };
	}

	HPOINT  RightBot()
	{
		return HPOINT{ Postion.X + Scale.HX() , Postion.Y + Scale.HY() };
	}
};

int main()
{
	HARR<int> Arr;
	HPOINT point;
	point.X = 4;
	point.Y = 12;
	HGAMERECT re = { {10,10},{4,4} };
	Arr.Resize(5);
	for (size_t i = 0; i < 5; i++)
	{
		Arr[i] = i;
	}

	
	return 0;
};