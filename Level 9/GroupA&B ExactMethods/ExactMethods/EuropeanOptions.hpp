/*EuropeanOptions.hpp
* Author: Tengxiao Fan
* This is a header file for the EuropeanOptions class. The class describes the characteristics of European options
*/
#ifndef EuropeanOptions_HPP
#define EuropeanOptions_HPP

#include <string>
#include <vector>

class EuropeanOptions
{
private:
	//Data members, cannot visit by users directly
	double m_T; //expiry time/ maturity
	double m_r; //risk-free interest rate
	double m_sig; //volatility
	double m_S; //Current stock price
	double m_K; //Strike price
	double m_b; //Carry cost
	double m_C; //Call option price
	double m_P; //Put option price

public:
	//Member functions, can be visited by users.
	//
	//Constructors and destructors
	EuropeanOptions();//Default constructor
	EuropeanOptions(double T, double K, double sig, double r, double S,double b);//Constructor with batches
	EuropeanOptions(const EuropeanOptions& source);//Copy constructor
	virtual ~EuropeanOptions();//Destructor

	//Pricing functions for Call option and Put option
	double CallPricing();//Pricing for Call options
	double PutPricing();//Pricing for Put options
	double CallParity();//Calculate the Call option price by parity
	double PutParity();//Calculate the Put option price by parity
	bool CheckParity() const;//Check whether the Put and Call option prices obeys the parity relationship

	//Return the vector of the results, begin from the S of the object
	std::vector<double> CallPricingS(double h, int N) const;
	std::vector<double> PutPricingS(double h, int N) const;
	std::vector<std::vector<double>> PricingMat(int index_change, double h, int N) const;
	//0:T;1:N;2:sig;3:r;4:S;5:b
	//Option Sensitivities, Greek quantity
	double DeltaCall() const;//Delta value of call option
	double DeltaPut() const;//Delta value of put option
	double GammaCall() const;//Gamma value of call option
	double GammaPut() const;//Gamma value of put option
	double difDeltaCall(double h) const;//Delta value of call option, using divided difference
	double difDeltaPut(double h) const;//Delta value of put option, using divided difference
	double difGammaCall(double h) const;//Gamma value of call option, using divided difference
	double difGammaPut(double h) const;//Gamma value of put option, using divided difference

	//These functions return a vector testing a bunch of S values
	std::vector<double> DeltaCallS(double h, int N) const;//Delta value of some call options
	std::vector<double> DeltaPutS(double h, int N) const;//Delta value of some put options
	std::vector<std::vector<double>> SensitiveMat(int index_change, double h, int N) const;//This matrix gives the value of some Greek quantities

	//Functions just for getting and setting the values of the data member
	//Inline for simplicity
	double T() const{ return m_T; } 
	void T(double t) { m_T = t; }
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