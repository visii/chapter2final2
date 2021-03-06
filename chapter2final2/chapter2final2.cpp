// chapter2final2.cpp : Write a short program to simulate a ball being dropped off of a tower. 
// To start, the user should be asked for the height of the tower in meters. 
// Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
// Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. 
// The ball should not go underneath the ground (height 0).
//



#include "pch.h"
#include <iostream>
//Contains the value of gravity, as intructed
#include "constants.h"
//Forward declarations to all the functions
#include "balldrop.h"

int main()
{
	//Gets the height of the tower from the user.
	double tHeight{ towerHeight() };
	//Sets initial time to zero, the printPosition functions will increase the time themselves.
	int time{ 0 };
	//Uses the ballPosition function to get the height of the ball,
	//and sends it to printPosition to be printed.
	printPosition(ballPosition(time, tHeight), time, tHeight);
	return 0;
}

//Using a double so it can take exact tower heights.
double towerHeight()
{
	std::cout << "Enter the height of the tower ";
	double tHeight{};
	std::cin >> tHeight;
	return tHeight;
}

// Calculates the height of the ball using the supplied formula
double ballPosition(int time, double tHeight)
{
	return (tHeight - (myConstants::gravity * (time*time) / 2));
}

//Initially takes its input from main, then loops with the printPosition1 function.
void printPosition(double ballPos, int time, double tHeight)
{
	//Checks if the ball is on the ground by seeing if the ball has fallen 
	//further than the height of the tower.
	if (ballPos <= 0.0)
		std::cout << "At " << time << " seconds, the ball is on the ground" << '\n';
	//If the ball is not on the ground yet, it will print the current height
	else if (ballPos > 0.0)
	{
		std::cout << "At " << time << " seconds, the ball is at height: " << ballPos << '\n';
		//Adds an extra second to the time
		time++;
		//And calls printPosition1 with the updated time
		printPosition1(ballPosition(time, tHeight), time, tHeight);
	}
}


void printPosition1(double ballPos, int time, double tHeight)
{
	if (ballPos <= 0.0)
		std::cout << "At " << time << " seconds, the ball is on the ground" << '\n';
	else if (ballPos > 0.0)
	{
		std::cout << "At " << time << " seconds, the ball is at height: " << ballPos << '\n';
		//Which adds an extra second to the time
		time++;
		//And calls printPosition again with the updated time,
		//this loops until the ball hits the ground, then we return to main.
		printPosition1(ballPosition(time, tHeight), time, tHeight);
	}
}