#include "Header.h"
using namespace std;

Service::Service() {
	time = 1;
	type = "deposit";
}


Service::Service(string st1, int x) {
	time = x;
	type = st1;
}

void Service::setType(string st1) {
	type = st1;
}
string Service::getType() {
	return type;
}
void Service::setTime(int x) {
	time = x;
}
int Service::getTime() {
	return time;
}


Customer::Customer() {
	service = "deposit";
}

Customer::Customer(string st1) {
	service = st1;
}
void Customer::setService(string st1) {
	service = st1;
}
string Customer::getService() {
	return service;
}


void Teller::settaken(int b1) {
	taken = b1;
}

int Teller::gettaken() {
	return taken;
}

void Teller::setwait(double x) {
	wait = x;
}

double Teller::getwait() {
	return wait;
}