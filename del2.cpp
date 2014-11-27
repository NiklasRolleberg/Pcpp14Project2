#include <iostream>
#include <cmath>
#include "matrix.hpp"
using namespace std;
#include "r8lib.h"
#include "r8lib.cpp"
#include "r8mat_expm1.h"
#include "r8mat_expm1.cpp"


Matrix matlabExpm(Matrix in);
double myexp(double x, double tol);
Matrix myMatrixExp(Matrix x, double tol);
void all(Matrix A);

int main()
{
    Matrix A("2 2 1.0 2.0 3.0 4.0");// 5.0 6.0 7.0 8.0 9.0");

    std::cout << "A:" << std::endl;
    A.printMatrix();
    all(A);

    /*
    std::cout << "\nOur matrix exponent" << std::endl;
    Matrix myMatrix = myMatrixExp(A, 10e-6);
    myMatrix.printMatrix();

    std::cout << "\nMatlabs matrix exponent" << std::endl;
    Matrix matlabMatrix = matlabExpm(A);
    matlabMatrix.printMatrix();
    */


	return 0;
}

void all(Matrix A)
{
    std::cout << "\nOur matrix exponent" << std::endl;
    Matrix myMatrix = myMatrixExp(A, 10e-6);
    myMatrix.printMatrix();

    std::cout << "\nMatlabs matrix exponent" << std::endl;
    Matrix matlabMatrix = matlabExpm(A);
    matlabMatrix.printMatrix();

    std::cout << "\nmyMatrix - matlabMatrix" << std::endl;
    myMatrix -= matlabMatrix;
    myMatrix.printMatrix();
}

Matrix matlabExpm(Matrix in)
{
    double* temp = new double[in.N*in.N];
    for(int i=0;i<in.N;++i)
        for(int j=0;j<in.N;++j)
            temp[j+i*in.N] = in.A[i+j*in.N];

    temp = r8mat_expm1(in.N, temp);

    for(int i=0; i<in.N; ++i)
        for(int j=0; j<in.N; ++j)
            in.A[i+j*in.N] = temp[j+i*in.N];

//    std::cout << "\n\n------cout:-------" << std::endl;
//    for(int i=0;i<in.N;++i)
//    {
//        for(int j=0;j<in.N;++j)
//        {
//            std::cout << temp[i+j*in.N] << " ";
//        }
//        std::cout << std::endl;
//    }
//    std::cout << "\n---printmatrix:---" << std::endl;
//    in.printMatrix();
//    std::cout << "------------------\n\n" << std::endl;

    delete[] temp;
    return Matrix(in);
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
