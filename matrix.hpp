#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
class Matrix
{

public:
    int N; //row
    double* A;

    Matrix()
    {
        N = 0;
        //std::cerr << "constructor 0" << std::endl;
    }

    /**unit matrix*/
    Matrix(int n)
    {
        N = n;
        A = new double[n*n];
        for(int i=0;i<N*N;++i)
        {
            A[i] = 0;
        }
        for(int i=0;i<N*N;i+=(N+1))
            A[i] = 1;
    }

    Matrix(std::string in)
    {
        //std::cerr << "fillmatrix" << std::endl;
        int row;
        int col;


        std::istringstream iss;
		iss.str(in);
		iss >> row >> col;

        if(row!=col || row == 0)
        {
            //std::cerr << "fel dim" << std::endl;
            exit(1);
        }

        delete[] A;
        N = row;
        A = new double[N*N];

        //assert( f != null );
        for(int i=0;i<N*N;++i)
            iss >> A[i];
    }

    /**Copy constructor (deep copy)*/
    Matrix(const Matrix& other)
    {
        //std::cerr << "Copy constructor" << std::endl;
        N = other.N;
        A = new double[N*N];
        for(int i=0;i<N*N;++i)
            A[i] = other.A[i];
    }

    /**Move constructor (Shallow copy)*/
    Matrix(const Matrix&& other) noexcept //Onödig
    {
        //std::cerr << "Move constructor" << std::endl;
        N = other.N;
        A = other.A;
        //other.N = 0;
        //other.A  = nullptr;
    }

    /**Destructor*/
    ~Matrix()
    {
        //std::cerr << "Destructor" << std::endl;
        delete[] A;
    }

    /**Copy-Assignment operator*/
    Matrix& operator=(const Matrix& other)
    {
        //std::cerr << "Copy assignment operator" << std::endl;
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
            A = new double[N*N];

            for(int i=0;i<N*N;++i)
                A[i] = other.A[i];
        }
        return *this;
    }

    /**Move-någonting*/
    Matrix& operator=(const Matrix&& other) noexcept
    {
        //std::cerr << "Move operator (&&)" << std::endl;
        return *this;
    }

    Matrix& operator+=(const Matrix& other)
    {
        //std::cerr << "+= operator" << std::endl;

        if(N != other.N)
        {
            //std::cerr << "fel dim" << std::endl;
            exit(1);
        }

        for(int i=0;i<N*N;++i)
            A[i] += other.A[i];

        return *this;
    }

    /**Matrix x Matrix*/
    Matrix& operator*=(const Matrix& other)
    {
        //std::cerr << "*=" << std::endl;

        if(N!= other.N)
            exit(1);

        double temp[N*N];

        for (int i=0;i<N;++i)
		{
			for(int j=0;j<N;++j)
			{
				double t = 0;
				for(int k=0;k<N;++k)
					t+= (A[k+i*N] * other.A[j+k*N]);
				temp[j+i*N] = t;
			}
		}

        for(int i=0;i<N*N;++i)
            A[i] = temp[i];

        //delete[] temp;
        return *this;
    }

    /**Matrix x double*/
    Matrix& operator*=(const double& d)
    {
        //std::cerr << "*= (double)" << std::endl;
        for(int i=0;i<N*N;++i)
            A[i] *= d;
        return *this;
    }

    /**Matrix x double*/
    Matrix operator*(const double rhs)
    {
        //std::cerr << "* (matrix x double)" << std::endl;
		Matrix temp(N);
		for(int i=0;i<N*N;++i)
            temp.A[i] = A[i]*rhs;
		return temp;
    }

    /**Frobenius norm*/
    double norm()
    {
        double sum = 0;
        for(int i=0;i<N*N;++i)
            sum += A[i]*A[i];
        return sqrt(sum);
    }

    /**Printmatrix*/
    void printMatrix() const
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<N;++j)
            {
                std::cout << A[j+i*N] << "  ";//<< "(" << i+j*N << ")  ";
            }
            std::cout <<"\n"<< std::endl;
        }
    }

    Matrix& operator-=(const Matrix& other)
    {
        //std::cerr << "-= operator" << std::endl;

        if(N != other.N)
        {
            //std::cerr << "fel dim" << std::endl;
            exit(1);
        }

        for(int i=0;i<N*N;++i)
            A[i] -= other.A[i];

        return *this;
    }
};
