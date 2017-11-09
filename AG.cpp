#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>
#include "AlgoGen.h"

//using namespace std;


class MyPrint {
public:
	int b = 5;
	double MyP(vector<double> a) {
		return 0;
	}
};



class MyFit {
public:
	static double Fit(vector<double> cromo) {
		//return 1.0;
		double sum = 0;
		for (unsigned int i = 0; i < cromo.size(); ++i) {
			sum += cromo[i];
		}
		return sum < 0 ? 0.0 : sum;
	}
};

int main() {
	
	
	
	//std::cout << "ASDASDASDASDASDAD";
	//MyFit A;

	AlgoGen AG(10, 10, 3, .1);
	AG.Set_input("BLA", AlgoGen::Set_array(0, 10, 1));
	AG.Set_input("BLE", AlgoGen::Set_array(0, 30, 1));
	AG.Set_input("ASDA", AlgoGen::Set_array(-12, 2, 1));

	AG.Initializate();
	
	AG.Fitness(&MyFit::Fit);
	//AG.Fitness <MyFit>(&A, &MyFit::Fit);
	AG.Print();

	getchar();
	return 0;

}