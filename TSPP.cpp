#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <conio.h>
using namespace std;

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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char c ,d;
	setlocale(LC_ALL, "Russian");
	Insurance_Auto ins_a;
	Insurance_Health ins_h;
	Insurance_Properity ins_p;
	Lawyer* law = new Lawyer;
	Client* cl = new Client;
	Admin* ad = new Admin;
	int age, num_pasport, num_auto, id;
	string FIO, status;
	int type = 0;
	while(1){
		cout<<"Клиент"<<endl;
		cout<<"Юрист"<<endl;
		cout<<"Администратор"<<endl;
		c = _getch(); 
		
		switch(c){
			case '1':{
				system("cls");
				cout<<"Выберите вид заявки:"<<endl;
				cout<<"Страховка автомобиля"<<endl;
				cout<<"Страховка имущества"<<endl;
				cout<<"Страховка здоровья"<<endl;
				d = _getch();
				
				switch(d){
					case '1':{
						system("cls");
						cout<<"Введите имя"<<endl;
						cin>>FIO;
						cout<<"Введите возраст"<<endl;
						cin>>age;
						cout<<"Введите номер паспорта"<<endl;
						cin>>num_pasport;
						cout<<"Введите номер авто"<<endl;
						cin>>num_auto;
						
						ins_a.Age = age;
						ins_a.FIO = FIO;
						ins_a.Num_Pasport = num_pasport;
						ins_a.Num_Auto;
						ins_a.status = "Заявка";
						type = 1;
						break;
					}
					case '2':{
						system("cls");
						cout<<"Введите имя"<<endl;
						cin>>FIO;
						cout<<"Введите возраст"<<endl;
						cin>>age;
						cout<<"Введите номер паспорта"<<endl;
						cin>>num_pasport;
				
						ins_h.Age = age;
						ins_h.FIO = FIO;
						ins_h.Old = age;
						ins_h.Num_Pasport = num_pasport;
						ins_h.status = "Заявка";
						type = 2;
						break;
					}
					case '3':{
						system("cls");
						cout<<"Введите имя"<<endl;
						cin>>FIO;
						cout<<"Введите возраст"<<endl;
						cin>>age;
						cout<<"Введите номер паспорта"<<endl;
						cin>>id;
						cout<<"Введите ID"<<endl;
						cin>>num_auto;
						cin>>age>>num_pasport>>FIO;
						ins_p.Age = age;
						ins_p.FIO = FIO;
						ins_p.ID = id;
						ins_p.Num_Pasport = num_pasport;
						ins_p.status = "Заявка";
						type = 3;
						break;
					}
				}
				break;
			}
			case '2':{
				system("cls");
				if (type == 1){
					law->Check(&ins_a);
					cout<<ins_a.status<<endl;
					if (ins_a.status == "Отказано"){
						break;
						}
					else{
						cl->FIO = ins_a.FIO;
						cl->_insurance = ins_a;
					}
				}
				
				if (type == 2){
					law->Check(&ins_h);
					if (ins_h.status == "Отказано"){

						break;
						}
					else{
						cl->FIO = ins_h.FIO;
						cl->_insurance = ins_h;
					}	
				}
				
				if (type == 3){
					law->Check(&ins_p);
					if (ins_p.status == "Отказано"){
						
						break;
						}
					else{
						cl->FIO = ins_p.FIO;
						cl->_insurance = ins_p;
				}
				}
				
				if (type == 0){	
					cout<<"Нет заявки"<<endl;
				}
				
				break;
			}
			case '3':{
				system("cls");
				if ((ins_p.status == "Отказано") || (ins_a.status == "Отказано") || (ins_h.status == "Отказано")){
					cout<<"В заявке было отказано"<<endl;
					system("pause");
					break;
				}
				cout<<" 1 Добавить:"<<endl;
				cout<<" 2 Удалить"<<endl;
				cout<<" 3 Модифицировать"<<endl;
				c = _getch();
				switch(c){
					case '1':{
						system("cls");
						ad->addClient(cl);
						cout<<"Клиент добавлен в базу"<<endl;
						break;
					}
					case '2':{
						system("cls");
						ad->delClient(cl);
						cout<<"Клиент удален из базы"<<endl;
						break;
					}
					case '3':{
						system("cls");
						ad->modClient(cl);
						cout<<"Данные о клиенте измененны"<<endl;
						break;
					}
				}
				break;
			}
			
		}
	}
	
	return 0;
}




