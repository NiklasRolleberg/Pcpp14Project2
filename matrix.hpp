#include <iostream>
#include <cmath>
#include <cstdlib>
class Matrix
{

public:
    int N; //row
    int M; //col
    double**A; //matrix  borde �ndras till en 1D array

    Matrix(int m)
    {
        N = m;
        M = m;
        A = (double**)calloc(m,sizeof(double*));
        for(int i=0;i<m;++i)
            A[i] = (double*)calloc(m,sizeof(double));
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
        for(int i= M-1;i<=0;--i)
            delete[] A[i];
        delete[] A;
    }

    /**Copy-Assignment operator*/
    Matrix& operator=(const Matrix& other)
    {
        if(this == &other)
            return;
        if(N == other->N)
        {
            for(int i=0;i<this->N;++i)
            {
                for(int j=0;j<this->M;++j)
                {
                    this->A[i][j] = other->A[i][j];
                }
            }
        }
        else
        {
            delete[] A;
            N = 0;
            M = 0;

            A = new double[other->N][other->M];
            for(int i=0;i<N;++i)
                for(int j=0;j<M;++j)
                    A[i][j] = other->A[i][j];
        }

    }

    /**Move-n�gonting*/
    Matrix& operator=(const Matrix&&) noexcept;

    Matrix& operator+=(const Matrix& other)
    {

    }

    Matrix& operator*=(const Matrix& other)
    {
        int newRows = N;
		int newCols = M;

		double** temp;
		temp = (double**)calloc(newRows , sizeof(double *));
		for(int i=0 ; i< newRows ; ++i)
			temp[i] = (double*)calloc(newCols , sizeof(double));

		//R�KNA!
		double t;
		int i,j,k;
		for (i=0;i<newRows;++i)
		{
			for(j=0;j<newCols;++j)
			{
				t = 0;
				//row in first matrix X col in second matrix;
				for(k=0;k<M;++k)
					t+= (A[i][k] * other.A[k][j]);
				temp[i][j] = t;
			}
		}
		A = temp;
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
            for(int j=0;j<M;++j)
            {
                std::cout << A[i][j] << "  ";
            }
            std::cout <<"\n"<< std::endl;
        }
    }

    void fillMatrix(std::string in)
    {
        //g�ra som i HMM.
    }
};
