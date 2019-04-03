#ifndef DYNAMICMATRIX_H
#define DYNAMICMATRIX_H
#include <cstdio>

class DynamicMatrix
{
private:
    std::size_t rows;
    std::size_t cols;
    int** matrix;
    int size;
    
public:
    DynamicMatrix();
    DynamicMatrix(std::size_t, std::size_t);
    DynamicMatrix(const DynamicMatrix &source);
    DynamicMatrix(DynamicMatrix&&);
    ~DynamicMatrix();
    
    int getRowCount() const;
    int getColCount() const;
    
    int getElement(std::size_t, std::size_t) const;
    void setElement(std::size_t, std::size_t, int);
    
    DynamicMatrix& operator =(const DynamicMatrix &source);
    DynamicMatrix& operator =(DynamicMatrix &&source);
    DynamicMatrix operator +(const DynamicMatrix &source) const;
    DynamicMatrix operator *(const DynamicMatrix &source) const;
};

#endif
