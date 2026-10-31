#ifndef DIMVECTOR_H_INCLUDED
#define DIMVECTOR_H_INCLUDED

class DimVector{
    private:
        double i;
        double j;
        double k;

    public:
        // constructors and destructors
        DimVector(double i, double j, double k);
        DimVector();
        DimVector(const DimVector& a);
        ~DimVector();

        // getters and setters
        double getI();
        double getJ();
        double getK();
        void setI(double i);
        void setJ(double j);
        void setK(double k);

        //vector mathematics via operator
        DimVector operator+(const DimVector& a) const;
        DimVector operator-(const DimVector& a) const; 

        //vector mathematics
        DimVector scaleVector(double scalar); //scalar multiplication
        double dotProduct(const DimVector& a); //dot product
        DimVector crossProduct(const DimVector& a); //cross product
        double magnitude(); //magnitude
        DimVector direction(); // direction

};


#include "dimVector.cpp"
#endif