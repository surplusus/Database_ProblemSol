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

generate(vi.begin(), vi.end(), fibo());



//�Լ� ��ü�� �۾� ����� ������ ������ �� ������ �� ȣ�⸶�� ���������� ������ �� �����Ƿ� ��Ƽ ������ ȯ�濡���� �� �����Ѵ�.