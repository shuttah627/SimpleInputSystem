#pragma once
#include <thread>
#include <conio.h>
#include <vector>
#include <iostream>

struct Binding
{
	char b_target;
	void(*b_function)();
};

class InputSystem
{
public:
	InputSystem();
	~InputSystem();
	
	void BindKey(char target, void(*function)());
	void MainLoop();

private:
	std::thread* loop;
	std::vector<Binding> i_bindings;
	bool runThread = true;
};

