#pragma once

#include <string>

class Service {
public:
	Service();
	~Service() {};
	Service(std::string, int);
	void setType(std::string);
	std::string getType();
	void setTime(int);
	int getTime();

private:
	std::string type;
	int time;
};

class Customer {
public:
	Customer();
	~Customer() {};
	Customer(std::string);
	void setService(std::string);
	std::string getService();
private:
	std::string service;
};

class Teller {
public:
	void settaken(int);
	int gettaken();
	void setwait(double);
	double getwait();
private:
	int taken;
	double wait;
};