#include <iostream>
#include <cmath>
#include "matrix.hpp"

double t;
double myexp(double x, double tol);
Matrix myMatrixExp(Matrix x, double tol);

int main()
{
    //std::string temp;
    //std::cin >> temp;

    //test//
    //Matrix test1 = Matrix(10);
    //Matrix test2(10);
    //Matrix test3 = test2;
    //test2.printMatrix();

    /*
    std::cout << "Matrix:\n0 1 2\n3 4 5\n6 7 8\nSamma matrix:\n" << std::endl;
    Matrix skrivTest("3 3 0.0 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 1.1 1.2");
    skrivTest.printMatrix();
    */
    /*
    Matrix v1;
    Matrix V2;
    Matrix V3;

    Matrix t1("4 4 0.0 0.8 0.1 0.1 0.1 0.0 0.8 0.1 0.1 0.1 0.0 0.8 0.8 0.1 0.1 0.0");
    Matrix t2("4 4 0.9 0.1 0.0 0.0 0.0 0.9 0.1 0.0 0.0 0.0 0.9 0.1 0.1 0.0 0.0 0.9");
    //Matrix t3(4);

    std::cout << "t1 norm = " << t1.norm() << std::endl;
    t1.printMatrix();
    //std::cout << "\nt2 norm = " << t2.norm() << std::endl;
    //t2.printMatrix();

    std::cout << "\ntest_2"<< std::endl;
    v1 = t1;
    std::cout << "Before" << std::endl;
    v1.printMatrix();

    std::cout << "\nAfter 1" << std::endl;
    //Matrix temp1(v1.N);
    v1+= t2;
    v1.printMatrix();

    std::cout << "\nAfter 2" << std::endl;
    double t = 0.5;
    v1*= t;
    v1.printMatrix();
    */

    //std::cout << "\nt3 (=t1)" << std::endl;
    //Matrix t3(4);// = t1;
    //Matrix t3("2 2 0.1 0.2 0.3 0.4");// = t1;
    //Matrix t3(t1);
    //t3.printMatrix();
    //std::cout << "\n\n" << std::endl;
    //t2.printMatrix();
    //test3.printMatrix();
    //std::cout << myexp(975, 1e-10);
    //Matrix A = Matrix(10);
    //Matrix B = myMatrixExp(A,10e-4);

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
    int N = 200;
    double expX = 7; //ska bytas ut till någon norm
    Matrix mexp  = Matrix(X.N);
    Matrix I = Matrix(X.N);
    Matrix temp;
    //while (fabs( mexp.norm() - expX) > tol)
    //{
        //break;
        for(int i=N; i>0; i--)
        {
            temp = X;
            temp *= 1./i;
            mexp *= temp;
            mexp += I;
        }
        //std::cout << myExp << std::endl;
        //N += 10;
    //}
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
