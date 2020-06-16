#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <conio.h>
using namespace std;

class Client{	
	public:
		Client(){
		}
		string FIO;
		Insurance _insurance;
		
		Client(string _FIO, Insurance * Ins);
};

Client::Client(string _FIO, Insurance * Ins): _insurance(*Ins){
	FIO=_FIO;
}

class Admin{
	private:
		list<Client*> clients;
		list<Lawyer*> lawyers;
	public:
		void addClient(Client * cl);
		void delClient(Client * cl);
		void modClient(Client * cl);
};

void Admin::addClient(Client * cl){
	clients.push_back(cl);
}

void Admin::delClient(Client * cl){
	for (list<Client*>::iterator i=clients.begin(); i!=clients.end(); i++){
		if (*i==cl){
			clients.erase(i);
		}
	}
}

void Admin::modClient(Client * cl){
	string NewFio; 
	int NewAge;
	int NewNum_Pasport;
	for (list<Client*>::iterator i=clients.begin(); i!=clients.end(); i++){
		if (*i==cl){
			cin >> NewFio;
			(*i)->_insurance.FIO = NewFio;
			cin >> NewAge;
			(*i)->_insurance.Age = NewAge;
			cin >> NewFio;
			(*i)->_insurance.Num_Pasport = NewNum_Pasport;
			return;
		}
	}
}

int main(int argc, char** argv) {
	return 0;
}
