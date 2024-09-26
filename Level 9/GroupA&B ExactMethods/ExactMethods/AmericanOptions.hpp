/*AmericanOptions.hpp
* Author: Tengxiao Fan
* This is a header file for the AmericanOptions class. The class describes the characteristics of American options
*/
#ifndef AmericanOptions_HPP
#define AmericanOptions_HPP
#include <vector>


class AmericanOptions
{
private:
	//Data members, cannot visit by users directly
	double m_r; //risk-free interest rate
	double m_sig; //volatility
	double m_S; //Current stock price
	double m_K; //Strike price
	double m_b; //Carry cost
	double m_C; //Call option price
	double m_P; //Put option price
public:
	//Member functions, available to users
	//
	//Constructors and Destructors
	AmericanOptions();//Default constructor
	AmericanOptions(double K, double sig, double r, double S, double b);//Initialized constructor
	AmericanOptions(const AmericanOptions& source);;//Copy constructor
	virtual ~AmericanOptions();//Destructor

	//Pricing functions for Call option and Put option
	double CallPricing();//Pricing for Call options
	double PutPricing();//Pricing for Put options

	//Return the vector of the results, begin from the S of the object
	std::vector<double> CallPricingS(double h, int N) const;
	std::vector<double> PutPricingS(double h, int N) const;
	std::vector<std::vector<double>> PricingMat(int index_change, double h, int N) const;

	//Functions just for getting and setting the values of the data member
	//Inline for simplicity
	double K() const { return m_K; }
	void K(double k) { m_K = k; }
	double sig() const { return m_sig; }
	void sig(double sg) { m_sig = sg; }
	double r() const { return m_r; }
	void r(double R) { m_r = R; }
	double S() const { return m_S; }
	void S(double s) { m_S = s; }
	double b() const { return m_b; }
	void b(double B) { m_b = B; }
	double C() const { return m_C; }
	void C(double c) { m_C = c; }
	double P() const { return m_P; }
	void P(double p) { m_P = p; }
};

#endif
