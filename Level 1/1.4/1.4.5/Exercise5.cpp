#include<stdio.h>

int main()
{
	double start_temp = 0, end_temp = 19, step = 1, current_temp_Fahrenheit, current_temp_Celsius;//start and end temperatures, and the temperature step
	printf("Temperature Comparison Table\n");
	printf("Celsius\t\tFahrenheit\n");
	for (current_temp_Celsius = start_temp;current_temp_Celsius <= end_temp;current_temp_Celsius+=step)//When the temperature doesn't reach the end, output the comparison
	{
		current_temp_Fahrenheit = 9. / 5 * current_temp_Celsius + 32;
		printf("%10.1f, %10.1f\n", current_temp_Celsius,current_temp_Fahrenheit );
	}
	return 0;
}