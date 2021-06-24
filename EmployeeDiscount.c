// ------------------------------------------------------------------------------------------
// Name: Neina Cichon
// Abstract: Employee Discount
// Date: 2020-09-25
// ------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes – built-in libraries of functions
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------
const double DISCOUNT_10 = .10;
const double DISCOUNT_14 = .14;
const double DISCOUNT_20 = .20;
const double DISCOUNT_24 = .24;
const double DISCOUNT_25 = .25;
const double DISCOUNT_30 = .30;
const double DISCOUNT_35 = .35;
const double DISCOUNT_40 = .40;
const double YTD_PURCHASE_DISCOUNT_MAX = 200.00;


// --------------------------------------------------------------------------------
// User Defined Types (UDT)
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes - Methods
// --------------------------------------------------------------------------------
double GetEmployeeDiscount(int* pintYearsWorked, char* intchrEmployeeStatus);
double GetManagerDiscount(int intYearsWorked);
double GetHourlyDiscount(int intYearsWorked);
double GetYTDAmountDiscount(double dblPreviousPurchases, double dblDiscount);
double MaxDiscount(double dblCurrentPurchases, double dblDiscount, double dblYTDDiscountTotal);




// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------
void main()
{
	//Declare Variables
	int intYearsWorked = 0;
	char chrEmployeeStatus = "x";
	double dblPreviousPurchases = 0;
	double dblCurrentPurchases = 0;
	double dblDiscount = 0;
	double dblCurrentDiscount = 0;
	double dblYTDDiscountTotal = 0;
	double dblPurchaseTotal = 0;
	char chrNewTransaction = ' ';
	double dblAllEmployeeTotalBefore = 0;
	double dblAllEmployeeTotalAfter = 0;


	printf("Employee Discount\n--------------------------------------------");
do
{
	//Get user input
	do
	{
		printf("\nEnter years worked: ");
		scanf_s("\n%d", &intYearsWorked);

	} while (intYearsWorked < 0);

	do
	{
		printf("\nEnter employee status (\"H\" for Hourly or \"M\" for Manager): ");
		scanf_s("\n%c", &chrEmployeeStatus);

	} while (chrEmployeeStatus != 'h' && chrEmployeeStatus != 'H' && chrEmployeeStatus != 'm' && chrEmployeeStatus != 'M');

	do
	{
		printf("\nEnter total amount of PREVIOUS purchases: ");
		scanf_s("\n%lf", &dblPreviousPurchases);

	} while (dblPreviousPurchases < 0);

	do
	{
		printf("\nEnter total amount of TODAY'S purchase: ");
		scanf_s("\n%lf", &dblCurrentPurchases);

	} while (dblCurrentPurchases <= 0);

	dblDiscount = GetEmployeeDiscount(&intYearsWorked, &chrEmployeeStatus);


	dblYTDDiscountTotal = GetYTDAmountDiscount(dblPreviousPurchases, dblDiscount);

	dblCurrentDiscount = MaxDiscount(dblCurrentPurchases, dblDiscount, dblYTDDiscountTotal);
	dblPurchaseTotal = dblCurrentPurchases - dblCurrentDiscount;

	printf("\n--------------------------------------------------------------\n");
	printf("Employee Discount Percentage: %lf\n", dblDiscount);
	printf("YTD Discount Amount (Not including current purchase): $%.2lf\n", dblYTDDiscountTotal);
	printf("Current Purchase (before discount): $%.2lf\n", dblCurrentPurchases);
	printf("Employee discount this purchase: $%.2lf\n", dblCurrentDiscount);
	printf("Total with discount: $%.2lf\n", dblPurchaseTotal);
	printf("--------------------------------------------------------------\n");

	do
	{
		printf("\nWould you like to enter another transaction (Y or N)?: ");
		scanf_s("\n%c", &chrNewTransaction);

	} while (chrNewTransaction != 'n' && chrNewTransaction != 'N' && chrNewTransaction != 'y' && chrNewTransaction != 'Y');

	printf("--------------------------------------------------------------\n");
	dblAllEmployeeTotalBefore += dblCurrentPurchases;
	dblAllEmployeeTotalAfter += dblPurchaseTotal;

} while (chrNewTransaction == 'y' || chrNewTransaction == 'Y');


printf("--------------------------------------------------------------\n");
printf("All Employee Summary\n");
printf("--------------------------------------------------------------\n");
printf("All Employee Total (Before Discount): $%.2lf\n", dblAllEmployeeTotalBefore);
printf("All Employee Total (After Discount): $%.2lf\n", dblAllEmployeeTotalAfter);
printf("--------------------------------------------------------------\n\n");


	system("pause");
}




