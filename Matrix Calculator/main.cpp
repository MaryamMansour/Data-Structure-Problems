#include <iostream>
#include "Matrix.h"

using namespace std;


template<class K>
istream& operator>> (istream& in, Matrix<K>& m)
{

    for (int i = 0; i < m.rows; i++)
        for (int j = 0; j < m.cols; j++)
            in >> m.mat[i][j];

    return in;
}


template <class K>
ostream& operator<<(ostream& out, const Matrix<K>& m) {
      for (int i= 0; i< m.rows; i++){
        for (int j= 0; j < m.cols; j++)
        out<< m.mat[i][j]<<"  ";
        out<<endl;
        }return out;
}




class MatrixCalc
{
public:
    MatrixCalc()
    {};

//---------------------------------------------------------------------------------------

template<class T>
bool checkMulti(Matrix<T>& mat1 ,Matrix<T>&mat2)
{
    if(mat1.getcol()== mat2.getrow())
        return true;
    else
        return false;
}

template<class T>
bool checkAddSub(Matrix<T>& mat1 ,Matrix<T>&mat2)
{
    if(mat1.getrow()== mat2.getrow() && mat1.getcol()== mat2.getcol())
        return true;
    else
        return false;
}

//---------------------------------------------------------------------------------------

template<class T>
void printMenu()
{
    cout << "Welcome to Our Matrix Calculator"<<endl;
    cout << "----------------------------------------------"<<endl;
int flag=1,num;

    while(flag)
    {
        cout << "1- Perform Matrix Addition"<<endl<<"2- Perform Matrix Subtraction."<<endl;
        cout<<"3- Perform Matrix Multiplication."<<endl<<"4- Matrix Transpose." <<endl<<"0- To Exit the calculator."<<endl;
        cin >> num;
if(num == 0)
flag = 0;

     else   {
int r1, c1, r2, c2;
    cout << "Enter matrix 1 dimensions: ";
    cin >> r1 >> c1;
    cout << "Enter matrix 2 dimensions: ";
    cin >> r2 >> c2;

    Matrix <T>mat1(r1, c1);
    Matrix <T>mat2(r2, c2);
    cout << "Enter matrix 1 elements: " << endl;
    cin >> mat1;
    cout << "Enter matrix 2 elements: " << endl;
    cin >> mat2;


if(num == 1){

            if(checkAddSub(mat1,mat2))
                {

                cout <<"\nMatrix 1 + Matrix 2 = "<<endl<<(mat1+ mat2)  <<endl;
                }
            else    cout<<"Error !Rows and Columns are not equal\n";
}

if(num == 2){
          if(checkAddSub(mat1,mat2))
                {
                cout <<"\nMatrix 1 - Matrix 2 = "<<endl<< (mat1 - mat2)<<endl;
                }
            else    cout<<"Error !Rows and Columns are not equal\n";
}

if(num == 3)
{
            if(checkMulti(mat1, mat2)){
                cout <<"\nMatrix 1 * Matrix 2 = "<<endl<< (mat1*mat2);
            }
            else   cout<<"Error !Rows and Columns are not equal\n";
}


if(num == 4){

            cout << "transposed the first Matrix : " << endl;
            cout << mat1.transpose() << endl;
        }

        }
}}

};

int main()
{

    Matrix <double> MyMatrix;
    MatrixCalc MyCalculator;
MyCalculator.printMenu<double>();

    return 0;
}

