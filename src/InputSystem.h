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
private:
	std::vector<Binding> i_bindings;
	std::thread* loop;
};

