#include "InputSystem.h"

void MainLoop()
{
	while (true)
	{
		int x = _getch();
		std::cout << "pressed " << x << std::endl;
	}
}

InputSystem::InputSystem()
{
	loop = new std::thread(MainLoop);
}


InputSystem::~InputSystem()
{
	delete loop;
}

void InputSystem::BindKey(char target, void(*function)())
{
	Binding x;
	x.b_target = target;
	x.b_function = function;

	i_bindings.emplace_back(x);
}

