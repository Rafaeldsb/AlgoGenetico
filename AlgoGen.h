//#pragma once


using namespace std;



class AlgoGen
{
private:
	
	int						POP;							// Tamanho da população
	int						GENERATIONS;					// Tamanho máximo de gerações
	int						GENERATIONS_WITHOUT_BETTER;		// Generações máximas sem melhorias

	double					per_elitism;

	int						nGene = 0;

	vector<string>			header;							// Header do alfabeto
	vector<vector<double>>	Alph;							// Alfabeto
	

	vector<vector<double>>	Population;						// População atual
	vector<double>			Score;							// Score da população atual

	vector<short>			Pais_pos;						// Posições dos pais;

public:
	
	void					Set_input(string header, vector<double> alpha);

	static vector<double>	Set_array(double inicial, double final, double step);
	
	void					Initializate(void);
	/*
	template<class T>
	void					Fitness(T *Obj, double (T::*Fit)(vector<double>)) {
		
		this->Score.clear();
		for (int i = 0; i < this->POP; ++i) {
			this->Score.push_back((Obj->*Fit)(this->Population[i]));
		}
	
	}
*/
	void Fitness(double (*Fit)(vector<double>)){
		this->Score.clear();
		//cout << "\nSize: " << this->Population.size() << "\n";
		
		for(int i = 0; i < this->POP; ++i){
			cout << "\nSize: " << this->Population[i].size() << "\n";
			this->Score.push_back((*Fit)(this->Population[i]));
		}
		
	}

	
	double					Sum(void);

	void					SelectParents(void);

	void					Print(void);
	

	void SetAlgoGen(int pop, int gener, int gener_wb, double elit);
	AlgoGen(){}
	~AlgoGen();
};




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//														Setar		Alfabeto													  //


void AlgoGen::Set_input(string header, vector<double> alpha) {
	//std::cout << header << endl;
	this->header.push_back(header);
	this->Alph.push_back(alpha);
	this->nGene++;
}



vector<double> AlgoGen::Set_array(double inicial, double final, double step) {
	vector<double> temp;
	final += step / 2;
	for (double init = inicial; init <= final; init += step) {
		temp.push_back(init);
	}

	return temp;
}


double AlgoGen::Sum(void) {
	double S = 0;
	cout << "POP: " << this->POP << "\t\t ScoreS: " << this->Score.size() << "\n";
	for (int i = 0; i < this->POP; ++i) {
		S += this->Score[i];
	}
	return S;
}

void AlgoGen::SelectParents(void){
	vector<short> temp;

	for(int i = 0; i < this->POP; ++i){
		temp.push_back(i);
	}

	this->Pais_pos.clear();

	for(int i = 0; i < this->POP * this->per_elitism; ++i){

		double S = 0;
		for(unsigned int i = 0; i < temp.size(); ++i){
			S += this->Score[temp[i]];
		}

		double rad = ((double)rand() / RAND_MAX) * S;
		
		int pos = -1;
		do {
			pos++;
			rad -= this->Score[temp[pos]];
		} while (rad > 0);

		this->Pais_pos.push_back(temp[pos]);
		temp.erase(temp.begin() + pos);
	}
	return;
}

void AlgoGen::Print(void) {
	cout << "A\n";
	double S = Sum();
	double AC = 0;
	cout << "ASDASD\n";
	cout << S << endl;

	double rad = ((double)rand() / RAND_MAX) * S;
	
	cout << rad << endl;


	int pos = -1;
	do {
		pos++;
		rad -= this->Score[pos];
	} while (rad > 0);

	for (int i = 0; i < this->POP; ++i) {

		cout << "#" << i << ":\t Cromossomo: ";
		for (int j = 0; j < this->nGene; ++j) {
			cout << this->Population[i][j] << " ";
		}
		AC += this->Score[i];
		cout << "\t\tScore: " << this->Score[i] << " " << AC;
		if (i == pos) cout << "\tPai";
		cout << endl;
		

	}
}

void AlgoGen::Initializate(void) {
	//srand(time(NULL));

	vector<double> temp;
	for (int i = 0; i < this->POP; ++i) {
		temp.clear();
		//cout << this->nGene;
		for (int j = 0; j < this->nGene; ++j) {
			//int a = rand() % this->Alph[j].size();
			
			temp.push_back(
				this->Alph[j][
					rand() % this->Alph[j].size()
				]
			);
		}
		this->Population.push_back(temp);
	}

}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//															Construtores														  //

void AlgoGen::SetAlgoGen(int pop, int gener, int gener_wb, double elit){
	this->POP = pop;
	this->GENERATIONS = gener;
	this->GENERATIONS_WITHOUT_BETTER = gener_wb;
	this->per_elitism = elit;	
}


AlgoGen::~AlgoGen()
{
}