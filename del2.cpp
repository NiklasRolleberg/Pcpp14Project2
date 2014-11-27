#include <iostream>
#include <cmath>
#include <cstring>
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
    string svar;
    cout << "Vill du skriva in matrisen själv?" << endl;
    cin >> svar;
    if (svar == "ja")
    {
        cout << "Skriv en matris på formen:\nrows cols elm1 elm2 elm3... (matrisen skrivs rad for rad)";
        svar ="";
        cin >> svar;
        Matrix A(svar);
    }
    {
        svar = "3 3 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0";
    }


    Matrix A(svar);

    cout << "Matrix:" << endl;
    A.printMatrix();
    all(A);

	return 0;
}

/**Calculates exponents and compares*/
void all(Matrix A)
{
    cout << "\nOur matrix exponent" << endl;
    Matrix myMatrix = myMatrixExp(A, 10e-6);
    myMatrix.printMatrix();

    cout << "\nMatlab matrix exponent" << endl;
    Matrix matlabMatrix = matlabExpm(A);
    matlabMatrix.printMatrix();

    cout << "\nError (Our matrix exponent - matlab exponent)" << endl;
    myMatrix -= matlabMatrix;
    myMatrix.printMatrix();

    cout << "Error (norm) " << myMatrix.norm();

}

/**Computes the matrix exponent with matlabs algorithm*/
Matrix matlabExpm(Matrix in)
{
    /*transpose the matrix.(our matrix is not stored Fortran-style*/
    double* temp = new double[in.N*in.N];
    for(int i=0;i<in.N;++i)
        for(int j=0;j<in.N;++j)
            temp[j+i*in.N] = in.A[i+j*in.N];

    temp = r8mat_expm1(in.N, temp);

    for(int i=0; i<in.N; ++i)
        for(int j=0; j<in.N; ++j)
            in.A[i+j*in.N] = temp[j+i*in.N];

    delete[] temp;
    return Matrix(in);
}

/**Computes the matrix exponent with horners method */
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
        newNorm = mexp.norm();
        N += 10;
        if(N > 1000)
            break;
    }
    return mexp;
}

/**Calculates the exponent of a scalar*/
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
        N += 10;
    }
    return myExp;
}
