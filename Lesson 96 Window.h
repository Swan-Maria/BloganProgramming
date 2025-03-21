#pragma once

class Window
{
private:
	int x=0;
	int y=0;
	int height=10;
	int width=10;
	const int maxHeight=500;
	const int maxWidth=600;
public:
	/*
	Constructor creation syntax:
	1. Prototype:
		Class_name (parameter_list) ;
	2. Definitions:
		Class_name :: Class_name (parameter_list)
	{
		Code
	}
	*/
	//Window() { int x = 0; int y = 0; int height = 10; int width = 10; }
	//Window(int originX, int originY, int originHeight, int originWidth, int originMaxHeight, int originMaxWidth);
	Window(int originX=0, int originY=0, int originHeight=5, int originWidth=5);
	//Window(int originX, int originY);

	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetHeight() const { return height; }
	int GetWidth() const { return width; }
	void SetX(int newX);
	void SetY(int newY);
	void SetHeight(int newHeight);
	void SetWidth(int newWidth);
	void Show() const;

};

