#pragma once
#include <Siv3D.hpp>

class Controller
{
private:
	int index;
	unsigned jump, back;

public:
	Controller();
	~Controller();

	int get_index() { return index; }
	void set_index(int index) { this->index = index; }

	void Reset();

	unsigned get_jump() { return jump; }
	unsigned get_back() { return back; }

	void Update();
};

