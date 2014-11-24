#include <iostream>
#include <cmath>
#include "matrix.hpp"

double myexp(double x, double tol);
Matrix myMatrixExp(Matrix x, double tol);

int main()
{

    //test//
    Matrix test1 = Matrix(10);
    Matrix test2(10);
    Matrix test3 = test2;
    test2.printMatrix();
    std::cout << "\n\n" << std::endl;
    test3.printMatrix();
    //std::cout << myexp(975, 1e-10);
    Matrix A = Matrix(10);
    //Matrix B = myMatrixExp(A,10e-4);

	return 0;
}


Matrix myMatrixExp(Matrix X, double tol)
{
    int N = 10;
    double expX = 7; //ska bytas ut till någon norm
    Matrix mexp  = Matrix(X.N);
    while (fabs( mexp.norm() - expX) > tol)
    {
        break;
        for(int i=N; i>0; i--)
        {
            //myExp *= x/i;
            //myExp += 1.;
        }
        //std::cout << myExp << std::endl;
        N += 10;
    }
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
