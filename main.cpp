#include <iostream>
#include "matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Matriz X(3,1), A(3,3), C(3,3);
	A.unit(); // inicializa A como uma matriz identidade
	A(2,1)=10; // altera o valor de uma posição de A
<<<<<<< HEAD
	cout << A << endl;
	C.ones(); // inicializa C com zeros
	cout << "zeros" <<endl;
	cout << C << endl;
=======
	C.zeros(); // inicializa C com zeros
>>>>>>> f3255263db1801cc20d7d33d57f722e07a83808c
	C=A+A; // Soma
	C-=A; // Subtração
<<<<<<< HEAD
	cout << "sub" <<endl;
	cout << C << endl;
	A=C-A; // Subtração	
	cout << "sub" <<endl;
	cout << A << endl;
=======
	A=C-A; // Subtração
>>>>>>> f3255263db1801cc20d7d33d57f722e07a83808c
	A+=A; // Soma
	A=~C; // A é igual a transposta de C
	X.ones(); // inicializa X com 1s
	X*=2; // multiplicação por uma constante
<<<<<<< HEAD
	cout << "mult constante" <<endl;
	cout << X << endl;
	C*=X; // multiplicação de matrizes
	cout << "mult" <<endl;
	cout << C << endl; // Impressão de matrizes
	C=A*X; // multiplicação de matrizes
	cout << "mult" <<endl;
=======
	C=A*X; // multiplicação de matrizes
	C*=X; // multiplicação de matrizes
>>>>>>> f3255263db1801cc20d7d33d57f722e07a83808c
	cout << C << endl; // Impressão de matrizes
	int numerolinhas = X.getRows();
	int numerocolunas = X.getCols();
	A.~Matriz();
	cout<<A<<endl;
}
