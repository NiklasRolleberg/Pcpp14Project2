#include <iostream>
#include <cmath>
#include "matrix.hpp"

double t;
double myexp(double x, double tol);
Matrix myMatrixExp(Matrix x, double tol);

int main()
{
    Matrix A("3 3 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0");
    Matrix B("3 3 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0");

    std::cout << "A:" << std::endl;
    A.printMatrix();
    std::cout << "\nB:" << std::endl;
    B.printMatrix();


   /* //Funkar
    std::cout << "\nA*B:" << std::endl;
    A*=B;
    A.printMatrix();


    //Funkar
    std::cout << "\nA+B:" << std::endl;
    A+=B;
    A.printMatrix();

    std::cout << "\nA*0.5:" << std::endl;
    t = 0.5;
    A*=t;
    A.printMatrix();*/

    std::cout << "\nMatrix exponent" << std::endl;
    myMatrixExp(A, 10e-6).printMatrix();

	return 0;
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
        std::cout << newNorm << " " << oldNorm << std::endl << std::endl;
        newNorm = mexp.norm();
        N += 10;
        if(N > 1000)
            break;
    }
    std::cout << endl;
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
