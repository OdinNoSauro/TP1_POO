
#include "matriz.h"
#include <iostream>
#include <string>
using namespace std;


Matriz::Matriz(int linhas, int colunas){
	num_linhas = linhas;
	num_colunas = colunas;
	int i;
	M = new int* [num_linhas];
	for(i=0;i<num_linhas;i++){
		M[i] = new int[num_colunas];
	}
}

Matriz::Matriz(){
	Matriz(1,1);
}

Matriz::~Matriz(){
	for(int i = 0; i<num_linhas;i++)
		delete[] M[i];
	delete M;
}


void Matriz::unit(){
	int i,j;
	for(i=0;i<num_linhas;i++){
		for(j=0;j<num_colunas;j++){
			if(i==j)
				M[i][j]=1;
			else 
				M[i][j]=0;
		}
	}
}

void Matriz::zeros(){
	int i,j;
	for(i=0;i<num_linhas;i++){
		for(j=0;j<num_colunas;j++){
			M[i][j]=0;
		}
	}
}

void Matriz::ones(){
	int i,j;
	for(i=0;i<this->num_linhas;i++){
		for(j=0;j<this->num_colunas;j++){
			M[i][j]=1;
		}
	}
}
int Matriz::getRows(){
	return num_linhas;
}

int Matriz::getCols(){
	return num_colunas;
}

Matriz Matriz::operator+(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.M[i][j] = this->M[i][j] + m.M[i][j];
		}
	}
	return new_mat;
}

Matriz Matriz::operator-(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.M[i][j] = this->M[i][j] - m.M[i][j];
		}
	}
	return new_mat;
}

Matriz Matriz::operator+=(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->M[i][j] += m.M[i][j];
		}
	}
	return *this;
}

Matriz Matriz::operator-=(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->M[i][j] -= m.M[i][j];
		}
	}
	return *this;
}    

Matriz Matriz::operator~(){
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.M[j][i] = this->M[i][j];
			}
	}
	return new_mat;
}

Matriz Matriz::operator=(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->M[i][j] = m.M[i][j];
		}
	}
	return *this;
}


Matriz Matriz::operator*=(const Matriz& m){
	if (this->num_colunas != m.num_linhas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->M[j][i] = m.M[i][j];
		}
	}
	return *this;
}  

Matriz Matriz::operator*=(const int& constante){
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->M[j][i] *= constante;
		}
	}
	return *this;
} 

Matriz Matriz::operator*(const Matriz& m){
	if (this->num_colunas != m.num_linhas){
		cout << "Tamanhos das matrizes incompatíveis"<<endl;
		return (*this);
	}
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.M[i][j] = this->M[i][j] - m.M[i][j];
		}
	}
	return new_mat;
}

ostream& operator<<(ostream& out, const Matriz& m){
	int i,j;
	for (i = 0; i<m.num_linhas; i++){
		for(j = 0; j<m.num_linhas; j++){
			out<<m.M[i][j]<<"\t";
		}
		out<<endl;
	}
	return out;
}












