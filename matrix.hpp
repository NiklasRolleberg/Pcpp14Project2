#include <iostream>
#include <cmath>
#include <cstdlib>
class Matrix
{

public:
    int N; //row
    double* A; //matrix  borde ändras till en 1D array

    Matrix(int n)
    {
        N = n;
        //M = m;
        A = new double[n*n];
        for(int i=0;i<N*N;++i)
            A[i] = 0;
    }

    /**Copy constructor (deep copy)*/
    Matrix(const Matrix& other)
    {
        N = other.N;
        A = new double[N*N];
        for(int i=0;i<N*N;++i)
        {
            A[i] = other.A[i];
        }
    }

    /**Move constructor (Shallow copy)*/
    Matrix(const Matrix&& other) noexcept //Onödig
    {
        std::cerr << "Copy constructor" << std::endl;
    }

    /**Destructor*/
    ~Matrix()
    {
        std::cerr << "Destructor" << std::endl;
        delete[] A;
    }

    /**Copy-Assignment operator*/
    Matrix& operator=(const Matrix& other)
    {
        /*
        if(&this == other)
            return;
        */
        if(N == other.N)
        {
            for(int i=0;i<N*N;++i)
            {
                A[i] = other.A[i];
            }
        }
        else
        {
            delete[] A;
            N = other.N;
            //M = 0;
            A = new double[N*N];

            for(int i=0;i<N*N;++i)
                A[i] = other.A[i];
        }
    }

    /**Move-någonting*/
    Matrix& operator=(const Matrix&& other) noexcept
    {
        std::cerr << "Move operator nr1" << std::endl;
    }

    Matrix& operator+=(const Matrix& other)
    {
        std::cerr << "+=" << std::endl;

    }

    Matrix& operator*=(const Matrix& other)
    {
        std::cerr << "*=" << std::endl;
    }

    /**Frobenius norm*/
    double norm()
    {
        double sum = 0;
        for(int i=0;i<N*N;++i)
            sum += A[i]*A[i];
        return sqrt(sum);
    }


    void printMatrix() const
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                std::cout << A[i+j*N] << "(" << i+j*N << ")  ";
            }
            std::cout <<"\n"<< std::endl;
        }
    }

    void fillMatrix(std::string in)
    {
        //göra som i HMM.
    }
};
