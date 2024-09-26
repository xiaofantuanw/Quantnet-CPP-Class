/*AmericanOptions.cpp
* Author: Tengxiao Fan
* This is a source file for the AmericanOptions class. The class describes the characteristics of American options
*/
#include "AmericanOptions.hpp"
#include <cmath>
#include <iostream>

AmericanOptions::AmericanOptions()
{
	//Default constructor, give the members some value
	m_K = 100;
	m_sig = 0.1;
	m_r = 0.1;
	m_b = 0.02;
	m_S = 110;
	m_C = 0;
	m_P = 0;//C and P uncalculated yet
}

AmericanOptions::AmericanOptions(double K, double sig, double r, double S, double b)
{
	//Initialized constructor
	m_K = K;
	m_sig = sig;
	m_r = r;
	m_b = b;
	m_S = S;
	m_C = 0;
	m_P = 0;//C and P uncalculated yet
}

AmericanOptions::AmericanOptions(const AmericanOptions& source)
{
	//Copy constructor
	m_K = source.m_K;
	m_sig = source.m_sig;
	m_r = source.m_r;
	m_b = source.m_b;
	m_S = source.m_S;
	m_C = source.m_C;
	m_P = source.m_P;
}

AmericanOptions::~AmericanOptions()//Destructor
{

}

double AmericanOptions::CallPricing()//Call option pricing function
{
	double y1 = 1. / 2 - m_b / m_sig / m_sig + sqrt(pow((m_b / m_sig / m_sig - 1. / 2), 2) + 2 * m_r / m_sig / m_sig);
	m_C = m_K / (y1 - 1) * pow(((y1 - 1) / y1 * m_S / m_K), y1);
	return m_C;
}

double AmericanOptions::PutPricing()//Put option pricing function
{
	double y2 = 1. / 2 - m_b / m_sig / m_sig - sqrt(pow((m_b / m_sig / m_sig - 1. / 2), 2) + 2 * m_r / m_sig / m_sig);
	m_P = m_K / (1 - y2) * pow(((y2 - 1) / y2 * m_S / m_K), y2);
	return m_P;
}

std::vector<double> AmericanOptions::CallPricingS(double h, int N) const
//Call option pricing function for a vector of S values
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i++)
	{
		double S = m_S + i * h;
		result[i] = AmericanOptions(m_K, m_sig, m_r, S, m_b).CallPricing();
	}
	return result;
}

std::vector<double> AmericanOptions::PutPricingS(double h, int N) const
//Put option pricing function for a vector of S values
{
	std::vector<double> result(N);
	for (int i = 0; i < N;i++)
	{
		double S = m_S + i * h;
		result[i] = AmericanOptions(m_K, m_sig, m_r, S, m_b).PutPricing();
	}
	return result;
}

std::vector<std::vector<double>> AmericanOptions::PricingMat(int index_change, double h, int N) const
{
	//This is a pricing matrix for American Options.
	//The parameter with index on index_change will change, other parameters will remain unchanged.
	std::vector<std::vector<double>> result;
	std::vector<double> sample{ m_K,m_sig,m_r,m_S,m_b };
	double begin = sample[index_change];
	for (int i = 0;i < N;i++)
	{
		std::vector<double> temp{ m_K,m_sig,m_r,m_S,m_b };
		temp[index_change] = begin + i * h;
		temp.push_back(AmericanOptions(temp[0], temp[1], temp[2], temp[3], temp[4]).CallPricing());
		temp.push_back(AmericanOptions(temp[0], temp[1], temp[2], temp[3], temp[4]).PutPricing());
		result.push_back(temp);
	}
	return result;
}