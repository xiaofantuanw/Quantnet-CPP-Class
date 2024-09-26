// TestNormal.cpp
// Author: Tengxiao Fan
// 
// (C) Datasim Education BV 2009-2011
// 
// This program tests the exponential distribution and poisson distribution
// This program modifies the example program TestNormalDistribution.cpp

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>



int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;
	double scaleParameter = 0.5;

	exponential_distribution<> myExponential(scaleParameter); // Default type is 'double'
	std::cout << "Mean: " << mean(myExponential) << ", standard deviation: " << standard_deviation(myExponential) << std::endl;

	// Distributional properties
	double x = 3.25;

	std::cout << "pdf: " << pdf(myExponential, x) << std::endl;
	std::cout << "cdf: " << cdf(myExponential, x) << std::endl;

	// Choose another data type and default constructor
	exponential_distribution<float> myExponential2;
	std::cout << "Mean: " << mean(myExponential2) << ", standard deviation: " << standard_deviation(myExponential2) << std::endl;
	
	std::cout << "pdf: " << pdf(myExponential2, x) << std::endl;
	std::cout << "cdf: " << cdf(myExponential2, x) << std::endl;

	// Choose precision
	std::cout.precision(10); // Number of values behind the comma

	// Other properties
	std::cout << "\n***exponential distribution: \n";
	std::cout << "mean: " << mean(myExponential) << std::endl;
	std::cout << "variance: " << variance(myExponential) << std::endl;
	std::cout << "median: " << median(myExponential) << std::endl;
	std::cout << "mode: " << mode(myExponential) << std::endl;
	std::cout << "kurtosis excess: " << kurtosis_excess(myExponential) << std::endl;
	std::cout << "kurtosis: " << kurtosis(myExponential) << std::endl;
	std::cout << "characteristic function: " << chf(myExponential, x) << std::endl;
	std::cout << "hazard: " << hazard(myExponential, x) << std::endl;

	// Poisson distribution
	double meanpara = 3.0; // mean parameter
	poisson_distribution<double> myPoisson(meanpara);

	double val = 13.0;
	std::cout << "\n***poisson distribution: \n";
	std::cout << std::endl << "mean: "<< mean(myPoisson)<<std::endl;
	std::cout <<  "variance: " << variance(myPoisson) << std::endl;
	std::cout<<"pdf: " << pdf(myPoisson, val) << std::endl;
	std::cout << "cdf: " << cdf(myPoisson, val) << std::endl;

	std::vector<double> pdfList;
	std::vector<double> cdfList;

	double start = 0.0;
	double end = 10.0;
	long N = 30;		// Number of subdivisions

	val = 0.0;
	double h = (end - start) / double(N);

	for (long j = 1; j <= N; ++j)
	{
		pdfList.push_back(pdf(myPoisson, val));//Make the pdf vector
		cdfList.push_back(cdf(myPoisson, val));//Make the cdf vector
		val += h;
	}

	//Output the vectors
	for (long j = 0; j < pdfList.size(); ++j)
	{
		std::cout << pdfList[j] << ", ";

	}

	std::cout << "***" << std::endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		std::cout << cdfList[j] << ", ";

	}

	return 0;
}