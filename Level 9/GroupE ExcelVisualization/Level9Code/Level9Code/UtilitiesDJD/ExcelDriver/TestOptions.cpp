// TestOptions.cpp
//
// This file is used to display the result of option pricing
//
// (C) Datasim Education BV 2005-2017
//


#include "EuropeanOptions.hpp"

#include "ExcelDriverLite.hpp"
#include "Utilities.hpp"

#include <cmath>
#include <list>
#include <string>
#include <vector>
#include <iostream>

int main()
{
	// DON'T FORGET TO MODIFY EXCELIMPORTS.CPP for correct version of Excel.

	long N = 40;


	// Create abscissa x array
	double start = 60.0, end = 70.0;
	double T = 0.25, K = 65, sig = 0.3, r = 0.08, b = 0.08;

	auto x = CreateMesh(N, start, end);

	auto fun = [&](double x) { return EuropeanOptions(T,K,sig,r,x,b).CallPricing(); };
	auto fun2 = [&](double x) { return EuropeanOptions(T, K, sig, r, x, b).PutPricing(); };
	auto vec1 = CreateDiscreteFunction< std::vector<double>>(x, fun);
	auto vec2 = CreateDiscreteFunction< std::vector<double>>(x, fun2);

	ExcelDriver xl; xl.MakeVisible(true);
	xl.CreateChart(x, vec1, "Call Option");
	xl.CreateChart(x, vec2, "Put Option");

	// C++11 style initializer lists
	// std::list<std::string> labels{ "x^2", "x^3" };
	std::list<std::string> labels;
	labels.push_back("Call Option");
	labels.push_back("Put Option");

	// C++11 style initializer lists
	// std::list<std::vector<double>> curves{ vec1, vec2 };
	std::list<std::vector<double>> curves;
	curves.push_back(vec1);
	curves.push_back(vec2);

	xl.CreateChart(x, labels, curves, "Call option and Put option", "H", "V");

	return 0;
}