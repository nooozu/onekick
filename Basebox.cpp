#include "Basebox.h"

#define abs(x) (((x > 0) ? x : -x))

Basebox::Basebox()
{
	pos.x = 0;
	pos.y = 0;
	offset.x = 0;
	offset.y = 0;
}

Basebox::Basebox(Point2D pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	offset.x = 0;
	offset.y = 0;
}

Basebox::Basebox(float pos_x, float pos_y)
{
	pos.x = pos_x;
	pos.y = pos_y;
	offset.x = 0;
	offset.y = 0;
}

Basebox::Basebox(Point2D pos, Point2D offset)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->offset.x = offset.x;
	this->offset.y = offset.y;
}

Basebox::Basebox(float pos_x, float pos_y, float offset_x, float offset_y)
{
	pos.x = pos_x;
	pos.y = pos_y;
	offset.x = offset_x;
	offset.y = offset_y;
}

Basebox::~Basebox()
{
}

bool Basebox::HitCheck(Basebox target) const
{
	Point2D t = target.get_pos();
	Point2D t_offset = target.get_offset();

	float a_x_min = pos.x - offset.x / 2;
	float a_y_min = pos.y - offset.y / 2;
	float a_x_max = pos.x + offset.x / 2;
	float a_y_max = pos.y + offset.y / 2;

	float b_x_min = t.x - t_offset.x / 2;
	float b_y_min = t.y - t_offset.y / 2;
	float b_x_max = t.x + t_offset.x / 2;
	float b_y_max = t.y + t_offset.y / 2;

	if (a_x_max < b_x_min) {
	}
	else if (b_x_max < a_x_min) {
	}
	else if (a_y_max < b_y_min) {
	}
	else if (b_y_max < a_y_min) {
	}
	else {
		return true;
	}

	return false;
}

void Basebox::Draw(Color c)
{
	Rect(
		pos.x - offset.x / 2,
		pos.y - offset.y / 2,
		offset.x,
		offset.y
	).drawFrame(1.0, 0.0, c);
}
