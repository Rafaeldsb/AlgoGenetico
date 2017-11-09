#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "AlgoGen.h"

using namespace std;


class MyFit : public AlgoGen {
public:
	static double Fit(vector<double> cromo) {
		//return 1.0;
		cout << "Tamanho: " << cromo.size();
		double sum = 0;
		for (unsigned int i = 0; i < cromo.size(); ++i) {
			sum += cromo[i];
		}
		return sum < 0 ? 0.0 : sum;
	}

};

int main() {
	

	MyFit AG;
	AG.SetAlgoGen(10, 10, 3, .1);

	AG.Set_input("BLA", AlgoGen::Set_array(0, 10, 1));
	AG.Set_input("BLE", AlgoGen::Set_array(0, 30, 1));
	AG.Set_input("ASDA", AlgoGen::Set_array(-12, 2, 1));

	AG.Initializate();
	cout << "Iniciou\n";
	AG.Fitness(&AG.Fit);
	cout << "Avaliado\n";
	AG.Print();
	cout << "Termiado\n";

	return 0;
}