//------------------------------
//  DO NOT MODIFY THIS FILE
//------------------------------
#include "catch.hpp"
#include "binomial.h"
//------------------------------
 class Binomial {
double coefft1, coefft2;
int power1, power2;
public:
Binomial(double c1 = 1.0, double c2 = 1.0, int p1 = 1, int p2 = 1);
double GetCoefficient (int idx) const;
int GetPower(int idx) const;
int SetPower (int idx, int pwr);
int Add (const Binomial other);
void Multiply (double f);
void Multiply (double coefft, int pwr);
};

Binomial::Binomial (double c1, double c2, int p1, int p2) {
coefft1 = c1; coefft2 = c2;
if (p1 < 1) p1 = 1;
if (p2 < 1) p2 = 1;
power1 = p1; power2 = p2;
};

double Binomial::GetCoefficient (int idx) const {
if (idx == 1) return coefft1;
else if (idx == 2) return coefft2;
else return -1;
};

int Binomial::GetPower(int idx) 
const {
if (idx == 1) return power1;
else if (idx == 2) return power2;
else return -1;
};

int Binomial::SetPower (int idx, int pwr) {
if (pwr <= 0) pwr = 1;
if (idx == 1) power1 = pwr;
else if (idx == 2) power2 = pwr;
else return -1;
return 0;
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "b1" ) {
        Binomial b;
        REQUIRE( b.GetCoefficient(1) == 1.0 );
        REQUIRE( b.GetCoefficient(2) == 1.0 );
        REQUIRE( b.GetCoefficient(3) == -1.0 );
    }
    SECTION( "b2" ) {
        Binomial b;
        REQUIRE( b.GetPower(1) == 1 );
        REQUIRE( b.GetPower(2) == 1 );
        REQUIRE( b.GetPower(3) == -1 );
    }
    SECTION( "b3" ) {
        Binomial b{2.0,2};
        REQUIRE( b.GetCoefficient(1) == 2.0 );
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetCoefficient(2) == 1.0 );
        REQUIRE( b.GetPower(2) == 1 );
    }
    SECTION( "b4" ) {
        Binomial b{2.0,2,5.0};
        REQUIRE( b.GetCoefficient(1) == 2.0 );
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetCoefficient(2) == 5.0 );
        REQUIRE( b.GetPower(2) == 1 );
    }
    SECTION( "b5" ) {
        Binomial b{2.0,2,5.0,4};
        REQUIRE( b.GetCoefficient(1) == 2.0 );
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetCoefficient(2) == 5.0 );
        REQUIRE( b.GetPower(2) == 4 );
    }
    SECTION( "b6" ) {
        Binomial b{2.0,-2,5.0,-4};
        REQUIRE( b.GetCoefficient(1) == 2.0 );
        REQUIRE( b.GetPower(1) == 1 );
        REQUIRE( b.GetCoefficient(2) == 5.0 );
        REQUIRE( b.GetPower(2) == 1 );
    }
    SECTION( "b7" ) {
        Binomial b{2.0,2};
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetPower(2) == 1 );
        REQUIRE( b.SetPower(2,2) == 0 );
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetPower(2) == 2 );
    }
    SECTION( "b8" ) {
        Binomial b{2.0,2};
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.GetPower(2) == 1 );
        REQUIRE( b.SetPower(1,-2) == 0 );
        REQUIRE( b.GetPower(1) == 1 );
        REQUIRE( b.GetPower(2) == 1 );
    }
    SECTION( "b9" ) {
        Binomial b{2.0,2};
        REQUIRE( b.GetPower(1) == 2 );
        REQUIRE( b.SetPower(4,-2) == -1 );
        REQUIRE( b.GetPower(1) == 2 );
    }
    SECTION( "b10" ) {
        Binomial b1{2.0,2};
        Binomial b2{2.0,3};
        REQUIRE( b1.Add(b2) == -1 );
        REQUIRE( b1.GetPower(1) == 2 );
        REQUIRE( b1.GetCoefficient(1) == 2.0 );
        REQUIRE( b1.GetPower(2) == 1 );
        REQUIRE( b1.GetCoefficient(2) == 1.0 );
    }
    SECTION( "b11" ) {
        Binomial b1{2.0,2,4.0};
        Binomial b2{2.0,2,7.0};
        REQUIRE( b1.Add(b2) == 0 );
        REQUIRE( b1.GetPower(1) == 2 );
        REQUIRE( b1.GetCoefficient(1) == 4.0 );
        REQUIRE( b1.GetPower(2) == 1 );
        REQUIRE( b1.GetCoefficient(2) == 11.0 );
    }
    SECTION( "b12" ) {
        Binomial b1{2.0,2};
        Binomial b2{2.0,2};
        REQUIRE( b1.Add(b2) == 0 );
        REQUIRE( b1.GetPower(1) == 2 );
        REQUIRE( b1.GetCoefficient(1) == 4.0 );
        REQUIRE( b1.GetPower(2) == 1 );
        REQUIRE( b1.GetCoefficient(2) == 2.0 );
    }
    SECTION( "b13" ) {
        Binomial b{4.0,3};
        b.Multiply(4.0);
        REQUIRE( b.GetPower(1) == 3 );
        REQUIRE( b.GetCoefficient(1) == 16.0 );
        REQUIRE( b.GetCoefficient(2) == 4.0 );
    }
    SECTION( "b14" ) {
        Binomial b{4.0};
        b.Multiply(-3.0);
        REQUIRE( b.GetPower(1) == 1 );
        REQUIRE( b.GetCoefficient(1) == -12.0 );
        REQUIRE( b.GetCoefficient(2) == -3.0 );
    }
    SECTION( "b15" ) {
        Binomial b{1.0, 2, 3.0, 4};
        b.Multiply(2.0, 3);
        REQUIRE( b.GetCoefficient(1) == 2.0 );
        REQUIRE( b.GetPower(1) == 5 );
        REQUIRE( b.GetCoefficient(2) == 6.0 );
        REQUIRE( b.GetPower(2) == 7 );
    }
    SECTION( "b16" ) {
        Binomial b;
        b.Multiply(-3.0, 5);
        REQUIRE( b.GetCoefficient(1) == -3.0 );
        REQUIRE( b.GetPower(1) == 6 );
        REQUIRE( b.GetCoefficient(2) == -3.0 );
        REQUIRE( b.GetPower(2) == 6 );
    }
}
//------------------------------
