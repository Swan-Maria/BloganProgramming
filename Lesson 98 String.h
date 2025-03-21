#pragma once
class String
{
private:
	char* str;
	void Copy(const char* str);
public:
	String();
	String(const char* str);
	~String();
	const char* GetString() const;
	size_t GetSize() const;
	void SetString(const char* str);

	const String& CompareBySize(const String& other);

};

