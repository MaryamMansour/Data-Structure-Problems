#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

template <class T>
class Matrix
{
    private:
        int rows; // rows of the matrix
        int cols; // columns of the matrix
        T **mat; // 2D array

    public:

        Matrix(); // Default constructor
        Matrix(int r, int c); // Parameterized Constructor

        int getrow();
        int getcol();
        Matrix<T> operator+(const Matrix<T>& m);
        Matrix<T> operator-(const Matrix<T>& m);
        Matrix<T> operator*(const Matrix<T>& m);
        //Matrix<T> operator=(const Matrix<T>& m);


        template <class K>
        friend ostream& operator<<(ostream& out, const Matrix<K>& m);
        template <class K>
        friend istream& operator>>(istream& in, Matrix<K>& m);

        Matrix<T> transpose();


        virtual~Matrix(); // Destructor
};


template <class T>
Matrix<T>::Matrix()
{
    rows = 0;
    cols = 0;
 }

template <class T>
Matrix<T>:: Matrix( int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
	    mat = new T*[rows];
    for(int i = 0; i < rows; i++) {
        mat[i] = new T[cols];
        }}

template<class T>
Matrix<T>::getrow()
{
    return rows;
}

template<class T>
Matrix<T>::getcol()
{
    return cols;
}


template <class T>
Matrix<T> Matrix<T>::transpose(){

Matrix<T> trans(cols, rows);

  for (int i=0 ; i<rows ;i++)
    for( int j=0 ; j<cols ;j++)
    trans.mat[j][i] = mat[i][j];

    return trans;

  }



template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix &m)
{
  Matrix <T>temp(cols, m.rows);


      for(int i=0; i < m.rows ; i++)

          for(int j=0; j < m.cols ; j++)
            {
                temp.mat[i][j] = 0;
            for(int c =0; c < m.rows ;c++)
                temp.mat[i][j] += mat[i][c] * m.mat[c][j];
          }
                return temp;

}



template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix &m)
{
Matrix <T>temp( rows, cols);

 for(int i=0 ;i<rows ;i++)
    for(int j=0; j<cols ;j++)
        temp.mat[i][j] = m.mat[i][j] + mat[i][j];

    return temp;

}

    /*
template <class T>
Matrix<T> Matrix<T>::operator=(const Matrix& m){
    mat = new int*[rows];
    for(int i = 0; i < rows; i++) {
        mat[i] = new int[cols];
        for(int j = 0; j < cols; j++) {
            mat[i][j] = 0;
        }
    }
}
*/


template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix &m)
{
Matrix <T>temp( rows, cols);


 for(int i=0; i < rows; i++)
    for(int j=0; j < cols; j++)
        temp.mat[i][j] = mat[i][j] - m.mat[i][j];

    return temp;
    }




template <class T>
Matrix<T>::~Matrix() {
    for(int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}




#endif // MATRIX_H
