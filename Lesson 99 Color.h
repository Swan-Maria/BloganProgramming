#pragma once
class Color
{
private:
	using byte = unsigned char;
	byte red = 0;
	byte green = 0;
	byte blue = 0;
public:
	Color(byte red = 0, byte green = 0, byte blue = 0);
	~Color();
	void SetR(byte red) { this->red = red; }
	void SetG(byte green) { this->green = green; }
	void SetB(byte blue) { this->blue = blue; }
	byte GetR() const { return red; }
	byte GetG() const { return green; }
	byte GetB() const { return blue; }
	void ShowRGB() const;
};