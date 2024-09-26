#include "EuropeanOptions.hpp"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions
#include <cmath>
#include <iostream>

EuropeanOptions::EuropeanOptions()
{
	//Default constructor, give it the value of Batch 1.
	m_T = 0.25;
	m_K = 65;
	m_sig = 0.30;
	m_r = 0.08;
	m_S = 60;
	m_b = m_r;//In our initialization, b = r
	m_C = 0;
	m_P = 0;//Value of C and P are not calculated
}

EuropeanOptions::EuropeanOptions(double T, double K, double sig, double r, double S,double b)
{
	//constructor with initialization
	m_T = T;
	m_K = K;
	m_sig = sig;
	m_r = r;
	m_S = S;
	m_b = b;
	m_C = 0;
	m_P = 0;//Value of C and P are not calculated
}

EuropeanOptions::EuropeanOptions(const EuropeanOptions& source)
{
	//Copy constructor
	m_T = source.m_T;
	m_K = source.m_K;
	m_sig = source.m_sig;
	m_r = source.m_r;
	m_S = source.m_S;
	m_b = source.m_b;
	m_C = source.m_C;
	m_P = source.m_P;
}

EuropeanOptions::~EuropeanOptions()//Destructor
{

}

double EuropeanOptions::CallPricing()//Call option pricing function
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	//Calculate the call value by the function
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double d2 = d1 - m_sig * sqrt(m_T);
	m_C = m_S * exp((m_b - m_r) * m_T) * cdf(StdNormal, d1) - m_K * exp(-m_r * m_T) * cdf(StdNormal, d2);
	return m_C;//return the result
}

double EuropeanOptions::PutPricing()//Put option pricing function
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	//Calculate the call value by the function
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double d2 = d1 - m_sig * sqrt(m_T);
	m_P = -m_S * exp((m_b - m_r) * m_T) * cdf(StdNormal, -d1) + m_K * exp(-m_r * m_T) * cdf(StdNormal, -d2);
	return m_P;//return the result
}

double EuropeanOptions::CallParity()//Calculate the Call option price by parity
{
	m_C = m_P + m_S - m_K * exp(-m_r * m_T);//Calculate by parity function
	return m_C;
}

double EuropeanOptions::PutParity()//Calculate the Call option price by parity
{
	m_P = m_C - m_S + m_K * exp(-m_r * m_T);//Calculate by parity function
	return m_P;
}

bool EuropeanOptions::CheckParity() const//Check whether the option prices satisfies the parity condition
{
	return (m_P + m_S == m_C + m_K * exp(-m_r * m_T));
}

std::vector<double> EuropeanOptions::CallPricingS(double h, int N) const
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i ++)
	{
		double S =m_S + i * h;
		result[i] = EuropeanOptions(m_T, m_K, m_sig, m_r, S, m_b).CallPricing();
	}
	return result;
}

std::vector<double> EuropeanOptions::PutPricingS(double h, int N) const
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i++)
	{
		double S = m_S + i * h;
		result[i] = EuropeanOptions(m_T, m_K, m_sig, m_r, S, m_b).PutPricing();
	}
	return result;
}

std::vector<std::vector<double>> EuropeanOptions::PricingMat(int index_change, double h, int N) const
{
	std::vector<std::vector<double>> result;
	std::vector<double> sample{m_T,m_K,m_sig,m_r,m_S,m_b};
	double begin = sample[index_change];
	for (int i = 0;i < N;i++)
	{
		std::vector<double> temp{ m_T,m_K,m_sig,m_r,m_S,m_b };
		temp[index_change] = begin + i * h;
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4],temp[5]).CallPricing());
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4],temp[5]).PutPricing());
		result.push_back(temp);
	}
	return result;
}



double EuropeanOptions::DeltaCall() const
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double result = exp((m_b - m_r) * m_T) * cdf(StdNormal, d1);
	return result;
}

double EuropeanOptions::DeltaPut() const
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double result = -exp((m_b - m_r) * m_T) * cdf(StdNormal, -d1);
	return result;
}

double EuropeanOptions::GammaCall() const
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double result = pdf(StdNormal, d1) * exp((m_b - m_r) * m_T) / m_S / tmp;
	return result;
}

double EuropeanOptions::GammaPut() const
{
	using namespace boost::math;
	normal_distribution<> StdNormal; // Standard normal
	double tmp = m_sig * sqrt(m_T);
	double d1 = (log(m_S / m_K) + (m_b + m_sig * m_sig / 2) * m_T) / tmp;
	double result = pdf(StdNormal, -d1) * exp((m_b - m_r) * m_T) / m_S / tmp;
	return result;
}

std::vector<double> EuropeanOptions::DeltaCallS(double h, int N) const
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i++)
	{
		double S = m_S + i * h;
		result[i] = EuropeanOptions(m_T, m_K, m_sig, m_r, S, m_b).DeltaCall();
	}
	return result;
}

std::vector<double> EuropeanOptions::DeltaPutS(double h, int N) const
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i++)
	{
		double S = m_S + i * h;
		result[i] = EuropeanOptions(m_T, m_K, m_sig, m_r, S, m_b).DeltaPut();
	}
	return result;
}

std::vector<std::vector<double>> EuropeanOptions::SensitiveMat(int index_change, double h, int N) const
{
	std::vector<std::vector<double>> result;
	std::vector<double> sample{ m_T,m_K,m_sig,m_r,m_S,m_b };
	double begin = sample[index_change];
	for (int i = 0;i < N;i++)
	{
		std::vector<double> temp{ m_T,m_K,m_sig,m_r,m_S,m_b };
		temp[index_change] = begin + i * h;
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]).DeltaCall());
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]).DeltaPut());
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]).GammaCall());
		temp.push_back(EuropeanOptions(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]).GammaPut());
		result.push_back(temp);
	}
	return result;
}

double EuropeanOptions::difDeltaCall(double h) const
{
	double dif = EuropeanOptions(m_T, m_K, m_sig, m_r, m_S + h, m_b).CallPricing() - EuropeanOptions(m_T, m_K, m_sig, m_r, m_S - h, m_b).CallPricing();
	return dif / 2 / h;
}

double EuropeanOptions::difDeltaPut(double h) const
{
	double dif = EuropeanOptions(m_T, m_K, m_sig, m_r, m_S + h, m_b).PutPricing() - EuropeanOptions(m_T, m_K, m_sig, m_r, m_S - h, m_b).PutPricing();
	return dif / 2 / h;
}

double EuropeanOptions::difGammaCall(double h) const
{
	double dif= EuropeanOptions(m_T, m_K, m_sig, m_r, m_S + h, m_b).CallPricing() + EuropeanOptions(m_T, m_K, m_sig, m_r, m_S - h, m_b).CallPricing()
		-2*EuropeanOptions(m_T, m_K, m_sig, m_r, m_S, m_b).CallPricing();
	return dif / h / h;
}

double EuropeanOptions::difGammaPut(double h) const
{
	double dif = EuropeanOptions(m_T, m_K, m_sig, m_r, m_S + h, m_b).PutPricing() + EuropeanOptions(m_T, m_K, m_sig, m_r, m_S - h, m_b).PutPricing()
		- 2 * EuropeanOptions(m_T, m_K, m_sig, m_r, m_S, m_b).PutPricing();
	return dif / h / h;
}