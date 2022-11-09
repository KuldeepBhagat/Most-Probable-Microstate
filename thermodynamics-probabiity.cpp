#include <iostream>
using std::cout; using std::cin; using std::endl;

int factorial(int a)
{
	if (a > 0)
	{
  return a*factorial(a-1);	
  }
	else 
	{
		return 1;
	}
}

int microstate(int N)
{	

//Total Number of Microstates.
//For two compartments only!!

int TotalNumber = 1;
while(N > 0)
{

TotalNumber = TotalNumber*2;
N--;

}
return TotalNumber;
}
int Number_Of_Micro(int Total_Partical)
{
// Calculating Thermodynamics Probability (W)

int Compartment1,Compartment2, factorial_of_n, factorial_of_N,factorial_of_Compartment2,W;
if (Total_Partical%2 == 0)
{
 Compartment1 = Total_Partical/2;
 Compartment2 = Total_Partical - Compartment1;
}
else 
{
	Compartment1 = (Total_Partical - 1)/2;
	Compartment2 = (Total_Partical + 1)/2;
}

// W(n, N-n)

factorial_of_n = factorial(Compartment1);
factorial_of_N = factorial(Total_Partical);
factorial_of_Compartment2 = factorial(Compartment2);

W = factorial_of_N/(factorial_of_n*factorial_of_Compartment2);
return W;
}
int main()
{
	int N;
	float Thermo_Probability,Total_No_Of_Microstate;
	float MPM;
  cout << "Enter Number of Particals " << endl << "Note!! input should be Even number" << endl;
	cin >> N;

  Total_No_Of_Microstate = microstate(N);
  Thermo_Probability = Number_Of_Micro(N);
  
	
  MPM = Thermo_Probability/Total_No_Of_Microstate;

  cout << "Most Probable Microstate: " << MPM << endl; 

		return 0;
}

