#include "InputSystem.h"

void InputSystem::MainLoop()
{
	while (runThread)
	{
		char x = _getch();
		//std::cout << "pressed " << x << std::endl;

		for (Binding i : i_bindings)
		{
			if (i.b_target == x)
			{
				i.b_function();
			}
		}
	}
}

InputSystem::InputSystem()
{
	loop = new std::thread(&InputSystem::MainLoop, this);
}



InputSystem::~InputSystem()
{
	//std::cout << "quitting";
	loop->detach();
	delete loop;
}

void InputSystem::BindKey(char target, void(*function)())
{
	Binding x;
	x.b_target = target;
	x.b_function = function;

	i_bindings.emplace_back(x);
}

