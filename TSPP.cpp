#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <conio.h>
using namespace std;

<<<<<<< HEAD
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
=======
class Insurance{	
	public:
		Insurance(){
		}
		string FIO;
		int Num_Pasport;
		int Age;
		string status;
		Insurance(string _FIO, int _Num_Pasport, int _Age, string _status);
};

Insurance::Insurance(string _FIO, int _Num_Pasport, int _Age, string _status){
	FIO=_FIO;
	Num_Pasport=_Num_Pasport;
	Age=_Age;
	status=_status;
}
	

class Insurance_Health : public Insurance{
	public:
		int Old;
		Insurance_Health(){
		}
		Insurance_Health(int _Old, string FIO, int Num_Pasport, int Age, string status):Insurance(FIO, Num_Pasport, Age, status){
			Old = _Old;
		};
};

class Insurance_Auto : public Insurance{
	public:
		int Num_Auto;
		Insurance_Auto(){
		}
		Insurance_Auto(int _Num_Auto, string FIO, int Num_Pasport, int Age, string status):Insurance(FIO, Num_Pasport, Age, status){
			Num_Auto=_Num_Auto;
		}
};

class Insurance_Properity : public Insurance{
	public:
		int ID;
		Insurance_Properity(){
		}
		Insurance_Properity(int _ID, string FIO, int Num_Pasport, int Age, string status):Insurance(FIO, Num_Pasport, Age, status){
			ID=_ID;
		};
};

class Lawyer{
	public:
		Lawyer(){
		}
		string FIO_Lawyer;
		Lawyer(int _FIO_Lawyer);
		void Check(Insurance * Ins);
		void Refusal(Insurance * Ins);
		void Approved(Insurance * Ins);
};

Lawyer::Lawyer(int _Fio_Lawyer){
	FIO_Lawyer = _Fio_Lawyer;
}

void Lawyer::Check(Insurance * Ins){
	system("cls");
	for (int i=0; i < Ins->FIO.size();i++){
		if (isdigit(Ins->FIO[i]))
			cout<<"В имени была допущена ошибка"<<endl;
			system("pause");
			Refusal(Ins);
			return;		
	}
	
	if (!((Ins->Num_Pasport > 999999) && (Ins->Num_Pasport<100000))){
			cout<<"В номере паспорта была допущена ошибка"<<endl;
			system("pause");
			Refusal(Ins);
			return;	
	}
	
	if (!((Ins->Age < 200) && (Ins->Age>0))){
			cout<<"В возрасте была допущена ошибка"<<endl;
			system("pause");
			Refusal(Ins);
			return;	
	}
	
	Approved(Ins);
	return;
}

void Lawyer::Approved(Insurance * Ins){
	cout<<"+"<<endl;
	Ins->status = "Страховка";
	system("pause");
}

void Lawyer::Refusal(Insurance * Ins){
	cout<<"-"<<endl;
	Ins->status = "Отказано";
	system("pause");
}

>>>>>>> Insurance_and_Lawyer

int main(int argc, char** argv) {
	return 0;
}
