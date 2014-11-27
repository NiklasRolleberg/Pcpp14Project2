#include <iostream>
#include <cmath>

double myexp(double x, double tol);

int main()
{

    std::cout << "exp(9) = " << myexp(9, 1e-10);
    std::cout << std::endl << "Error: " << exp(9) - myexp(9, 1e-10);


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
