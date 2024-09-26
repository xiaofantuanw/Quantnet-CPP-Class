/*TestExact.cpp
* Author: Tengxiao Fan
* This is the test program for exact methods of European and American Options
*/
#include "EuropeanOptions.hpp"
#include "AmericanOptions.hpp"
#include <iostream>
#include <iomanip>

void prtMat(std::vector<std::vector<double>> Mat, int N, int factor)
//This function prints the matrix
{
	//std::cout << "T\tK\tsig\tr\tS\tb\tC\tP\t";
	std::cout << std::setprecision(4) << std::endl;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < factor;j++)
		{
			std::cout << Mat[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::setprecision(6) << std::endl;
}

std::vector<double> MakeMesh(double begin, double h, int N)//This function makes a mesh
{
	std::vector<double> result;
	for (int i = 0;i < N;i++)
	{
		result.push_back(begin + i * h);//push the num into the vec
	}
	return result;
}

int main()
{
	std::cout << "***European options***" << std::endl;
	//Create the European option batches
	EuropeanOptions batch1(1.45,120,0.51,0.045,108,0);
	EuropeanOptions batch2(1, 100, 0.2, 0, 100,0);
	EuropeanOptions batch3(1, 10, 0.5, 0.12, 5,0.12);
	EuropeanOptions batch4(30, 100, 0.3, 0.08, 100,0.08);
	//Calculate the Call and put prices
	//Use parity function to calculate again
	//Check whether the call and put prices matches

	//Test of batch 1
	std::cout << "Batch 1:" << std::endl << "Call: " << batch1.CallPricing() << std::endl;
	std::cout<< "Put: " << batch1.PutPricing()<<std::endl;
	std::cout << "Call calculated by parity: " << batch1.CallParity() << std::endl;
	std::cout << "Put calculated by parity: " << batch1.PutParity() << std::endl;
	std::cout << "Call and Put option prices match? " << (batch1.CheckParity() ? "Yes" : "No") << std::endl << std::endl;

	//Test of batch 2
	std::cout << "Batch 2:" << std::endl << "Call: " << batch2.CallPricing() << std::endl;
	std::cout << "Put: " << batch2.PutPricing() << std::endl;
	std::cout << "Call calculated by parity: " << batch2.CallParity() << std::endl;
	std::cout << "Put calculated by parity: " << batch2.PutParity() << std::endl;
	std::cout << "Call and Put option prices match? " << (batch2.CheckParity() ? "Yes" : "No") << std::endl << std::endl;

	//Test of batch 3
	std::cout << "Batch 3:" << std::endl << "Call: " << batch3.CallPricing() << std::endl;
	std::cout << "Put: " << batch3.PutPricing() << std::endl;
	std::cout << "Call calculated by parity: " << batch3.CallParity() << std::endl;
	std::cout << "Put calculated by parity: " << batch3.PutParity() << std::endl;
	std::cout << "Call and Put option prices match? " << (batch3.CheckParity() ? "Yes" : "No") << std::endl << std::endl;

	//Test of batch 4
	std::cout << "Batch 4:" << std::endl << "Call: " << batch4.CallPricing() << std::endl;
	std::cout << "Put: " << batch4.PutPricing() << std::endl;
	std::cout << "Call calculated by parity: " << batch4.CallParity() << std::endl;
	std::cout << "Put calculated by parity: " << batch4.PutParity() << std::endl;
	std::cout << "Call and Put option prices match? " << (batch4.CheckParity() ? "Yes" : "No") << std::endl << std::endl;

	//This part tests the vector pricing functions with a vector S
	std::vector<double> putprices, callprices, Svalue;
	int N = 10;
	double h = 1.0;
	callprices = batch1.CallPricingS(h, N);
	putprices = batch1.PutPricingS(h, N);
	Svalue = MakeMesh(batch1.S(), h, N);
	std::cout << "Batch 1" << std::endl;
	for (int i = 0;i < N;i++)
	{
		std::cout << "S="<<Svalue[i]<<"; Call Price: "<<callprices[i]<<";Put Price: "<<putprices[i] << std::endl;
	}
	//This part tests the matrix function
	std::vector<std::vector<double>> results;//This matrix stores the results
	results = batch1.PricingMat(4, h, N);
	std::cout << "T\tK\tsig\tr\tS\tb\tC\tP\t";
	prtMat(results,N,8);

	//This part tests the sensitive quantities of the option
	EuropeanOptions BatchTest_Delta(1.45, 120, 0.51, 0.045, 108, 0);
	std::cout << "Test of Option Sensitivities" << std::endl;
	//Test the delta
	std::cout << "Delta Call: " << BatchTest_Delta.DeltaCall()<<std::endl;
	std::cout << "Delta Put: " << BatchTest_Delta.DeltaPut() << std::endl<<std::endl;
	//Test the vector of delta
	std::cout << "Vector Output" << std::endl;
	std::vector<double> deltaput, deltacall;
	deltaput = BatchTest_Delta.DeltaPutS(h, N);
	deltacall = BatchTest_Delta.DeltaCallS(h, N);
	for (int i = 0;i < N;i++)
	{
		std::cout << "S=" << Svalue[i] << "; Call Delta: " << deltacall[i] << ";Put Delta: " << deltaput[i] << std::endl;
	}
	//Test the matrix of sensitivity
	std::cout <<std::endl<< "Matrix Output" << std::endl;
	results = BatchTest_Delta.SensitiveMat(4, h, N);
	std::cout << "T\tK\tsig\tr\tS\tb\tDelta_C\tDelta_P\tGamma_C\tGamma_P";
	prtMat(results, N, 10);

	//This part tests the delta calculated by divided difference
	std::cout << "Using divided difference" << std::endl;
	h = 1e-1;
	std::cout << "Delta Call (Using divided difference): " << BatchTest_Delta.difDeltaCall(h) << std::endl;
	double err = abs(BatchTest_Delta.difDeltaCall(h) - BatchTest_Delta.DeltaCall());
	std::cout << "Absolute difference with exact solution: " << err << std::endl;
	err = abs(err / BatchTest_Delta.DeltaCall());
	std::cout << "Relative difference with exact solution: " << err << std::endl;
	std::cout << "Delta Put (Using divided difference): " << BatchTest_Delta.difDeltaPut(h) << std::endl;
	err= abs(BatchTest_Delta.difDeltaPut(h) - BatchTest_Delta.DeltaPut());
	std::cout << "Absolute difference with exact solution: " << err<< std::endl;
	err = abs(err / BatchTest_Delta.DeltaPut());
	std::cout << "Relative difference with exact solution: " << err << std::endl;

	//Now, test the American options
	std::cout <<std::endl<< "***American options***" << std::endl;
	AmericanOptions batchAM(100, 0.1, 0.1, 110, 0.02);
	std::cout << "Test batch" << std::endl;
	std::cout << "Call Price: " << batchAM.CallPricing()<<std::endl;
	std::cout << "Put Price: " << batchAM.PutPricing() << std::endl<<std::endl;
	h = 1;N = 10;
	//This part tests the vector
	callprices = batchAM.CallPricingS(h, N);
	putprices = batchAM.PutPricingS(h, N);
	Svalue = MakeMesh(batchAM.S(), h, N);
	std::cout << "Vector Output" << std::endl;
	for (int i = 0;i < N;i++)
	{
		std::cout << "S=" << Svalue[i] << "; Call Price: " << callprices[i] << ";Put Price: " << putprices[i] << std::endl;
	}
	//This part tests the matrix
	results = batchAM.PricingMat(3, h, N);
	std::cout << std::endl<<"Matrix Output"<<std::endl<<"K\tsig\tr\tS\tb\tC\tP\t";
	prtMat(results, N, 7);
}

