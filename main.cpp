#include "DynamicMatrix.h"
#include <iostream>

int main()
{
    /*DynamicMatrix dm1(2,3);
    DynamicMatrix dm2(3,4);
    for(int i = 0; i < dm1.getRowCount(); i++)
    {
        for(int j = 0; j < dm1.getColCount(); j++)
        {
            dm1.setElement(i, j, 1);
            std::cout << dm1.getElement(i, j);
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i < dm2.getRowCount(); i++)
    {
        for(int j = 0; j < dm2.getColCount(); j++)
        {
            dm2.setElement(i, j, 3);
            std::cout << dm2.getElement(i, j);
        }
        std::cout << std::endl;
    }
    
    DynamicMatrix dm(2,4);
    dm = dm1 * dm2;
    
    for(int i = 0; i < dm.getRowCount(); i++)
    {
        for(int j = 0; j < dm.getColCount(); j++)
        {
            std::cout << dm.getElement(i, j);
        }
        std::cout << std::endl;
    }
    
    
    DynamicMatrix q(3,3);
    DynamicMatrix qq(3,3);
    
    for(int i = 0; i < q.getRowCount(); i++)
    {
        for(int j = 0; j < q.getColCount(); j++)
        {
            q.setElement(i,j,2);
            qq.setElement(i,j,2);
            std::cout << q.getElement(i,j);
        }
        std::cout << std::endl;
    }
    
    q = q + qq;
    
    for(int i = 0; i < q.getRowCount(); i++)
    {
        for(int j = 0; j < q.getColCount(); j++)
        {
            std::cout << q.getElement(i, j);
            //std::cout << qq.getElement(i, j);
        }
        std::cout << std::endl;
    }*/
    
    DynamicMatrix mvx(3,3);
    for(int i = 0; i < mvx.getRowCount(); i++)
    {
        for(int j = 0; j < mvx.getColCount(); j++)
        {
            mvx.setElement(i,j,i+j);
            std::cout << mvx.getElement(i,j);
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    DynamicMatrix mv1(3,3);
    mv1 = mvx + mvx;
    for(int i = 0; i < mv1.getRowCount(); i++)
    {
        for(int j = 0; j < mv1.getColCount(); j++)
        {
            std::cout << mv1.getElement(i,j);
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    
    DynamicMatrix mv2(std::move(mv1));
    for(int i = 0; i < mv2.getRowCount(); i++)
    {
        for(int j = 0; j < mv2.getColCount(); j++)
        {
            std::cout << mv2.getElement(i,j);
        }
        std::cout << std::endl;
    }

    
}
