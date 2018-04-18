#include <iostream>
#include "matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Matriz X(3,1), A(3,3), C(3,3);
	A.unit(); // inicializa A como uma matriz identidade
	//A(2,1)=10; // altera o valor de uma posição de A
	C.zeros(); // inicializa C com zeros
	C=A+A; // Soma
	C-=A; // Subtração
	A=C-A; // Subtração
	A+=A; // Soma
	A=~C; // A é igual a transposta de C
	X.ones(); // inicializa X com 1s
	X*=2; // multiplicação por uma constante
	C=A*X; // multiplicação de matrizes
	C*=X; // multiplicação de matrizes
	cout << C << endl; // Impressão de matrizes
	int numerolinhas = X.getRows();
	int numerocolunas= X.getCols();
}
