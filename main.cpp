#include <iostream>
#include "matriz.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Matriz X(3,1), A(3,3), C(3,3);
	A.unit(); // inicializa A como uma matriz identidade
	A(2,1)=10; // altera o valor de uma posição de A
	cout << A << endl;
	C.zeros(); // inicializa C com zeros
	cout << "zeros" <<endl;
	cout << C << endl;
	C=A+A; // Soma
	cout << "soma" <<endl;
	cout << C << endl;
	C-=A; // Subtração
	cout << "sub" <<endl;
	cout << C << endl;
	A=C-A; // Subtração
	cout << "sub" <<endl;
	cout << A << endl;
	A+=A; // Soma
	cout << "soma" <<endl;
	cout << A << endl;
	A=~C; // A é igual a transposta de C
	cout << "transposta" <<endl;
	cout << A << endl;
	X.ones(); // inicializa X com 1s
	cout << "ones" <<endl;
	cout << X << endl;
	X*=2; // multiplicação por uma constante
	cout << "mult constante" <<endl;
	cout << X << endl;
	C=A*X; // multiplicação de matrizes
	cout << "mult" <<endl;
	cout << C << endl; // Impressão de matrizes
	cout << A << endl;
	cout << X << endl;
	C*=X; // multiplicação de matrizes
	cout << "mult" <<endl;
	cout << C << endl; // Impressão de matrizes
	int numerolinhas = X.getRows();
	int numerocolunas = X.getCols();
}
