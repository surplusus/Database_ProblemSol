#pragma once
#include <memory>
#include <list>

class Process;
typedef std::shared_ptr<Process> StrongProcessPtr;
typedef std::weak_ptr<Process> WeakProcessPtr;

//===========Process Interface====================//
class Process
{
	friend class ProcessManager;

public:
	enum State
	{
		UNINITIALIZED = 0,
		REMOVED,
		RUNNING,
		PAUESED,
		SUCCEEDED,
		FAILED,
		ABORTED,
	};
private:
	State m_state;
	StrongProcessPtr m_pChild;
public:
	Process();
	virtual ~Process();

protected:
	virtual void VOnInit() { m_state = RUNNING; }
	virtual void VOnSuccess() {}
	virtual void VOnFail() {}
	virtual void VOnAbort() {}
	virtual void VOnUpdate(unsigned long deltaMs) = 0;
	
public:
	inline void Succeed();
	inline void Fail();

	inline void Pause();
	inline void UnPause();

	State GetState() const { return m_state; }
	bool IsAlive() const { return (m_state == RUNNING || m_state == ABORTED); }
	bool IsDead() const {
		return (m_state == SUCCEEDED || m_state == FAILED || m_state == ABORTED);
	}
	bool IsRemoved() const { return (m_state == REMOVED); }
	bool IsPaused() const { return (m_state == PAUESED); }

	inline void AttachChild(StrongProcessPtr pChild);
	StrongProcessPtr RemoveChild();
	StrongProcessPtr PeekChild() { return m_pChild; }

private:
	void SetState(State newState) { m_state = newState; }
};

//===========ProcessManager Interface====================//
class ProcessManager
{
	typedef std::list<StrongProcessPtr> ProcessList;
private:
	ProcessList m_processList;
public:
	virtual ~ProcessManager();

	unsigned int UpdateProcesses(unsigned long deltaMs);
	WeakProcessPtr AttachProcess(StrongProcessPtr pProcess);
	void AbortAllProcesses(bool immediate);

	unsigned int GetProcessCount() const { return m_processList.size(); }

private:
	void ClearAllProcesses();
};


//===========Process Concrete====================//
class DelayProcess : public Process
{
	unsigned long m_timeToDelay;
	unsigned long m_timeDelayedSoFar;

public:
	explicit DelayProcess(unsigned long timeToDelay)  {
		m_timeToDelay = timeToDelay;
		m_timeDelayedSoFar = 0;
	}

protected:
	virtual void VOnUpdate(unsigned long deltaMs)	{
		m_timeDelayedSoFar += deltaMs;
		if (m_timeDelayedSoFar >= m_timeToDelay)
			Succeed();
	}
};

class KaboomProcess;
//===========main Ȱ�� ����====================//
int main()
{
	ProcessManager processManager;

	StrongProcessPtr pDelay(new DelayProcess(3000));
	processManager.AttachProcess(pDelay);

	// KaboomProcess�� DelayProcess�� AttachChild�Ǿ��ֱ� ������ 
	// DelayProcess�� Success()�� ȣ���Ҷ����� ��ٸ���.
	// ���� ��ٷȴµ��� DalyProcess�� Success() ���� ���ϸ� 
	// KaboomProcess�� ������Ʈ ���ϰ� ��������.
	StrongProcessPtr pKaboom(new KaboomProcess());
	pDelay->AttachChild(pKaboom);

	return 0;
}