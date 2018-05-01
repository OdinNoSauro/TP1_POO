
#include "matriz.h"
#include <iostream>
#include <string>
using namespace std;


Matriz::Matriz(int linhas, int colunas){
	num_linhas = linhas;
	num_colunas = colunas;
	aloca_matriz();
}

Matriz::Matriz(){
	num_linhas = 0;
	num_colunas = 0;
	array = NULL;
}

Matriz::Matriz(const Matriz& origem){
    this->num_colunas = origem.num_colunas;
    this->num_linhas = origem.num_linhas;
    this->aloca_matriz();
    for (int i = 0; i < this->num_linhas; i++){
        for (int j = 0; j < this->num_colunas; j++){
            this->array[i][j] = origem.array[i][j];
        }
    }
}

Matriz::~Matriz(){
	for(int i = 0; i<this->num_linhas;i++)
		delete[] this->array[i];
	delete[] this->array;
	this->array = NULL;
	this->num_colunas = 0;
	this->num_linhas = 0;
}

Matriz::aloca_matriz(){
	int i;
	array = new double* [num_linhas];
	for(i=0;i<num_linhas;i++)
		array[i] = new double[num_colunas];
}

void Matriz::unit(){
	int i,j;
	for(i=0;i<num_linhas;i++){
		for(j=0;j<num_colunas;j++){
			if(i==j)
				array[i][j]=1;
			else
				array[i][j]=0;
		}
	}
}

void Matriz::zeros(){
	int i,j;
	for(i=0;i<num_linhas;i++){
		for(j=0;j<num_colunas;j++){
			array[i][j]=0;
		}
	}
}

void Matriz::ones(){
	int i,j;
	for(i=0;i<this->num_linhas;i++){
		for(j=0;j<this->num_colunas;j++){
			array[i][j]=1;
		}
	}
}
int Matriz::getRows(){
	return num_linhas;
}

int Matriz::getCols(){
	return num_colunas;
}

double& Matriz::operator()(int linha, int coluna){
	return this->array[linha][coluna];
}

Matriz Matriz::operator+(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompativeis"<<endl;
		return (*this);
	}
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.array[i][j] = this->array[i][j] + m.array[i][j];
		}
	}
	return new_mat;
}

Matriz Matriz::operator-(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompativeis"<<endl;
		return (*this);
	}
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.array[i][j] = this->array[i][j] - m.array[i][j];
		}
	}
	return new_mat;
}

Matriz Matriz::operator+=(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompativeis"<<endl;
		return (*this);
	}
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->array[i][j] += m.array[i][j];
		}
	}
	return *this;
}

Matriz Matriz::operator-=(const Matriz& m){
	if (this->num_linhas != m.num_linhas || this->num_colunas != m.num_colunas){
		cout << "Tamanhos das matrizes incompativeis"<<endl;
		return (*this);
	}
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			this->array[i][j] -= m.array[i][j];
		}
	}
	return *this;
}

Matriz Matriz::operator~(){
	Matriz new_mat(this->num_linhas,this->num_colunas);
	for (int i=0; i<this->num_linhas; i++){
		for (int j=0; j<this->num_colunas; j++){
			new_mat.array[j][i] = this->array[i][j];
			}
	}
	return new_mat;
}

Matriz Matriz::operator=(const Matriz& m){
	if (this == &m) 
		return*this;
	this->~Matriz();
	this->num_linhas = m.num_linhas;
	this->num_colunas = m.num_colunas;
	this->aloca_matriz();
	for (int i=0; i<m.num_linhas; i++){
		for (int j=0; j<m.num_colunas; j++){
			this->array[i][j] = m.array[i][j];
		}
	}
	return *this;
}
	
Matriz Matriz::operator*=(const Matriz& m){
    if (this->num_colunas != m.num_linhas){
		cout << "Tamanhos das matrizes incompativeis" << endl;
		return (*this);
	}
    Matriz new_mat(this->num_linhas, m.num_colunas);
    new_mat.zeros();
    for (int i = 0; i < new_mat.num_linhas; i++) {
        for (int j = 0; j < new_mat.num_colunas; j++) {
            for (int k = 0; k < this->num_colunas; k++) {
                new_mat.array[i][j] += (this->array[i][k] * m.array[k][j]);
            }
        }
    }
    this->num_colunas = m.num_colunas;
    return (*this = new_mat);
}

Matriz Matriz::operator*=(double constante){
    for (int i = 0; i < this->num_linhas; i++) {
        for (int j = 0; j < this->num_colunas; j++) {
            this->array[i][j] *= constante;
        }
    }
    return *this;
}

Matriz Matriz::operator*(const Matriz& m){
    if (this->num_colunas != m.num_linhas){
		cout << "Tamanhos das matrizes incompativeis"<<endl;
		return (*this);
	}
    Matriz new_mat(this->num_linhas, m.num_colunas);
    new_mat.zeros();
    for (int i = 0; i < new_mat.num_linhas; i++) {
        for (int j = 0; j < new_mat.num_colunas; j++) {
            for (int k = 0; k < this->num_colunas; k++) {
                new_mat.array[i][j] += (this->array[i][k] * m.array[k][j]);
            }
        }
    }
    return (new_mat);
}


ostream& operator<<(ostream& out, const Matriz& m){
	if (m.num_linhas == 0 && m.num_colunas == 0 ){
		out<< "Matriz vazia"<<endl;
		return out;
	}	
	for (int i = 0; i < m.num_linhas; i++) {
        out << m.array[i][0];
        for (int j = 1; j < m.num_colunas; j++) {
            out << "\t" << m.array[i][j];
        }
        out << endl;
    }
    return out;
}
















