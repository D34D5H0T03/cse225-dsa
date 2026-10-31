#include <iostream>

class ComplexNumber{
    private:
        double real;
        double imaginary;
    public:
        ComplexNumber(double real, double imaginary):
            real(real), imaginary(imaginary) {}
        
        ComplexNumber():
            real(0), imaginary(0) {}

        ~ComplexNumber(){
           
        }

        void setReal(double real){
            this->real = real;
        }
        void setImaginary(double imaginary){
            this->imaginary = imaginary;
        }
        double getReal(){
            return this->real;
        }
        double getImaginary(){
            return this->imaginary;
        }

        ComplexNumber static addNumbers(ComplexNumber addend, ComplexNumber augend){
            ComplexNumber result;

            result.setReal(addend.getReal() + augend.getReal());
            result.setImaginary(addend.getImaginary() + augend.getImaginary());

            return result;
        }

        void printInfo(){
            std::cout << "Complex Number: " << this->getReal() << " + " 
            << this->getImaginary() << "i" << std::endl; 
        }
};

int main(){
    ComplexNumber* n1 = new ComplexNumber(4, 5);
    ComplexNumber* n2 = new ComplexNumber(2, 3);

    ComplexNumber add = ComplexNumber::addNumbers(*n1, *n2);
    add.printInfo();
    return 0;
}