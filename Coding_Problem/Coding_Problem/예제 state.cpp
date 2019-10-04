// context
class TCPstream;
class TCPState;

class TCPConnection
{
public:
	TCPConnection();

	void ActiveOpen();
	void PassiveOpen();
	void ProcessOctet(TCPstream*);
private:
	// State�� �������̽��� friend�̱� ������ 
	// State���� TCPConnection�� �Լ��� ����� ������ �ִ�
	friend class TCPState;
	void ChangeState(TCPState*);
private:
	TCPState* _state;
};

void TCPConnection::ActiveOpen()
{
	_state->ActiveOpen(this);
}

void TCPConnection::PassiveOpen()
{
	_state->PassiveOpen(this);
}

void TCPConnection::ChangeState(TCPState *s)
{
	_state = s;
}

// ���� ���� �θ� Ŭ����
class TCPState
{
	// �ڽ� Ŭ������ ����� �Լ��� �������̽����� ���̱�����
	// Ŭ������ public���� ������ ������ ������ �ڽĵ��� �Ѵ�
public:
	virtual void ActiveOpen(TCPConnection*) {}
	virtual void PassiveOpen(TCPConnection*) {}
	virtual void Send(TCPConnection*) {}
	virtual void Transmit(TCPConnection*, TCPstream*) {}
protected:
	void ChangeState(TCPConnection*, TCPState*);
	
};

void TCPState::ChangeState(TCPConnection *t, TCPState *s)
{
	// context�� private friend�� State�� ��� ������ �Լ��� ������ �� �ִ�
	TCPConnection::ChangeState(s);
}

// concretes
class TCPestablished : public TCPState
{
	// �Ƹ��� �� Ŭ������ ��Ŭ���ϵ�
	// static���� �ڽ��� �ν��Ͻ��� ������ �� �ְ� ��������ؼ�
public:
	static TCPState* Instance();

	virtual void Send(TCPConnection*);
	virtual void Transmit(TCPConnection*, TCPstream*);
		//...
};

class TCPclosed : public TCPState
{
public:
	// �Ƹ��� �� Ŭ������ ��Ŭ���ϵ�
// static���� �ڽ��� �ν��Ͻ��� ������ �� �ְ� ��������ؼ�
	static TCPState* Instance();

	virtual void ActiveOpen(TCPConnection*);
	virtual void PassiveOpen(TCPConnection*);
	// ....
};

void TCPclosed::ActiveOpen(TCPConnection *t)
{
	TCPstream* stream;
	t->ProcessOctet(stream);
}

void TCPclosed::PassiveOpen(TCPConnection *t)
{
	ChangeState(t, TCPestablished::Instance());
}
