#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <conio.h>
using namespace std;

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

int main(int argc, char** argv) {
	return 0;
}
