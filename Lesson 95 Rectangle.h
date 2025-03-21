#pragma once
class Rectangle
{
private:
	int height = 10;
	int width = 10;
public:
	void SetHeight(int newHeight);
	void SetWidth(int newWidth);
	int GetHeight() const;
	int GetWidth() const;

};

