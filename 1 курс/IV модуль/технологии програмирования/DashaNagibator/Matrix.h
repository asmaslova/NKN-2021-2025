#include <iostream>
// #include <conio.h>
//C:/msys64/mingw64/include/**
using namespace std;

class Matrix{
private:
    int height; //Максимальный размер вектора
    int width;
    int** arr; //Указатель на область памяти, где будет находиться массив.

public:

    //Деструктор
    ~Matrix() {}
    
     /*void Del()
         {
             for (int z = 0; z < height; z++)
                 delete[] arr[z];
             delete[] arr;
        }*/
 
    void Create() {
        arr = new int* [height];
        for (int z = 0; z < height; z++) {
            arr[z] = new int[width];
        }
    }
        
    // Функция для добавления элемента
    void setMatrix()
    {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cin >> arr[i][j];
            }
        }
    }
    
     Matrix()
        {
            int height = 0;
            int width = 0;
            int arr = 0;
        }

        Matrix(int height, int width)
        {
            this->height = height;
            this->width = width;
            Create();
        }
        
    /*void Matrix_copy(const Matrix& right)
    {
        Del();
        Create();
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                arr[i][j] = right.arr[i][j];
    }*/

    //Функция печати вектора
    void print() {
        for (int i = 0; i < this->height; i++) {
            for (int j = 0; j < this->width; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
       
    }
        
    //Прототипы операторов
    Matrix operator + (Matrix& right);
    Matrix operator - ();
    Matrix& operator = (const Matrix& b);
    Matrix operator * (int p);
    Matrix operator * (Matrix& right);
    Matrix operator - (Matrix& right);
};


Matrix Matrix::operator + (Matrix& right)
{
    if (this->width != right.width || this->height != right.height)
    {
        cout << "Матрицы разного размера";
        exit(1);
    }
    Matrix result(right.height, right.width);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.arr[i][j] = this->arr[i][j] + right.arr[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator - (Matrix& right)
{
    if (right.width != this->width || right.height != this->height)
    {
        cout << "Матрицы разного размера";
        exit(1);
    }
    Matrix result(this->height, this->width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result.arr[i][j] = this->arr[i][j] - right.arr[i][j];
        }
    }

    return result;
}

Matrix &Matrix::operator=(const Matrix& r) // оператор присваивания
      {  
        if (this != &r) 
        { 
           for ( int i = 0; i < this->height; i++ )
            {
                delete []arr[i];
            }
            delete []arr;
            this->height = r.height;
            this->width = r.width;

            arr = new int*[height];
            for ( int i = 0; i < this->height; i++ )
            {
                arr[i] = new int[this->width];
            }
            for (int i= 0; i < r.height; ++i) {
            for (int j = 0; j < r.width; ++j) {
               arr[i][j] = r.arr[i][j]; 
            }
            }
        }
   
       return *this;
       
       }

//Перегрузка операторов
Matrix Matrix::operator - ()
{
    Matrix left = *this;
     Matrix result (left.height, left.width) ;
     for (int i = 0; i < left.height; i++) {
        for (int j = 0; j < left.width; j++) {
        result.arr[i][j] = -left.arr[i][j];
    }
    }
    return result;
}

Matrix Matrix::operator * (int p) {
    Matrix result (this->height,this->width);
    for (int i = 0; i < height; i++) {
        for (int j =0; j < width; j++)
        result.arr[i][j] = this->arr[i][j] * p;
    }
    return result;
}

Matrix Matrix:: operator * (Matrix& right) {
    Matrix result(this->height,right.width);
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < right.width; j++) {
            for (int k = 0; k < this->width; k++) {
                result.arr[i][j] += (this->arr[i][j]) * right.arr[i][j];
            }
        }
    }
    return result;
}

