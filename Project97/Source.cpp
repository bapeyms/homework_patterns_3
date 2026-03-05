#include <iostream>
#include <string>
using namespace std;

class Car
{
	string shell; // корпус
	int engine;
	int wheel;
	string gearbox; // коробка передач
public:
	string getShell() { return shell; }
	int getEngine() { return engine; }
	int getWheel() { return wheel; }
	string getGearbox() { return gearbox; }

	void setShell(string shell) { this->shell = shell; }
	void setEngine(int engine) { this->engine = engine; }
	void setWheel(int wheel) { this->wheel = wheel; }
	void setGearbox(string gearbox) { this->gearbox = gearbox; }

	void showInfo()
	{
		cout << "--- CAR INFO ---" << endl;
		cout << "Shell: " << shell << endl;
		cout << "Engine: " << engine << endl;
		cout << "Wheel: " << wheel << endl;
		cout << "Gearbox: " << gearbox << endl << endl;
	}
};

class CarBuilder
{
protected:
	Car car;
public:
	Car getCar() { return car; }
	virtual void buildShell() = 0;
	virtual void buildEngine() = 0;
	virtual void buildWheel() = 0;
	virtual void buildGearbox() = 0;
};

class DaewooLanosBuilder : public CarBuilder
{
public:
	void buildShell() 
	{ 
		car.setShell("Sedan"); 
	}
	void buildEngine() 
	{ 
		car.setEngine(98); 
	}
	void buildWheel() 
	{ 
		car.setWheel(13); 
	}
	void buildGearbox() 
	{ 
		car.setGearbox("5 Manual"); 
	}
};

class FordProbeBuilder : public CarBuilder
{
public:
	void buildShell()
	{
		car.setShell("Coupe");
	}
	void buildEngine()
	{
		car.setEngine(160);
	}
	void buildWheel()
	{
		car.setWheel(14);
	}
	void buildGearbox()
	{
		car.setGearbox("4 Auto");
	}
};

class UAZpatriotBuilder : public CarBuilder
{
public:
	void buildShell()
	{
		car.setShell("Universal");
	}
	void buildEngine()
	{
		car.setEngine(120);
	}
	void buildWheel()
	{
		car.setWheel(16);
	}
	void buildGearbox()
	{
		car.setGearbox("4 Manual");
	}
};

class HyundaiGetzBuilder : public CarBuilder
{
public:
	void buildShell()
	{
		car.setShell("Hatchback");
	}
	void buildEngine()
	{
		car.setEngine(66);
	}
	void buildWheel()
	{
		car.setWheel(13);
	}
	void buildGearbox()
	{
		car.setGearbox("4 Auto");
	}
};

class Shop
{
	CarBuilder* builder;
public:
	void setBuilder(CarBuilder* _builder) 
	{ 
		builder = _builder; 
	}
	Car getCar()
	{
		return builder->getCar();
	}
	void constructCar()
	{
		builder->buildShell();
		builder->buildEngine();
		builder->buildWheel();
		builder->buildGearbox();
	}
};

void Client(CarBuilder* builder)
{
	Shop shop;
	shop.setBuilder(builder);
	shop.constructCar();
	Car car = shop.getCar();
	car.showInfo();
}

int main()
{
	CarBuilder* builder = new DaewooLanosBuilder();
	Client(builder);
	delete builder;

	builder = new FordProbeBuilder();
	Client(builder);
	delete builder;

	builder = new UAZpatriotBuilder();
	Client(builder);
	delete builder;

	builder = new HyundaiGetzBuilder();
	Client(builder);
	delete builder;
	return 0;
}