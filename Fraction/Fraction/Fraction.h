#pragma once
#include <iostream>

class Fraction
{
public:
	static double half;
	static double third;
	static double fourth;
	static double fifth;

	Fraction();
	Fraction(int num, int denom);
	void Add(Fraction& x, Fraction& y);
	void Subtract(Fraction& x, Fraction& y);
	void Multiply(Fraction& x, Fraction& y);
	void Divide(Fraction& x, Fraction& y);
	bool CompareFractions(Fraction& x, Fraction& y) const;
	void SimplifyFraction();
	inline int& GetNumerator();
	inline int& GetDenominator();

	friend std::ostream& operator<<(std::ostream& consoleOut, const Fraction& number);

private:
	int numerator;
	int denominator;
};

std::ostream& operator<<(std::ostream& consoleOut, const Fraction& number)
{
	consoleOut << number.numerator << "/" << number.denominator << std::endl;
	return consoleOut;
}