// PMII PROJECT1.cpp : Defines the entry point for the console application.
//

#include "Header.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	vector <Service> serviceArray;		//Vector for services
	vector <Customer> customerArray;	//Vector for customers/min
	vector <Teller> tellerArray;		//Vector for tellers

	//Stock services
	Service deposit("deposit", 1);
	Service withdraw("withdraw", 1);
	Service account("account", 5);
	Service transfer("transfer", 2);
	serviceArray.push_back(deposit);
	serviceArray.push_back(withdraw);
	serviceArray.push_back(account);
	serviceArray.push_back(transfer);

	vector <Customer> queue;			//Vector used for the queue of customers

	//Welcome message
	cout << "Welcome to the bank teller simulation!" << endl;
	cout << "Preloaded are services of: 'deposit' 'withdraw' 'account' 'transfer'" << endl;

	string input = " ";		//used for input
	string st1 = "";		//used for new service name
	Service *nw;			//used for new service
	int time;				//used for new service time
	Teller *t1;				//used to initialize tellers
	Customer *cc;			//used to initialize customers

	//This is the main loop that will continue the program
	//until the user types "exit" when asked to choose and option
	while (input != "exit") {
		cout << endl << endl;
		cout << "Please select an action from the list of options (input the number): " << endl;
		cout << "1. Introduce a new service" << endl
			<< "2. Configure a simulation" << endl
			<< "3. exit" << endl;
		cin >> input;

		//Create a new service
		if (input == "1") {
			cout << "Please tell me the name of your new service: ";
			st1 = "";
			cin >> st1;
			cout << endl;
			cout << "Please tell me (in minutes) how long this service is supposed to take (input must be an integer): ";
			time = 0;
			cin >> time;
			cout << endl;
			nw = new Service;
			nw->setTime(time);
			nw->setType(st1);
			serviceArray.push_back(*nw);
			cout << "New service is introduced." << endl;
		}

		//Simulation time
		else if (input == "2") {
			int x = 0, time1 = 0, tellers = 0;
			cout << "Okay, before we begin we will run through all the parameters." << endl;
			cout << "The current services offered are:" << endl;

			//Set customers per min
			for (int i = 0; i < serviceArray.size(); i++) {
				cout << "Service: " << serviceArray[i].getType() << "      " << "Time needed (mins): "
					<< serviceArray[i].getTime() << endl;
				cout << "How many customers will require this service each minute? ";
				cin >> x;
				if (x > 0) {
					for (int j = 0; j < x; j++) {
						cc = new Customer;
						cc->setService(serviceArray[i].getType());
						customerArray.push_back(*cc);
					}
				}
			}//end customers/min loop

			random_shuffle(customerArray.begin(), customerArray.end());		//use shuffle to create a more dynamic situation

																			//Set tellers
			cout << "How long will we like to have this simulation run (minutes)? ";
			cin >> time1;
			cout << endl;
			cout << "How many tellers do we have available? ";
			cin >> tellers;
			for (int i = 0; i < tellers; i++) {
				t1 = new Teller;
				tellerArray.push_back(*t1);
			}
			cout << endl;
			int count = 0;
			string service = "";
			double service_Time = 0.0;
			double wait_time = 0.0;
			vector<double> wait_avg;

			//SIMULATION
			for (int i = 0; i < time1; i++) {

				//Make queue with customers given prior
				for (int x = 0; x < customerArray.size(); x++) {
					queue.push_back(customerArray[x]);
				}

				//Count marks which customer is being served, put each teller to one customer
				if (tellerArray.size() > queue.size()) {
					for (int j = 0; j < queue.size(); j++) {
						if (tellerArray[j].gettaken() == 0) {
							tellerArray[j].settaken(count);
							count++;
						}
					}
				}
				else {
					for (int j = 0; j < tellers; j++) {
						if (tellerArray[j].gettaken() == 0) {
							tellerArray[j].settaken(count);
							count++;
						}
					}
				}

				//Tellers help customers
				if (tellerArray.size() > queue.size()) {
					for (int y = 0; y < queue.size(); y++) {
						service = queue[y].getService();

						//Find the service time for the customer being helped
						for (int t = 0; t < serviceArray.size(); t++) {
							if (service == serviceArray[t].getType()) {
								service_Time = serviceArray[t].getTime();
								break;
							}
						}

						tellerArray[y].setwait(service_Time);	//set time to see when teller will complete

						if ((tellerArray[y].getwait() - 1.0) <= 0)
							tellerArray[y].settaken(0);
						//else the time teller takes to complete is subtracted by 1
						else {
							tellerArray[y].setwait((tellerArray[y].getwait() - 0.1));
						}
						wait_time = 0.0;
						//Calculate Average wait time

						for (int xy = count; xy < queue.size(); xy++) {
							service = queue[xy].getService();
							service_Time = 0;
							//Get service time of current customer
							for (int tt = 0; tt < serviceArray.size(); tt++) {
								if (service == serviceArray[tt].getType()) {
									service_Time = serviceArray[tt].getTime();
									break;
								}
							}
							wait_time = wait_time + service_Time;
						}//end wait time loop
						wait_time = (wait_time / tellerArray.size());
					}//end teller loop

					cout << "After " << (i + 1) << " minutes the current wait time is "
						<< wait_time << " minutes" << endl;
					wait_avg.push_back(wait_time);
				}//end Simulation loop
				else {
					for (int y = 0; y < tellerArray.size(); y++) {
						service = queue[y].getService();

						//Find the service time for the customer being helped
						for (int t = 0; t < serviceArray.size(); t++) {
							if (service == serviceArray[t].getType()) {
								service_Time = serviceArray[t].getTime();
								break;
							}
						}

						tellerArray[y].setwait(service_Time);	//set time to see when teller will complete

						if ((tellerArray[y].getwait() - 1.0) <= 0)
							tellerArray[y].settaken(0);
						//else the time teller takes to complete is subtracted by 1
						else {
							tellerArray[y].setwait((tellerArray[y].getwait() - 0.1));
						}
						wait_time = 0.0;
						//Calculate Average wait time

						for (int xy = count; xy < queue.size(); xy++) {
							service = queue[xy].getService();
							service_Time = 0;
							//Get service time of current customer
							for (int tt = 0; tt < serviceArray.size(); tt++) {
								if (service == serviceArray[tt].getType()) {
									service_Time = serviceArray[tt].getTime();
									break;
								}
							}
							wait_time = wait_time + service_Time;
						}//end wait time loop
						wait_time = (wait_time / tellerArray.size());
					}//end teller loop

					cout << "After " << (i + 1) << " minutes the current wait time is "
						<< wait_time << " minutes" << endl;
					wait_avg.push_back(wait_time);
				}//end Simulation loop
			}//END SIMULATION
			wait_time = 0.0;
			for (int i = 0; i < wait_avg.size(); i++) {
				wait_time = wait_time + wait_avg[i];
			}
			wait_time = wait_time / time1;
			cout << "Average wait time: " << wait_time << endl;
			wait_avg.clear();
			queue.clear();		// clear all vectors so that the next simulation starts from stratch
			customerArray.clear();
			tellerArray.clear();
		}//input==2 if statment

		 //exit program
		else if (input == "3") {
			break;
		}

		//if input is invalid
		else {
			cout << "I'm sorry, that input is invalid." << endl << endl;
		}
	}// end of top while loop
	return 0;
}//end program

