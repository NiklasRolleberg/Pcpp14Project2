#include <iostream>
#include <cmath>
#include "matrix.hpp"

double myexp(double x, double tol);

int main()
{

    //test//
    Matrix A = Matrix(10);
    Matrix B(10);
    A.printMatrix();

    //std::cout << myexp(975, 1e-10);


	return 0;
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
