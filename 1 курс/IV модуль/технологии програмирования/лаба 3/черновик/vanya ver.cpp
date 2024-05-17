#include <iostream>
#define maximum 256
using namespace std;


class Vector{
    int *vector;//array
    int dimensions;//dimensions
    int num=0;//num
public:
    friend class Matrix;
    int count=0;
     Vector(int dim, int *v);
     Vector(int dim);
     Vector();
     ~Vector();
     void print();
     Vector operator= (const Vector &r);
     Vector operator+ (Vector &l);
     Vector operator- ();
     Vector operator- (Vector &l);
     Vector operator*(int k);
     Vector operator*(Vector &l);
};

class Matrix{
    int dimension_rows;
    int dimension_colls;
    int** matrix;
public:
    friend class Vector;
    static int count;
    int num;
    Matrix(int dimension_rows, int dimension_colls , int** matrix);
    Matrix(int dimension_rows, int dimension_colls);
    Matrix(const Matrix &x);
    Matrix();
    ~Matrix();
    void print();
    Matrix& operator= (const  Matrix &r);
    Matrix operator+ ( const Matrix &r);
    Matrix operator- ( const Matrix &r);
    Matrix operator- ();
    Matrix operator* ( int k);
    double operator[] ( int i);
    Matrix operator* ( const Matrix &r);
    Vector operator* ( const Vector &r);
};


Matrix::Matrix(int dimension_rows, int dimension_colls , int** matrix),dimension_rows=dimension_rows,dimension_colls=dimension_colls{
    this->dimension_rows = dimension_rows;
    this->dimension_colls = dimension_colls;
    int **tmp = new int[dimension_rows][dimension_colls];
    for (int i = 0; i < this->dimension_rows; i++){
        for (int j = 0; j < this->dimension_colls; j++){
            tmp[i][j] = matrix[i][j];
        }
    }
    this->matrix=tmp;
    for (int i = 0; i < this->dimension_colls*this->dimension_rows; i++){
        cout<<"matrix["<<i<<"] == " <<matrix[i]<<endl;
      }
}


Matrix::Matrix(int dimension_rows, int dimension_colls){
    this->dimension_rows = dimension_rows;
    this->dimension_colls = dimension_colls;
    int *temp = new int[this->dimension_colls*this->dimension_rows];
    for (int i = 0; i < this->dimension_colls*this->dimension_rows; i++){
        temp[i] = 0;
    }
    this->matrix = temp;

}


Matrix::Matrix(){
    this->dimension_rows = 0;
    this->dimension_colls = 0;
    this->matrix = NULL;
}

Matrix::~Matrix(){
    delete[] this->matrix;
}

Matrix Matrix:: operator+(const Matrix &r){
    if(this->dimension_rows!=r.dimension_rows ||this->dimension_colls!=r.dimension_colls)
        exit(13);
    Matrix tmp(this->dimension_rows, this->dimension_colls);
    for(int i=0; i< this->dimension_rows*this->dimension_colls;i++ )
        tmp.matrix[i]=this->matrix[i]+r.matrix[i];
   return tmp;
}

Matrix& Matrix::operator=( const Matrix &r){
    int *tmp = new int[r.dimension_rows*r.dimension_colls];
    cout << "Copying Matrix in new Matrix" << endl;
    for (int i = 0; i < r.dimension_colls*r.dimension_rows; i++){
        tmp[i] = r.matrix[i];
    }
    this->dimension_rows = dimension_rows;
    this->dimension_colls = dimension_colls;
    this->matrix = tmp;
    return *this;
}

Matrix Matrix:: operator-(const Matrix &r){
    if(this->dimension_rows!=r.dimension_rows ||this->dimension_colls!=r.dimension_colls)
        exit(13);
    Matrix tmp(this->dimension_rows, this->dimension_colls);
    for(int i=0; i< this->dimension_rows*this->dimension_colls;i++ )
        tmp.matrix[i]=this->matrix[i]-r.matrix[i];
   return tmp;
}


Matrix Matrix:: operator*(int n){
    Matrix tmp(this->dimension_rows, this->dimension_colls);
    for(int i=0; i< this->dimension_rows*this->dimension_colls;i++ )
        tmp.matrix[i]=this->matrix[i]*n;
    return tmp;
}

Matrix Matrix:: operator*(const Matrix &r){
    if(this->dimension_colls!=r.dimension_rows){
        cout<<"Unavailable"<<endl;
        exit(13);
    }
    Matrix tmp(this->dimension_rows, r.dimension_colls);
    for(int i=0; i< tmp.dimension_rows;i++ ){
        for(int j=0; j< tmp.dimension_colls;j++ ){
                 for (int k = 0; k < r.dimension_rows; k++){

                       tmp.matrix[(tmp.dimension_colls * i)+j] += this->matrix[(this->dimension_rows * i) + k] * r.matrix[(r.dimension_colls * k) + j];
                                                    }
                         }
                     }
   return tmp;
}

