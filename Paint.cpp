/*kaya Ota 
*CIS 278
*2013/2/11
*/


#include <iostream>

using namespace std;

void getRoomSize(int& squareFt);
int paintRequired (int squareFt);
double computeLabor(int squareFt);
double jobCost(int gallons, double hours );

int main()
{
	int manyRooms = 0;
	int roomSize = 0;
  	double  hours = 0;
	int paint = 0;
	double totalCost = 0.0;
	int roomLoop =0;
	do
	{
		cout << "Enter the number of rooms to be painted";
		cin >> manyRooms;
		cout << "\n";
		if(manyRooms < 1)
		{
			cout << "invalid. entry positive";
		}
	}while(manyRooms < 1);
	
	roomLoop = manyRooms - 1;
	do
	{
		cout << "Enter size of the room in square feet";
		cin >> roomSize;
		if(roomSize < 1)
		{
			cout << "invalid. enter psitive!";
		}
	}while(roomSize < 1);


	for(int index = 0; index <  roomLoop; index++)
	{
		getRoomSize(roomSize);
	}
	cout << "\nTotal room size is "<< roomSize << "ft^2";
	
	//calculate the amout of paint requirement 
	paint = paintRequired(roomSize);
	cout << "\n Requirement for paints: "<< paint << "Gallon/paint\n"; 
	
	//evaluate required hours to paint 
	hours = (int) computeLabor(roomSize);
	cout << "total required hours of labor is"<< hours << "h";
	
	//estimete both total cost
	totalCost = jobCost(paint, hours);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Total cost $ "<< totalCost << "\n";
	
	cout << "thank you for using this program";
	cout << "\nprogramed by Kaya Ota ";
}//main 


void getRoomSize(int& squareFt)
{
	int roomSizes;
	do
	{
		cout << "Enter the size of the next room: ";
		cin >> roomSizes;
		cout << "\n";
	
		squareFt += roomSizes;
		if(roomSizes < 1)
		{
			cout << "invalid. ";
		}
	}while(roomSizes < 1);
}

int paintRequired (int squareFt)
{
	const int galPSquareFt = 115; //gallons per square feet
	if(squareFt <= galPSquareFt)
	{
		return 1;//1 gallon needs
	}
	else 
	{
		return 1 + paintRequired(squareFt - galPSquareFt ); 
	}
}
double computeLabor(int squareFt)
{
	const double hoursPgal = 8.0;
	double hours;
	if(squareFt < 115 && squareFt > 0)
	{
		hours = 8.0;
	}
	else
	{
		 hours = squareFt / 115 * hoursPgal;
	}
	return hours;
}
double jobCost(int gallons, double hours)
{
	const double laborPhours = 18.00;//labor per hours
	const double paintPgal = 15.00;//paint per gallons

	double paintCost = gallons * paintPgal;
	double laborCost = hours * laborPhours; 
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "\nCost of Labor $" << laborCost << "\n";
	cout << "\nCost of Paint $" << paintCost << "\n";
	cout << "\n";

	double total = laborCost + paintCost;

	return total;
}








