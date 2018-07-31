#include "Controller.h"

Controller::Controller()
{
	index = 0;
	jump = 0;
	back = 0;
}

Controller::~Controller()
{
}

void Controller::Reset()
{
	jump = 0;
	back = 0;
}

void Controller::Update()
{
	auto controller = XInput(index);

	//コントローラー操作
	if (controller.isConnected()) {
		if (controller.buttonA.pressed || controller.buttonB.pressed || controller.buttonRB.pressed) {
			jump++;
		}
		else {
			jump = 0;
		}
		
		if (controller.buttonX.pressed || controller.buttonY.pressed || controller.buttonLB.pressed) {
			back++;
		}
		else {
			back = 0;
		}
	}
	//キーボード操作
	else {
		switch (index) {
		case 0:
			if (Input::KeyS.pressed || Input::KeyZ.pressed) {
				jump++;
			}
			else {
				jump = 0;
			}
			if (Input::KeyW.pressed || Input::KeyA.pressed) {
				back++;
			}
			else {
				back = 0;
			}
			break;
		case 1:
			if (Input::KeyK.pressed || Input::KeyM.pressed) {
				jump++;
			}
			else {
				jump = 0;
			}
			if (Input::KeyJ.pressed || Input::KeyI.pressed) {
				back++;
			}
			else {
				back = 0;
			}
			break;
		default:
			if (Input::KeyS.pressed || Input::KeyZ.pressed) {
				jump++;
			}
			else {
				jump = 0;
			}
			if (Input::KeyW.pressed || Input::KeyA.pressed) {
				back++;
			}
			else {
				back = 0;
			}
			break;
		}
	}
}