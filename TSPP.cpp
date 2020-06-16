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


int main(int argc, char** argv) {
	return 0;
}
