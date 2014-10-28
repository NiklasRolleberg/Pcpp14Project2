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



    Matrix& operator=(const Matrix& other)
    {
        M = other.M;
        N = other.N;
        A = initialize(M,N);
        for(int i=0;i<M;++i)
            for(int j=0;j<N;++j)
                A[i][j] = other.A[i][j];
    }
    //Matrix& operator=(const Matrix&&) noexcept;

    Matrix& operator+=(const Matrix& other)
    {
        for(int i=0;i<M;++i)
            for(int j=0;j<N;++j)
                A[i][j] += other.A[i][j];
    }

    Matrix& operator*=(const Matrix& other)
    {
        int newRows = N;
		int newCols = M;

		double** temp;
		temp = (double**)calloc(newRows , sizeof(double *));
		for(int i=0 ; i< newRows ; ++i)
			temp[i] = (double*)calloc(newCols , sizeof(double));

		//RÄKNA!
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

    /**Creates a nxm matrix*/
    double** initialize(int rows, int cols)
    {
        double** temp;
        temp = (double**)calloc(rows , sizeof(double *));
        for(int i=0 ; i< rows ; ++i)
        temp[i] = (double*)calloc(cols , sizeof(double));
        return temp;
    }


};
