#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	virtual string distribution() const = 0;
};

class Context
{
private:
	Car* strategy_;
	
public:
	Context(Car* strategy = nullptr) : strategy_(strategy)
	{
	}
	~Context()
	{
		delete this->strategy_;
	}

	void set_strategy(Car* strategy)
	{
		delete this->strategy_;
		this->strategy_ = strategy;
	}
	
	void DoSomeBusinessLogic() const
	{
		
		string result = this->strategy_->DoAlgorithm();
		cout << result << endl;
	}
};


class Green : public Car
{
public:
	string distribution() const override
	{
		return "Parents has green machine and it need to clean";
	}
};

class Red : public Car
{
public:
	string distribution() const override
	{
		return "Son has red machine and it need to clean";
	}
};

class Blue : public Car
{
public:
	string distribution() const override
	{
		return "Daughter has blue machine and it don't need to clean";
	}
};

int main()
{
	int year;
	string member;
	cout << "Enter the family member (Son, Daughter, Parents)" << endl;
	cin >> member;
	cout << "Enter the year (2000, 2005, 2007)"<< endl;
	cin>> year;

	Context* context = new Context();

	if (year == 2000 && member = "Parents") context->set_strategy(new Green);
	else if (year == 2005 && member = "Son") context->set_strategy(new Red);
	else if (year == 2007 && member = "Daughter") context->set_strategy(new Blue);
	else cout << "Error: invalid data" << endl;

	context->DoSomeBusinessLogic();
	delete context;

	system("PAUSE");
	return 0;
}