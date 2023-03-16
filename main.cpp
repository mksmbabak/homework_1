#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>


using namespace std;


class Complex{

public:

    Complex (float real, float imag){ // constructor for real and imaginary part all together
        real_ = real;
        imag_ = imag;
    }

    Complex (float real){ // constructor for number without imaginary part
        real_ = real;
        imag_ = 0.0;
    }

    Complex (){ // constructor without any argument
        real_ = 0.0;
        imag_ = 0.0;
    }

    float real_p (){  // reading a real part
        return real_;
    }

    float imag_p (){ // reading an imaginary part
        return imag_;
    }

    void mod_real (float real1){ // set a real part
        real_ = real1;
    }

    void mod_imag (float imag1){ // set an imaginary part
        imag_ = imag1;
    }

    void display (){ // display number in a natural way
        cout << real_;
        if (imag_ >= 0){
            cout << " + " << imag_ << "i" << endl;
        }
        else{
            cout << " - " << abs(imag_) << "i" << endl;
        }
    }

    void add_two_num (Complex &c1, Complex &c2){
        real_ = c1.real_ + c2.real_;
        imag_ = c1.imag_ + c2.imag_;
    }

    void add_num (Complex &c){
        real_ += c.real_;
        imag_ += c.imag_;        
    }

private:

    float real_;
    float imag_;
};


int main()
{    
    Complex c1(2.0);
    Complex c2(3.0, 8.25);
    Complex c3;
    Complex c4(10.0, 14.0);
    cout << "Real part" << endl;
    cout << c1.real_p() << endl; // using getter for real part
    cout << "Imaginary part" << endl;
    cout << c1.imag_p() << endl; // using getter for imaginary part
    c1.mod_real(5.0);
    c1.mod_imag(-4.5);
    c1.display();
    c2.display();
    c3.add_two_num(c2, c4);
    c3.display();
    c1.add_num(c2);
    c1.display();
}
