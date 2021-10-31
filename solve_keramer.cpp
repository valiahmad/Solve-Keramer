// solve_keramer.cpp
#include <iostream>
using namespace std;
double solve_det(double mat[3][3]) {
	double answ;
	answ = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
		- mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
		+ mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
	return answ;
}
void det_3x3(double matrix[3][3], double answ[3]) {
	double A[3][3] = {
		{answ[0],matrix[0][1],matrix[0][2]},
		{answ[1],matrix[1][1],matrix[1][2]},
		{answ[2],matrix[2][1],matrix[2][2]}
	};
	double B[3][3] = {
		{matrix[0][0],answ[0],matrix[0][2]},
		{matrix[1][0],answ[1],matrix[1][2]},
		{matrix[2][0],answ[2],matrix[2][2]}
	};
	double C[3][3] = {
		{matrix[0][0],matrix[0][1],answ[0]},
		{matrix[1][0],matrix[1][1],answ[1]},
		{matrix[2][0],matrix[2][1],answ[2]}
	};
	//////////////////////////////////////////////////
	//************************************************
	double det = solve_det(matrix);
	double a, b, c;
	a = solve_det(A);
	b = solve_det(B);
	c = solve_det(C);
	//////////////////////
	//*******************
	if (!det)cout << "\nNo Answer!";
	else {
		cout << "\nA is : " << a / det;
		cout << "\nB is : " << b / det;
		cout << "\nC is : " << c / det;
	}
}

int main()
{
	double Q[3][3] = {
		{7,-3,-4},
		{-3,6,-2},
		{-4,-2,11}
	};
	double A[3] = { -11,3,25 };
	det_3x3(Q, A);


	return 0;
}