Vector Matrix::operator *(const Vector &r){
    if(this->dimension_colls!=r.dimensions)
        exit(13);
        Vector tmp(r.dimensions);
        for(int i=0; i< this->dimension_rows;i++ ){
            for(int j=0; j< this->dimension_colls;j++ ){
                 tmp.vector[i] += (this->matrix[(this->dimension_rows * i) + j] * r.vector[j]);
                }
            }
        return tmp;
}

Matrix Matrix::operator-(){
       Matrix tmp(this->dimension_rows, this->dimension_colls);
    for(int i=0; i< this->dimension_rows*this->dimension_colls;i++ )
        tmp.matrix[i]=this->matrix[i]*(-1);
    return tmp;
}


void Matrix::print(){
    cout<<endl;
        cout<<"Output"<<endl;
        for (int i = 0; i < this->dimension_rows*this->dimension_colls; i++){
            cout<<"matrix["<<i<<"] == " <<this->matrix[i]<<endl;
          }
    cout<<"DONE"<<endl;
        cout<<endl;
}
// VECTORS HERE

Vector ::Vector(int dim, int *v){
    this->dimensions = dim;
    int *tmp = new int[this->dimensions];
    for (int i = 0; i < this->dimensions; i++ ){
        tmp[i] = v[i];
    }
    this->vector = tmp;
    count++;

    num = count;
}


Vector:: Vector(int dim){
    this->dimensions = dim;
    int *tmp = new int[this->dimensions];
    for(int i = 0; i < dimensions; i++){
        tmp[i] = 0;
    }
    this->vector = tmp;
    count++;
    num = count;
}

Vector ::Vector(){
    this->dimensions = 0;
    count++;
    num = count;
}

Vector:: ~Vector(){
    delete vector;
    count--;

    num=0;
}

void Vector :: print(){
    cout <<"Elements of vector ";
    for (int i = 0; i < this->dimensions; i++){
        cout << this->vector[i] << " ";
    }
    cout<<endl;
    cout<< "Amount of vectors total  "<<num<<endl;
}

Vector Vector::operator+(Vector &r){
    if(this-> dimensions != r.dimensions)
        exit(1);
    Vector tmp(dimensions,vector);
    for (int i = 0; i < dimensions; i++)
    {
        tmp.vector[i] += r.vector[i];
    }
    return tmp;
}

Vector Vector::operator- (Vector &r){

    if(this-> dimensions != r.dimensions)
        exit(1);
    Vector tmp(dimensions,vector);
    for (int i = 0; i < dimensions; i++)
    {
        tmp.vector[i] -= r.vector[i];
    }
    return tmp;

}


Vector Vector:: operator*(int k){
        Vector tmp(dimensions,vector);
        for (int i = 0; i < tmp.dimensions; i++){
            tmp.vector[i] *= k;
        }
        return tmp;
    }

Vector Vector::operator*( Vector &r){
        if(dimensions != r.dimensions)
            return 0;
        Vector tmp2(r.dimensions,r.vector);
        int sum = 0;
        for (int i = 0; i <r.dimensions; i++)
        {
           sum+= tmp2.vector[i]*vector[i];
        }
        cout<<"Result is "<<sum<<endl;
        return r;
    }

Vector Vector :: operator- (){
    Vector tmp(*this);
    for (int i = 0; i < dimensions; i++)
    {
        tmp.vector[i] *= -1;
    }
    return tmp;
}
Vector Vector::operator= (const Vector &r){
    int *tmp = new int[this->dimensions];
    for (int i = 0; i < r.dimensions; i++){
        tmp[i] = r.vector[i];
    }
    this->dimensions = r.dimensions;
    this->vector = tmp;
    Vector temp = Vector(dimensions, vector);
    return temp;
}


