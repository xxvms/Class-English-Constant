// Class-English-Constant.cpp : Defines the entry point for the console application.
//

#include <iostream>

class Distance
{
private:
	int feet;
	double inches;
public:
	Distance() : feet(0), inches(0.0) // constructor no arguments
	{	}
	Distance(int feet_, double inches_) : feet(feet_), inches(inches_)
	{}
	void getDistance() //get lenght from user
	{
		std::cout << "Enter Feet: ";
		std::cin >> feet;
		std::cout << "Enter inches: ";
		std::cin >> inches;
	}
	void showDistance() const //Display distance
	{
		std::cout << feet << "\'-" << inches << "\" ";
	}
	Distance addDistance(const Distance&) const; // add
};
Distance Distance::addDistance(const Distance & d2) const
{
	Distance temp; // temprorary variable
	//feet = 0; // is not goig to work!!!
	//d2.feet = 22; // constant object
	temp.inches = inches + d2.inches; // add the inches 
	if (temp.inches >= 12)
	{
		temp.inches -= 12;
		temp.feet++;
	}
	temp.feet += feet + d2.feet;

	return temp;
}
int main()
{
	Distance Distance1, Distance3; // define two lengths
	Distance Distance2(11, 6.25); // define and initialize distance 2

	Distance1.getDistance(); // get Distance1 from user
	Distance3 = Distance1.addDistance(Distance2); // adds Distance 1 and Distance 2

	//Display lenght
	std::cout << "Distance 1: "; Distance1.showDistance();
	std::cout << std::endl;
	std::cout << "Distance 2: "; Distance2.showDistance();
	std::cout << std::endl;
	std::cout << "Distance 3: "; Distance3.showDistance();
	std::cout << std::endl;

	system("pause");
	return 0;
}

