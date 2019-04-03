#include "DynamicMatrix.h"
#include <iostream>

DynamicMatrix::DynamicMatrix (std::size_t rows, std::size_t cols) : rows(rows), cols(cols)
{
    this->size = rows * cols;
    this->matrix = new int*[rows];
    
    for(int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix &source)
{
    this->rows = source.rows;
    this->cols = source.cols;
    
    this->size = source.size;
    this->matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        this->matrix[i] = new int[cols];
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            this->matrix[i][j] = source.matrix[i][j];
        }
    }
}

DynamicMatrix::DynamicMatrix(DynamicMatrix &&source) : rows(source.rows), cols(source.cols), size(source.size), matrix(source.matrix)
{
    source.rows = 0;
    source.cols = 0;
    source.size = 0;
    source.matrix = nullptr;
}

DynamicMatrix::~DynamicMatrix()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
    
int DynamicMatrix::getRowCount() const
{
    return this->rows;
}

int DynamicMatrix::getColCount() const
{
    return this->cols;
}
    
int DynamicMatrix::getElement(std::size_t r, std::size_t c) const
{
    return this->matrix[r][c];
}

void DynamicMatrix::setElement(std::size_t r, std::size_t c, int element)
{
    matrix[r][c] = element;
}

DynamicMatrix& DynamicMatrix::operator =(const DynamicMatrix &source)
{
    if(this != &source)
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        this->rows = source.rows;
        this->cols = source.cols;
        this->size = source.size;
        this->matrix = new int*[rows];
        
        for(int i = 0; i < rows; i++)
        {
            this->matrix[i] = new int[cols];
        }
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                this->matrix[i][j] = source.matrix[i][j];
            }
        }
    }
    return *this;
}

DynamicMatrix& DynamicMatrix::operator=(DynamicMatrix &&source)
{
    if(this != &source)
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
        
        this->rows = source.rows;
        this->cols = source.cols;
        this->size = source.size;
        this->matrix = source.matrix;
        
        source.rows = 0;
        source.cols = 0;
        source.size = 0;
        source.matrix = nullptr;
    }
    
    return *this;
}

DynamicMatrix DynamicMatrix::operator +(const DynamicMatrix &source) const
//const nie zmienia skladowych klasy na ktorych jest wywolwana
{
    int newcols = source.cols;
    int newrows = this->rows;
    DynamicMatrix dm(newrows, newcols);
    
    if((this->rows == source.rows)&&(this->cols == source.cols))
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                dm.matrix[i][j] = this->matrix[i][j] + source.matrix[i][j];
            }
        }
    }
    return dm;
}

DynamicMatrix DynamicMatrix::operator *(const DynamicMatrix &source) const 
{
    int tmp;
    int newcols = source.cols;
    int newrows = this->rows;
    
    DynamicMatrix dm(newrows, newcols);
    
    if(this->cols == source.rows)
    {
        for(int i = 0; i < dm.getRowCount(); i++)
        {
            for(int j = 0; j < dm.getColCount(); j++)
            {
                //std::cout << this->matrix[i][j];
                //std::cout << source.matrix[i][j];
                
                tmp = 0;
                dm.setElement(i, j, tmp);
                
                for(int k = 0; k < cols; k++)
                {
                    tmp += (this->matrix[i][k] * source.matrix[k][j]);
                }
                
                dm.setElement(i, j, tmp);
                std::cout << dm.getElement(i, j);
            }
            std::cout << std::endl;
        }
    }
    
    else
    {
        std::cout << "Nie mozna pomnozyc tych macierzy." << std::endl;
    }
    return dm;
}
