int main()
{   Vector *array_of_vectors = new Vector[maximum];
    Matrix *array_of_matrices = new Matrix[maximum];
    int f_vect;
    int s_vect;
    int f_mat;
    int s_mat;
    int len=10;
    int* v = new int[len];
    int command = 1;
    int count_vectors;
    int N;
    cout<<"Patched 2.0 "<<endl;
    cout<<"input the number of vectors"<<endl;
    cin>>count_vectors;
    for (int i = 0 ; i < count_vectors; i++ ){
        cout << "Enter the size of the " << i+1 << "'st vector: "<<endl;
        cin>>N;
        for (int j = 0; j < N; j++){
            cout << j+1 << "'st element of array # " << i+1 << " is : ";
            cin >> v[j];
        }
        array_of_vectors[i] = Vector(N, v);
        array_of_vectors[i].print();
        }
    int count_matrices,rows=10,colls=10;
    int **matrix= new int[rows][colls];
    cout<<"input the number of matrices"<<endl;
    cin>>count_matrices;
    for (int i = 0 ; i < count_matrices; i++ ){
        cout << "Enter the number of rows and colls of the  " << i+1 << "'st Matrix: "<<endl;
        cin>>rows>>colls;
        cout<<"Type all the elements of matrix: "<<endl;
        for (int i = 0; i < colls*rows; i++){
            cin>> matrix[i];
        }
        array_of_matrices[i] = Matrix(rows, colls, matrix);
        cout<<"Debug testing";
    }
    array_of_matrices[0].print();
    while (command != 0){

        cout<<"list of commands: "<<endl;
        cout<<"Type 1 to sum vectors"<<endl;
        cout<<"Type 2 to assign vector"<<endl;
        cout<<"Type 3 to subtract vectors"<<endl;
        cout<<"Type 4 to multiply vector and constant"<<endl;
        cout<<"Type 5 to multiply vectors"<<endl;
        cout<<"Type 6 to print all vectors"<<endl;
        cout<<"Type 7 to sum matrices"<<endl;
        cout<<"Type 8 to assign matrices"<<endl;
        cout<<"Type 9 to subtract matrices"<<endl;
        cout<<"Type 10 to multiply matrix and constant"<<endl;
        cout<<"Type 11 to multiply matrix and vector"<<endl;
        cout<<"Type 12 to multiply matrices"<<endl;
        cout<<"Type 13 to print all matrices"<<endl;
        cin>>command;
        switch (command)
        {
        case 1:
            cout<<"Type the number of the first vector: ";
            cin>>f_vect;
            cout<<"Type the number of the second vector: ";
            cin>>s_vect;
            cout<<"The sum of these two vectors is: " ;
            (array_of_vectors[f_vect-1] + array_of_vectors[s_vect-1]).print();
        case 2:
            cout<<"Type the number of the vector to change: ";
            cin>>f_vect;
            cout<<"Type the number of the vector to assign: ";
            cin>>s_vect;
            array_of_vectors[f_vect-1] = array_of_vectors[s_vect-1];
            cout<<"Done! Now the vector with number "<<f_vect<< " equals: "<<endl;
            array_of_vectors[f_vect].print();
        case 3:
            cout<<"Type the number of the first vector: ";
            cin>>f_vect;
            cout<<"Type the number of subtructed vector: ";
            cin>>s_vect;
            cout<<"The subtrabtion equals: " ;
            (array_of_vectors[f_vect-1] - array_of_vectors[s_vect-1]).print();
        case 4:
            int num_c;
            cout<<"Type the number of the vector: ";
            cin>>f_vect;
            cout<<"Type the number to multiply: ";
            cin>>num_c;
            cout<<"The result is: ";
            (array_of_vectors[f_vect-1] * num_c).print();
        case 5:
            cout<<"Type the number of the vector: ";
            cin>>f_vect;
            cout<<"Type the number of the second vector: ";
            cin>>s_vect;
            (array_of_vectors[f_vect-1] * array_of_vectors[s_vect-1]).print();
        case 6:
            for (int j = 0; j < count_vectors; j++){
                cout<< j+1 <<" vector is "<<endl;
                array_of_vectors[j].print();

            }
        case 7:
                cout<<"Type the number of the first matrix: ";
                cin>>f_mat;
                cout<<"Type the number of the second matrix: ";
                cin>>s_mat;
                cout<<"The sum of these two matrices is: " ;
                (array_of_matrices[f_mat-1] + array_of_matrices[s_mat-1]).print();
        case 8:

                cout<<"Type the number of the matrix to change: ";
                cin>>f_mat;
                cout<<"Type the number of the matrix to assign: ";
                cin>>s_mat;
                array_of_matrices[f_mat-1] = array_of_matrices[s_mat-1];
                cout<<"Done! Now the matrix with number "<<f_mat<< " equals: "<<endl;
                array_of_matrices[f_mat].print();
        case 9:
                cout<<"Type the number of the first matrix: ";
                cin>>f_mat;
                cout<<"Type the number of subtructed matrix: ";
                cin>>s_mat;
                cout<<"The subtrabtion equals: " ;
                (array_of_matrices[f_mat-1] + array_of_matrices[s_mat-1]).print();
        case 10:
                int numm_c;
                cout<<"Type the number of the matrix: ";
                cin>>f_mat;
                cout<<"Type the number to multiply: ";
                cin>>num_c;
                cout<<"The result is: ";
                (array_of_matrices[f_mat-1] * numm_c).print();
        case 11:
                cout<<"Type the number of the matrix: ";
                cin>>f_mat;
                cout<<"Type the number of the vector to multiply: ";
                cin>>f_vect;
                (array_of_matrices[f_mat-1] * array_of_vectors[f_vect-1]).print();
        case 12:
                cout<<"Type the number of the matrix: ";
                cin>>f_mat;
                cout<<"Type the number of the second matrix: ";
                cin>>s_mat;
                (array_of_matrices[f_mat-1] * array_of_matrices[s_mat-1]).print();
        case 13:
                for (int j = 0; j < count_matrices; j++){
                    cout<< j+1 <<" matrix is "<<endl;
                    array_of_matrices[j].print();
        }

    }
    }
        return 0;
    }
