enum Topic
{
	NO_HELP_TOPIC = -1,
	PRINT_TOPIC = 1,			// 0001
	PAPER_ORIENTATION_TOPIC = 2,// 0010
	APPLICATION_TOPIC = 4,		// 0100
	ALL_RELATED_TOPIC = 7		// 0111
};
//==============handler Base Class===========//
class HelpHandler
{
public:
	HelpHandler(HelpHandler* = 0, Topic = NO_HELP_TOPIC);
	virtual bool HasHelp();
	virtual void SetHandler(HelpHandler*, Topic);
	virtual void HandleHelp();

private:
	HelpHandler* _successor;
	Topic _topic;
};


HelpHandler::HelpHandler(HelpHandler *h, Topic t)
	: _successor(h), _topic(t)
{
}

bool HelpHandler::HasHelp()
{
	return (_topic != NO_HELP_TOPIC);
}

void HelpHandler::SetHandler(HelpHandler *h, Topic t)
{
	_successor = h;
	_topic = t;
}

void HelpHandler::HandleHelp()
{
	if (_successor)
		_successor->HandleHelp();
}

//==============Interface===========//
class Widget : public HelpHandler
{
protected:
	Widget(Widget* parent, Topic t = NO_HELP_TOPIC);

private:
	Widget* _parent;
};

Widget::Widget(Widget *w, Topic t)
	: HelpHandler(w,t)
{
	_parent = w;
}


//==============handler concrete===========//

class Button : public Widget
	// Widget�� ����ϴ� �ٸ� ��ü���� ���� ���ʸ� �ѱ�
{
public:
	Button(Widget* w, Topic t = NO_HELP_TOPIC);

	virtual void HandleHelp();
private:

};

Button::Button(Widget * w, Topic t)
	: Widget(w, t)
{
}

void Button::HandleHelp()
{
	if (HasHelp())
	{
		// Here to do
	}
	else
	{
		HelpHandler::HandleHelp();
	}
}

class Dialog : public  Widget
	// Widget�� �ƴ϶� HelpHandler�� ����ϴ� ��ü���� ���� ���ʸ� �ѱ�
{
public:
	Dialog(HelpHandler* h, Topic t = NO_HELP_TOPIC);

	virtual void HandleHelp();

};

Dialog::Dialog(HelpHandler * h, Topic t)
	: Widget(0)
{
	// Widget�� �ƴ϶� �ٷ� HelpHandler���� �����Ϳ� Topic �˷���
	SetHandler(h, t);
}

void Dialog::HandleHelp()
{
	if (HasHelp()) {
		// here to do
	}
	else	{
		HelpHandler::HandleHelp();
	}
}

class Application :public HelpHandler
	// HelpHandler�� ���� ��� �޴� �ν��Ͻ�
{
public:
	Application(Topic t) : HelpHandler(0, t) {}

	virtual void HandleHelp();
};

void Application::HandleHelp()
{
	// here to do
}

//==============main example===========//
int main()
{
	Application* application = new Application(APPLICATION_TOPIC);
	Dialog* dialog = new Dialog(application, PRINT_TOPIC);
	Button* button_paper = new Button(dialog, PAPER_ORIENTATION_TOPIC);
	Button* button_all = new Button(dialog, ALL_RELATED_TOPIC);

	button_paper->HandleHelp();
	return 0;
}