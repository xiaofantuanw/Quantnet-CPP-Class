/*test.cpp
* Author:Tengxiao Fan
* This tests the random functionality in boost.
*/

#include <boost/random.hpp> // Convenience header file
#include <iostream>
#include <ctime>			// std::time
#include <map>
#include <iomanip>

int main()
{
	// Throwing dice.
	// Mersenne Twister.
	boost::random::mt19937 myRng;
	// Set the seed.
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));
	// Uniform in range [1,6]
	boost::random::uniform_int_distribution<int> six(1, 6);
	std::map<int, long> statistics; // Structure to hold outcome + frequencies
	int outcome; // Current outcome
	long N;//Trial number
	std::cout << "Please Input the number of trials." << std::endl;
	std::cin >> N;
	for (int num = 1;num <= 6;num++)
	{
		statistics[num] = 0;//Set the initial frequency
	}
	for (int i = 1;i <= N;i++)
	{
		outcome = six(myRng);//Do the trial
		statistics[outcome]=statistics[outcome]+1;//Add to the frequency
	}
	
	//Outputs
	std::cout << "How many trials? " << N << std::endl << std::endl;
	std::map<int, long>::iterator im = statistics.begin();
	for (im = statistics.begin();im != statistics.end();im++)//Iterate through the map
	{
		double percentage = (double)im->second / N * 100;//The percentage of a number
		std::cout << "Trial " << im->first << " has " << std::setiosflags(std::ios::fixed) << std::setprecision(4) << percentage << "% outcomes" << std::endl;
	}
	
}