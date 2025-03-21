#pragma once

//forward declaration
class Ork;

class Shaman
{
private:
	int hp;
	char name[20];
	/*...*/
public:
	Shaman(const char* name, int hp = 100);
	
	int GetHP() const { return hp; }
	const char* GetName() const { return name; }

	void Heal(Ork& ork);

};

