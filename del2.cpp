#include <iostream>
#include <cmath>
#include "matrix.hpp"
using namespace std;
#include "r8lib.h"
#include "r8mat_expm1.h"

void matlabExpm(Matrix in);
double myexp(double x, double tol);
Matrix myMatrixExp(Matrix x, double tol);

int main()
{
    Matrix A("2 2 1.0 2.0 3.0 4.0");// 5.0 6.0 7.0 8.0 9.0");

    std::cout << "A:" << std::endl;
    A.printMatrix();

    std::cout << "\nOur matrix exponent" << std::endl;
    myMatrixExp(A, 10e-6).printMatrix();

    std::cout << "\nMatlabs matrix exponent" << std::endl;
    matlabExpm(A);

	return 0;
}

void matlabExpm(Matrix in)
{
    double* temp = new double[in.N];

}

Matrix myMatrixExp(Matrix X, double tol)
{
    int N = 10;
    double newNorm = 1;
    double oldNorm = 0;
    Matrix mexp  = Matrix(X.N);
    Matrix I = Matrix(X.N);

    while (fabs(newNorm - oldNorm) > tol)
    {
        oldNorm = newNorm;
        for(int i=N; i>0; i--)
        {
            mexp *= X*(1./i);
            mexp += I;
        }
        //std::cout << newNorm << " " << oldNorm << std::endl << std::endl;
        newNorm = mexp.norm();
        N += 10;
        if(N > 1000)
            break;
    }
    std::cout << std::endl;
    return mexp;
}

double myexp(double x, double tol)
{
    int N = 10;
    double myExp = 0;
    double expX = exp(x);
    while (fabs(myExp - expX) > tol)
    {
        myExp = 1;
        for(int i=N; i>0; i--)
        {
            myExp *= x/i;
            myExp += 1.;
        }
        //std::cout << myExp << std::endl;
        N += 10;
    }
    return myExp;
}
