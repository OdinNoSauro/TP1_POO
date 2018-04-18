#include <iostream>
#include "matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Matriz X(3,1), A(3,3), C(3,3);
	A.unit(); // inicializa A como uma matriz identidade
	//A(2,1)=10; // altera o valor de uma posi��o de A
	C.zeros(); // inicializa C com zeros
	C=A+A; // Soma
	C-=A; // Subtra��o
	A=C-A; // Subtra��o
	A+=A; // Soma
	A=~C; // A � igual a transposta de C
	X.ones(); // inicializa X com 1s
	cout << X << endl; // Impress�o de matrizes
	X*=2; // multiplica��o por uma constante
	cout << X << endl; // Impress�o de matrizes
	C=A*X; // multiplica��o de matrizes
	cout << C << endl; // Impress�o de matrizes
	C*=X; // multiplica��o de matrizes
	cout << C << endl; // Impress�o de matrizes
	int numerolinhas = X.getRows();
	int numerocolunas= X.getCols();
	cout << numerolinhas << endl << numerocolunas << endl;
}
