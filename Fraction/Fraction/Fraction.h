#pragma once
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
	void DisplayFraction() const;
	void SimplifyFraction();
	inline int& GetNumerator();
	inline int& GetDenominator();
private:
	int numerator;
	int denominator;
};

