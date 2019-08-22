#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Wheel
{
	int size;
};
struct Engine
{
	int horsepower;
};
struct Body
{
	std::string shape;
};
class Builder;
class JeepBuilder;

class Car
{
public:
	vector<Wheel*> wheels;
	Engine*  engine;
	Body* body;

	void specifications()
	{
		cout << "body:" << body->shape << endl;
		cout << "engine horsepower:" << engine->horsepower << endl;
		cout << "tire size:" << wheels[0]->size << "'" << endl;
	}
};

class Builder
{
public:
	virtual Wheel* getWheel() = 0;
	virtual Engine* getEngine() = 0;
	virtual Body* getBody() = 0;
};
class Director
{
	Builder* builder;

public:
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	}

	Car* getCar()
	{
		Car* car = new Car();
		car->body = builder->getBody();
		car->engine = builder->getEngine();
		car->wheels.resize(4, builder->getWheel());
		return car;
	}
};

class JeepBuilder : public Builder
{
public:
	Wheel* getWheel()
	{
		Wheel* wheel = new Wheel();
		wheel->size = 22;
		return wheel;
	}

	Engine* getEngine()
	{
		Engine* engine = new Engine();
		engine->horsepower = 400;
		return engine;
	}

	Body* getBody()
	{
		Body* body = new Body();
		body->shape = "SUV";
		return body;
	}
};

int main()
{
	Car* car; 
	Director director;
	
	/* Build a Jeep */
	JeepBuilder jeepBuilder;
	std::cout << "Jeep" << std::endl;
	director.setBuilder(&jeepBuilder);
	car = director.getCar();
	car->specifications();

	return 0;
}