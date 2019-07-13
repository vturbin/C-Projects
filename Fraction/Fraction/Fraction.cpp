#include "Fraction.h"
#include <iostream>

using namespace std;


Fraction::Fraction() :Fraction(0,1) {
}

Fraction::Fraction(int num, int denom): numerator(num), denominator(denom) {
	SimplifyFraction();
}



void Fraction::Add(Fraction& x, Fraction& y)
{
	
	if (x.denominator != y.denominator)
	{
		denominator = x.denominator * y.denominator;
		numerator = x.numerator * (denominator / x.denominator)
			+ y.numerator * (denominator / y.denominator);
	}
	else {
		denominator = x.denominator;
		numerator = x.numerator + y.numerator;
	}
	SimplifyFraction();
}

void Fraction::Subtract(Fraction& x, Fraction& y)
{
	if (x.denominator != y.denominator)
	{
		denominator = x.denominator * y.denominator;
		numerator = x.numerator * (denominator / x.denominator)
			- y.numerator * (denominator / y.denominator);
	}
	else {
		denominator = x.denominator;
		numerator = x.numerator - y.numerator;
	}
	SimplifyFraction();
}

void Fraction::Multiply(Fraction& x, Fraction& y)
{
	numerator = x.numerator * y.numerator;
	denominator = x.denominator * y.denominator;
	SimplifyFraction();
}

void Fraction::Divide(Fraction& x, Fraction& y)
{
	numerator = x.numerator * y.denominator;
	denominator = x.denominator * y.numerator;
	SimplifyFraction();
}

void Fraction::SimplifyFraction()
{
	while (numerator % 2 == 0 && denominator % 2 == 0)
	{
		numerator = numerator / 2;
		denominator = denominator / 2;
	}
}

bool Fraction::CompareFractions(Fraction& x, Fraction& y) const
{
	if (x.numerator == y.numerator && x.denominator == y.denominator)
	{
		return true;
	 }
	return false;
}

Fraction Fraction::operator-(const Fraction& fraction) const
{
	Fraction newFraction;
	if (denominator != fraction.denominator)
	{
		newFraction.denominator = denominator * fraction.denominator;
		newFraction.numerator = numerator * (newFraction.denominator / denominator)
			- fraction.numerator * (newFraction.denominator / fraction.denominator);
	}
	else {
		newFraction.denominator = denominator;
		newFraction.numerator = numerator - fraction.numerator;
	}
	newFraction.SimplifyFraction();
	return newFraction;
}

Fraction Fraction::operator+(const Fraction& fraction) const
{
	Fraction newFraction;
	if (denominator != fraction.denominator)
	{
		newFraction.denominator = denominator * fraction.denominator;
		newFraction.numerator = numerator * (newFraction.denominator / denominator)
			+ fraction.numerator * (newFraction.denominator / fraction.denominator);
	}
	else {
		newFraction.denominator = denominator;
		newFraction.numerator = numerator + fraction.numerator;
	}
	newFraction.SimplifyFraction();
	return newFraction;
}

Fraction Fraction::operator*(const Fraction& fraction) const
{
	Fraction newFraction(numerator * fraction.numerator, denominator * fraction.denominator);
	newFraction.SimplifyFraction();
	return newFraction;
}

Fraction Fraction::operator/(const Fraction& fraction) const
{
	Fraction newFraction(numerator * fraction.denominator, denominator * fraction.numerator);
	newFraction.SimplifyFraction();
	return newFraction;
}

bool Fraction::operator==(const Fraction& fraction) const
{
	return(this->numerator == fraction.numerator && this->denominator == fraction.denominator);
}

bool Fraction::operator!=(const Fraction& fraction) const
{
	return !(*this == fraction);
}

double Fraction::fourth = 0.25;
double Fraction::half = 0.5;
double Fraction::third = 0.33;
double Fraction::fifth = 0.2;

inline int& Fraction::GetNumerator()
{
	return numerator;
}

inline int& Fraction::GetDenominator()
{
	return denominator;
}


int main()
{
	Fraction sum;
	Fraction subtract;

	Fraction number2(2, 4);
	Fraction number3(4, 24);
	sum.Add(number2, number3);
	
	subtract.Subtract(number2, number3);
	cout << "here comes the fraction sum: " << sum << endl;

	cout << "here comes the fraction subtraction: " << subtract << endl;
	// fractions using operator overloading
	Fraction newFractionSum = number2 + number3;
	cout << "This is sum from operator overloading: " << newFractionSum << endl;
	Fraction newFractionSubtract = number2 - number3;
	cout << "This is subtraction from operator overloading: " << newFractionSubtract << endl;
	Fraction newFractionMultiple = number2 * number3;
	cout << "This is multiplication from operator overloading: " << newFractionMultiple << endl;
	Fraction newFractionDivide = number2 / number3;
	cout << "This is division from operator overloading: " << newFractionDivide << endl;

	//static data member
	cout << sum.fifth << endl;

	// inline functions
	cout << sum.GetNumerator() << endl;
	cout << sum.GetDenominator() << endl;
}