#include <iostream>
#include <cmath>
#include <cstdlib>
class Matrix
{

public:
    int N; //row
    int M; //col
    double* A; //matrix  borde ändras till en 1D array

    Matrix(int m)
    {
        N = m;
        //M = m;
        A = new double[m*m];
        //A = (double*)calloc(N*N,sizeof(double));
    }

    /**Copy constructor (deep copy)*/
    Matrix(const Matrix& other)
    {

    }

    /**Move constrictor (Shallow copy)*/
    Matrix(const Matrix&& other) noexcept
    {

    }

    /**Destructor*/
    ~Matrix()
    {
        delete[] A;
    }

    /**Copy-Assignment operator*/
    Matrix& operator=(const Matrix& other)
    {
        /*
        if(&this == other)
            return;
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
        */
    }

    /**Move-någonting*/
    Matrix& operator=(const Matrix&& other) noexcept
    {

    }

    Matrix& operator+=(const Matrix& other)
    {

    }

    Matrix& operator*=(const Matrix& other)
    {

    }

    double norm(const Matrix&)
    {
        double sum = 17.943;
        return sum;
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
