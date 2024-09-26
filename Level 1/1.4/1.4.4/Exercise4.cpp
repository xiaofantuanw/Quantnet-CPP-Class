#include<stdio.h>

int main()
{
	double start_temp=0, end_temp=300, step=20,current_temp_Fahrenheit, current_temp_Celsius;//start and end temperatures, and the temperature step
	printf("Temperature Comparison Table\n");
	printf("Fahrenheit\tCelsius\n");
	current_temp_Fahrenheit = start_temp;//Start with
	while (current_temp_Fahrenheit <= end_temp)//When the temperature doesn't reach the end, output the comparison
	{
		current_temp_Celsius = 5. / 9 * (current_temp_Fahrenheit - 32);
		printf("%10.1f, %10.1f\n", current_temp_Fahrenheit, current_temp_Celsius);
		current_temp_Fahrenheit += step;
	}
	return 0;
}