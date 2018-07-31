#pragma once
#include <Siv3D.hpp>

typedef struct {
	float x, y;
} Point2D;

class Basebox
{
protected:
	Point2D 
		pos,     //box‚Ì’†S“_
		offset;  //box‚Ì•
	
public:
	Basebox();
	Basebox(Point2D pos);
	Basebox(Point2D pos, Point2D offset);
	Basebox(float pos_x, float pos_y);
	Basebox(float pos_x, float pos_y, float offset_x, float offset_y);
	~Basebox();

	void set_pos(Point2D pos) { this->pos = pos; }
	void set_pos_x(float x) { pos.x = x; }
	void set_pos_y(float y) { pos.y = y; }

	void set_offset(Point2D offset) { this->offset = offset; }
	void set_offset_x(float x) { offset.x = x; }
	void set_offset_y(float y) { offset.y = y; }

	Point2D get_pos() { return pos; }
	Point2D get_offset() { return offset; }

	bool HitCheck(Basebox target) const;

	void Draw(Color c = Color(255, 255, 255));
};

