// headers do código da matriz
#include <iostream>
using namespace std;
#ifndef MATRIZ_h
#define MATRIZ_h

class Matriz{
	private:
		int num_linhas;
		int num_colunas;
		double **array;
	public:
		Matriz(int linhas, int colunas);
		Matriz();
		~Matriz();
		aloca_array();
		void zeros();
		void unit();
		void ones();
		int getRows();
		int getCols();
		double& operator()(int linha, int coluna);
		Matriz operator+(const Matriz& m);
		Matriz operator-=(const Matriz& m);
		Matriz operator+=(const Matriz& m);
		Matriz operator~();
		Matriz operator=(const Matriz& m);
		Matriz operator-(const Matriz& m);
		Matriz operator*=(const Matriz& m);
		Matriz operator*=(double);
		Matriz operator*(const Matriz& m);
		friend ostream& operator<<(ostream& out, const Matriz& m);

};

#endif
