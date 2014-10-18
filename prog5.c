/*Tyler Jowaisas
Integral calculator
10/17/14

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double func(double x);
double integrate(double low_point, double high_point, int n);
int input_checker(double low_point, double high_point, int n, int input_check1, int input_check2);
void clear();

int main()
	{
		//high and low point interval variables
		double low_point, high_point;
		//number of trapezoids used in this iteration
		int num_traps;
		//checks that we've read all the appropriate values
		int input_check1, input_check2;
		double integral_value;
		char do_again;
		
		printf("Enter end point of the integration (low high): ");
		input_check1 = scanf("%lf %lf", &low_point, &high_point);
		printf("\nEnter number of trapezoids to use: ");
		input_check2 = scanf("%d", &num_traps);
		
		//hopefully this just checks for if everything is enterted properly
		//it COULD clean up the code nicely.  Or I could pull my hair out.
		//printf("\n 1 \n");
		input_checker(low_point, high_point, num_traps, input_check1, input_check2);
		
		integral_value = integrate(low_point, high_point, num_traps);
		printf("\nThe integral of the function is: %5.3lf ", integral_value);
		
		do{				
				printf("\nDo it again?: ");
				clear();
				scanf(" %c", &do_again);
				
				switch(do_again)
				{
					case 'Y': case 'y':
						printf("Enter end point of the integration (low high)");
						input_check1 = scanf("%lf %lf", &low_point, &high_point);
						printf("\nEnter number of trapezoids to use");
						input_check2 = scanf("%d ", &num_traps);
						input_checker(low_point, high_point, num_traps, input_check1, input_check2);
						break;
					case 'N': case 'n':
						printf("Press Enter to Exit");
						exit(0);
				}
				
			}while(do_again == 'Y' || do_again == 'y');
		



		return 0;

	}
double integrate(double low_point, double high_point, int n)
	{
		//delta x will be (high_point - low_point)/num_traps
		double delta_x, sum_value;
		//place holder for low_point so we can use it in a loop
		double x;
		//steps through for loop
		int i;
		
		delta_x = (high_point - low_point)/n;
		x = low_point;
		
		//loop to iterate through all the y values
		for(i = 1; i < n; i++)
			{
				sum_value = (func(x) );
				x += delta_x;
			}
		return ((delta_x /2) * (func(low_point) + 2*(sum_value) + func(high_point)));
		//math stuff
		
	}

int input_checker(double low_point, double high_point, int num_traps, int input_check1, int input_check2)
	{
	//printf("Entering input_checker \n");
		while(num_traps < 1 || low_point > high_point || input_check1 < 2 || input_check2 != 1)
			{				
				clear();
				
				if(num_traps < 1)
					{
						printf("\nYou need to have at least one trapezoid");
						input_check2 = scanf("%d ", &num_traps);
						
					}
				else if(low_point > high_point)
					{
						printf("\nThe low point can't be higher than the high point");
						input_check1 = scanf("%lf %lf", &low_point, &high_point);
						
					}
				else if(input_check1 < 2)
					{
						printf("\nYou entered the (low high) in an improper format");
						input_check1 = scanf("%lf %lf", &low_point, &high_point);
						
					}
				else if (input_check2 != 1)
					{
						printf("\nYou entered an improper format for number of trapezoids");
						input_check2 = scanf("%d", &num_traps);
						
					}
				else
					{
						printf("\nSome issue.  Derp");
						
					}
			}
			
			if(num_traps >=1 && low_point < high_point && input_check1 ==2 && input_check2 == 1)
				{
				 return 1;
				}
	}

double func(double x)
	{	
		double sin_value;
		sin_value = sin(x);
		return (sin_value + (x * x)/10);
	}  

void clear()
	{
		while(getchar() != '\n');
	}
