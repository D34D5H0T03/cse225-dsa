#include <iostream>
#include "dimVector.h"

DimVector::DimVector(double i, double j, double k):
     i(i), j(j), k(k) {}

DimVector::~DimVector(){}

DimVector::DimVector(){
     this->i = 0;
     this->j = 0;
     this->k = 0;
}

DimVector::DimVector(const DimVector& a){
     this->i = a.i;
     this->j = a.j;
     this->k = a.k;
}

double DimVector::getI(){
     return this->i;
}

double DimVector::getJ(){
     return this->j;
}

double DimVector::getK(){
     return this->k;
}

void DimVector::setI(double i){
     this->i = i;
}

void DimVector::setJ(double j){
     this->j = j;
}

void DimVector::setK(double k){
     this->k = k;
}

DimVector DimVector::operator+(const DimVector& a) const{
     return DimVector(this->i + a.i, this->j + a.j, this->k + a.k);
}

DimVector DimVector::operator-(const DimVector& a) const{
     return DimVector(this->i - a.i, this->j - a.j, this->k - a.k);
}