// --------------------------------------------------------------------------------
// Name: GetEmployeeDiscount
// Abstract: Get Employee discount based on manager or hourly and years worked
// --------------------------------------------------------------------------------
double GetEmployeeDiscount(int* pintYearsWorked, char* pchrEmployeeStatus)
{
	double dblDiscount = 0;

	if (*pchrEmployeeStatus == 'm' || *pchrEmployeeStatus == 'M')
	{
		dblDiscount = GetManagerDiscount(*pintYearsWorked);
	}
	else
	{
		dblDiscount = GetHourlyDiscount(*pintYearsWorked);
	}
	return dblDiscount;
}



// --------------------------------------------------------------------------------
// Name: GetManagerDiscount
// Abstract: Determines discount for Managers based on years worked
// --------------------------------------------------------------------------------
double GetManagerDiscount(int intYearsWorked)
{
	double dblDiscount = 0;

	if (intYearsWorked <= 0)
	{
		dblDiscount = 0;
	}
	else if (intYearsWorked <= 3)
	{
		dblDiscount = DISCOUNT_20;
	}
	else if (intYearsWorked <= 6)
	{
		dblDiscount = DISCOUNT_24;
	}
	else if (intYearsWorked <= 10)
	{
		dblDiscount = DISCOUNT_30;
	}
	else if (intYearsWorked <= 15)
	{
		dblDiscount = DISCOUNT_35;
	}
	else
	{
		dblDiscount = DISCOUNT_40;
	}

	return dblDiscount;
}


// --------------------------------------------------------------------------------
// Name:  GetHourlyDiscount
// Abstract: Determines discount for hourly employees based on years worked
// --------------------------------------------------------------------------------
double GetHourlyDiscount(int intYearsWorked)
{
	double dblDiscount = 0;

	if (intYearsWorked <= 0)
	{
		dblDiscount = 0;
	}
	else if (intYearsWorked <= 3)
	{
		dblDiscount = DISCOUNT_10;
	}
	else if (intYearsWorked <= 6)
	{
		dblDiscount = DISCOUNT_14;
	}
	else if (intYearsWorked <= 10)
	{
		dblDiscount = DISCOUNT_20;
	}
	else if (intYearsWorked <= 15)
	{
		dblDiscount = DISCOUNT_25;
	}
	else
	{
		dblDiscount = DISCOUNT_30;
	}
	return dblDiscount;
}



// --------------------------------------------------------------------------------
// Name: GetYTDAmountDiscount
// Abstract: Get YTD Discount amount
// --------------------------------------------------------------------------------
double GetYTDAmountDiscount(double dblPreviousPurchases, double dblDiscount)
{
	double dblYTDDiscountTotal = 0;

	if (dblPreviousPurchases * dblDiscount >= 200)
	{
		dblYTDDiscountTotal = 200;
	}
	else if (dblPreviousPurchases * dblDiscount > 0)
	{

		dblYTDDiscountTotal = dblPreviousPurchases * dblDiscount;
	}
	else
	{
		dblYTDDiscountTotal = 0;
	}
	return dblYTDDiscountTotal;
}



// --------------------------------------------------------------------------------
// Name: MaxDiscount
// Abstract: check to make sure YTD discount does not exceed $200
// --------------------------------------------------------------------------------

double MaxDiscount(double dblCurrentPurchases, double dblDiscount, double dblYTDDiscountTotal)
{	
	double CurrentDiscount = 0;

	if (dblYTDDiscountTotal >= YTD_PURCHASE_DISCOUNT_MAX)
	{
		dblYTDDiscountTotal = YTD_PURCHASE_DISCOUNT_MAX;
		CurrentDiscount = 0;
	}
	else
	{
		if (dblYTDDiscountTotal < YTD_PURCHASE_DISCOUNT_MAX)
		{
			if ((dblCurrentPurchases * dblDiscount) + dblYTDDiscountTotal > YTD_PURCHASE_DISCOUNT_MAX)
			{
				CurrentDiscount = YTD_PURCHASE_DISCOUNT_MAX - dblYTDDiscountTotal;
			}
			else
			{
				CurrentDiscount = (dblCurrentPurchases * dblDiscount);
			}
		}
	}

	return CurrentDiscount;
}