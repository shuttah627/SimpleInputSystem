#include "../src/InputSystem.h"
#include <iostream>

int value;
bool isRunning = true;

void Inc()
{
	value++;
	std::cout << "Increasing Value! : " << value << std::endl;
}

void Dec()
{
	value--;
	std::cout << "Decreasing Value! : " << value << std::endl;
}

void quitLoop()
{
	isRunning = false;
}

int main()
{
	InputSystem* inputs = new InputSystem();;

	inputs->BindKey('w', Inc);
	inputs->BindKey('s', Dec);
	inputs->BindKey('q', quitLoop);

	std::cout << "Welcome to the increment and decrement example!" << std::endl << "Use 'w' and 'd' to increment and decrement a value! Press 'q' to quit program!" << std::endl;

	while (isRunning)
	{
		// Imagine the game loop here. This is just to keep the program running.
	}

	delete inputs;
	return 1;
}
