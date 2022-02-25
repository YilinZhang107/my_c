#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
        double real;
        double imaginary;
    public:
        Complex(double r=0, double ima=0){
            real = r;
            imaginary = ima;
        }
        Complex operator+(Complex &c){
            Complex t;
            t.real = real+c.real;
            t.imaginary = imaginary + c.imaginary;
            return t;
        }
        Complex operator-(Complex &c){
            Complex t;
            t.real = real-c.real;
            t.imaginary = imaginary - c.imaginary;
            return t;
        }
        Complex operator*(Complex &c){
            Complex t;
            t.real = real*c.real - imaginary*c.imaginary;
            t.imaginary = imaginary*c.real + real*c.imaginary;
            return t;
        }
        Complex operator/(Complex &c){
            Complex t;
            double cd = c.real*c.real+c.imaginary*c.imaginary;
            t.real = (real*c.real + imaginary*c.imaginary)/cd;
            t.imaginary = (imaginary*c.real - real*c.imaginary)/cd;
            return t;
        }
        friend ostream & operator<<(ostream &os, Complex &c){
            if(c.imaginary>=0)
                os<<c.real<<'+'<<c.imaginary<<'i';
            else
                os<<c.real<<c.imaginary<<'i';
            return os;
        }
};

int main(){
    Complex *a = new Complex(10,10);
    Complex *b = new Complex(-5,-15);

    Complex *c = new Complex;
    *c = *a + *b;
    cout<<*c<<endl;
    *c = *a - *b;
    cout<<*c<<endl;
    *c = *a * *b;
    cout<<*c<<endl;
    *c = *a / *b;
    cout<<*c<<endl;


    delete a,b,c;
    return 0;
}