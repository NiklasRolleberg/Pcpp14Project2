#include <iostream>
#include <cmath>
#include <cstdlib>
class Matrix
{

public:
    int N; //row
    int M; //col
    double**A; //matrix

    Matrix(int m)
    {
        N = m;
        M = m;
        A = (double**)calloc(m,sizeof(double*));
        for(int i=0;i<m;++i)
            A[i] = (double*)calloc(m,sizeof(double));
    }
    //Matrix(const& Matrix);
    //Matrix(const&& Matrix) noexcept;



    //Matrix& operator=(const Matrix&);
    //Matrix& operator=(const Matrix&&) noexcept;
    //Matrix& operator+=(const Matrix&);
    //Matrix& operator*=(const Matrix&);
    //double norm(const Matrix&);
    void printMatrix() const
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                std::cout << A[i][j] << "  ";
            }
            std::cout <<"\n"<< std::endl;
        }
    }
    //void fillMatrix(....);
};
