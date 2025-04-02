#include <iostream>
#include <string>

void Constants();
void Constructor();
void AssignmentOperator();
void Method_assign();
void Method_get_allocator();
void ElementAccess();
void Iterators();
void Capacity();
void Operations();
void Search();
void NonMemberFunctions();

int main()
{
	// ----------------- General Information -----------------
	// There is a templated class 'std::basic_string' designed
	// to manipulate strings of any character type.
	// This class generalizes how sequences of characters are 
	// manipulated and stored. String creation, manipulation, 
	// and destruction are all handled by a convenient set of 
	// class methods and related functions. 
	// 
	// Several specializations of std::basic_string are provided for commonly used types :
	// |		Alias	|		Specialization		 |
	// | std::string	| std::basic_string<char>	 |
	// | std::wstring	| std::basic_string<wchar_t> | (C++11)
	// | std::u8string  | std::basic_string<char8_t  | (C++20)
	// | std::u16string | std::basic_string<char16_t>| (C++11)
	// | std::u32string | std::basic_string<char32_t>| (C++11)
	// 
	// Most popular specialization is std::string. 
	// 
	// Don't forget to include <string> file to use all std::basic_string specializations. 
	// -------------------------------------------------------
	//
	// -------------------- Member Types ---------------------
	// std::string::value_type				- char
	// std::string::traits_type				- std::char_traits<char>
	// std::string::allocator_type			- std::allocator<char>
	// 
	// std::string::size_type				- std::size_t
	// std::string::difference_type			- std::ptrdiff_t
	// 
	// std::string::reference				- char&
	// std::string::const_reference			- const char&
	// 
	// std::string::pointer					- char*
	// std::string::const_pointer			- const char*
	// 
	// std::string::iterator				- std::string::iterator
	// std::string::const_iterator			- std::string::const_iterator
	// std::string::reverse_iterator		- std::reverse_iterator<std::string::iterator>
	// std::string::const_reverse_iterator  - std::reverse_iterator<std::string::const_iterator>
	// -------------------------------------------------------
	// ---------------------- Destructor ---------------------
	// All character stired in free store,
	// so when you destroy the string object,
	// it calls destructor.
	// -------------------------------------------------------

	Constants();
	Constructor();
	AssignmentOperator();
	Method_assign();
	Method_get_allocator();
	ElementAccess();
	Iterators();
	Capacity();
	Operations();
	Search();
	NonMemberFunctions();

	return 0;
}

void Constants() 
{
	std::cout << "---------------- Constants ----------------\n\n";
	// std::string::npos - static special value equal to the maximum value representable by the type size_t.
	// Thete are many functions which work with std::string and return std::string::npos if the result is not found.
	std::cout << "std::string::npos = " << std::string::npos << "\n\n";
	system("pause");
	system("cls");
}
void Constructor()
{
	std::cout << "---------------- Constructor ----------------\n\n";
	
	// std::string() has a lot of constructors (18 in C+20).
	// Here are most popular of them.

	// 1. Default constructor - constructs an empty string.
	std::cout << "Default constructor:\n";
	std::string str1;
	std::cout << "str1 = [" << str1 << "]\n\n";

	// 2. C-string constructor - constructs a string from a null-terminated character array.
	std::cout << "C-string constructor:\n";
	std::string str2("Hello str2");
	std::string str3{ "Hello str3" };
	std::string str4 = "Hello str4";
	std::cout << "str2 = [" << str2 << "]\n";
	std::cout << "str3 = [" << str3 << "]\n";
	std::cout << "str4 = [" << str4 << "]\n\n";

	// 3. Copy constructor - constructs a string from another string.
	std::cout << "Copy constructor:\n";
	std::string str5(str2);
	std::cout << "str5 = [" << str5 << "]\n\n";

	// 4. Move constructor - constructs a string from another string using move semantics.
	std::cout << "Move constructor:\n";
	std::string str6(std::move(str3));
	std::cout << "str6 = [" << str6 << "]\n";
	std::cout << "str3 = [" << str3 << "]\n\n";

	// 5. Chaaracter amount constructor - constructs a string with n characters.
	std::cout << "Character amount constructor:\n";
	std::string str7(5, '!');
	std::cout << "str7 = [" << str7 << "]\n\n";

	// 6. std::initializer_list constructor - constructs a string from an initializer list.
	std::cout << "std::initializer_list constructor:\n";
	std::string str8{ 'H', 'e', 'l', 'l', 'o' };
	std::cout << "str8 = [" << str8 << "]\n\n";

	// 7. Partial Copy Constructor - constructs a string from a part of another string.
	std::cout << "Partial Copy Constructor:\n";
	std::string str9("Hello World");
	std::string str10(str9, 6);
	std::cout << "str10 = [" << str10 << "]\n\n";

	// 8. Partial Copy (with char amount) Constructor
	std::cout << "Partial Copy (with char amount) Constructor:\n";
	std::string str11("My name is Demien");
	std::string str12(str11, 3, 4);
	std::cout << "str12 = [" << str12 << "]\n\n";

	// 9. Partial Copy from C-str Constructor
	std::cout << "Partial Copy from C-str Constructor:\n";
	std::string str13("Hello World", 5);
	std::cout << "str13 = [" << str13 << "]\n\n";

	system("pause");
	system("cls");
}
void AssignmentOperator()
{
	std::cout << "---------------- Assignment Operator ----------------\n\n";
	
	// You can assign one string to another using overloaded assignment operator.
	// This operator has 5 overloads.

	// 1. Assign character - assigns a string with n characters.
	std::cout << "Assign character:\n";
	std::string str1 = "str1";
	std::cout << "str1 = [" << str1 << "]\n";
	str1 = '!';
	std::cout << "str1 = [" << str1 << "]\n\n";

	// 2. Assign C-string - assigns a string from a null-terminated character array.
	std::cout << "Assign C-string:\n";
	std::string str2 = "str2";
	std::cout << "str2 = [" << str2 << "]\n";
	str2 = "abc";
	std::cout << "str2 = [" << str2 << "]\n\n";

	// 3. Assign std::initializer_list - assigns a string from an initializer list.
	std::cout << "Assign std::initializer_list:\n";
	std::string str3 = "str3";
	std::cout << "str3 = [" << str3 << "]\n";
	str3 = { '1', 'A', '#' };
	std::cout << "str3 = [" << str3 << "]\n\n";

	// 4. Assign std::string - assigns a string from another string.
	std::cout << "Assign std::string:\n";
	std::string str4 = "str4";
	std::string str5 = "str5";
	std::cout << "str4 = [" << str4 << "]\n";
	str4 = str5;
	std::cout << "str4 = [" << str4 << "]\n\n";

	// 5. Assign with moving std::string - assigns a string from another string using move semantics.
	std::cout << "Assign with moving std::string:\n";
	std::string str6 = "str6";
	std::cout << "str6 = [" << str6 << "]\n";
	std::cout << "str5 = [" << str5 << "]\n\n";
	str6 = std::move(str5);
	std::cout << "str6 = [" << str6 << "]\n";
	std::cout << "str5 = [" << str5 << "]\n\n";

	system("pause");
	system("cls");

}
void Method_assign()
{
	std::cout << "---------------- Method assign ----------------\n\n";

	// operator= can have onle 1 parameter, and that`s bad.
	// So you can use 'assign' method for more possibilities.
	// This method has 8 overloads. Here are 7 of them.

	std::string str1;
	std::cout << "str1 = [" << str1 << "]\n";

	/// 1
	str1.assign(3, '!');
	std::cout << "str1 = [" << str1 << "]\n";
	/// 2
	str1.assign("Odessa");
	std::cout << "str1 = [" << str1 << "]\n";
	/// 3
	str1.assign("Hello World", 5);
	std::cout << "str1 = [" << str1 << "]\n";
	/// 4
	std::string str2 = "By the Black Sea";
	str1.assign(str2, 7, 9);
	std::cout << "str1 = [" << str1 << "]\n";
	/// 5
	str1.assign(str2);
	std::cout << "str1 = [" << str1 << "]\n";
	/// 6
	str1.assign({ 'O', 'd', 'e', 's', 's', 'a'});
	std::cout << "str1 = [" << str1 << "]\n";
	/// 7
	str1.assign(std::move(str2));
	std::cout << "str1 = [" << str1 << "]\n";
	std::cout << "str2 = [" << str2 << "]\n";

	system("pause");
	system("cls");
}
void Method_get_allocator()
{
	// std::string is being constructed with associated allocator.
	// (3th template parameter). You can get this allocator by invoking this method

	std::string str;
	std::allocator<char> alloc = str.get_allocator();
}
void ElementAccess()
{
	std::cout << "---------------- Element Access ----------------\n\n";

	// Method 'at'  return character by index and throws 'std::out_of_range' 
	// expretion if index is incorrect.
	std::cout << "Method 'at()':\n";
	std::string str1 = "Hello";
	std::cout << "str1 = [";
	for (size_t i = 0; i < str1.length(); i++)
	{
		std::cout << str1.at(i);
	}
	std::cout << "]\n\n";

	// operator[] return character by index and doesn`t throw exception.
	std::cout << "Method 'operator[]':\n";
	std::string str2 = "Goodbye";
	std::cout << "str2 = [";
	for (size_t i = 0; i < str2.length(); i++)
	{
		std::cout << str2[i];
	}
	std::cout << "]\n\n";

	// Method 'front' return reference ro first element.
	// Method 'back' return reference to last element.
	std::cout << "Method 'front()' and 'back()':\n";
	std::string str3 = "abc";
	std::cout << "front() = [" << str3.front() << "]\n";
	std::cout << "back() = [" << str3.back() << "]\n\n";

	// Method 'data' and 'c_str' return internal character array address.
	std::cout << "Method 'data()' and 'c_str()':\n";
	const char* data = str3.data();
	std::cout << "ptr1 = [" << data << "]\n";
	const char* c_str = str3.c_str();
	std::cout << "ptr2 = [" << c_str << "]\n\n";

	system("pause");
	system("cls");
}
void Iterators()
{
	std::cout << "---------------- Iterators ----------------\n\n";
	
	// To work with iterators, std::string has some methods.
	// 'begin' and 'end' for working with variable character.
	std::string str = "Ti amo moltissimo";
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		*it = std::toupper(*it);
	}

	// 'cbegin' and 'cend' for working with constant character.
	std::cout << "\t"<<"str1 = [";
	for (std::string::const_iterator it = str.cbegin(); it != str.cend(); it++)
	{
		std::cout << *it;
	}
	std::cout << "]\n\n";
	
	// 'rbegin' and 'rend' for working with variable character for the end.
	std::string str2 = "Te quiero muchisimo";
	for (std::string::reverse_iterator it = str2.rbegin(); it != str2.rend(); it++)
	{
		*it = std::toupper(*it);
	}

	// 'crbegin' and 'crend' for working with constant character for the end.
	std::cout << "\t" << "str2 = [";
	for (std::string::const_reverse_iterator it = str2.crbegin(); it != str2.crend(); it++)
	{
		std::cout << *it;
	}
	std::cout << "]\n\n";

	system("pause");
	system("cls");
}
void Capacity()
{
	std::cout << "------------------ Capacity ------------------\n\n";

	// Method 'empty' checks if string has no characters and return true, if it`s true.

	std::cout << "Method 'empty':\n";
	std::string str1;
	std::string str2 = "Some text";
	if (str1.empty())
		std::cout << "str1 is empty.\n\n";
	else
		std::cout << "str2 is empty.\n\n";

	// Methods 'size' and 'length' return amount of character in string.
	// (without '\0' character)
	std::cout << "Methods 'size' and 'length':\n";
	std::cout << "str1 size = " << str1.size() << std::endl;
	std::cout << "str2 size = " << str2.size() << std::endl;
	std::cout << "str1 length = " << str1.length() << std::endl;
	std::cout << "str2 length = " << str2.length() << std::endl;

	// Method 'max_size' return maximum amount of characters that string can hold in system
	// (not including '\0' character)
	std::cout << "Method 'max_size':\n";
	std::cout << "In my system string can hold " << str1.max_size() << " characters.\n\n";

	// string has it`s own size and capacity. 
	// Size is amount of characters in string.
	// Capacity is amount of characters that string can hold without reallocation.
	std::cout << "Method 'capacity':\n";
	str1 = "World";
	std::cout << "str1 size = " << str1.size() << std::endl;
	std::cout << "str1 capacity = " << str1.capacity() << std::endl;
	str1 += "Goodbye, madam!";
	std::cout << "str1 size = " << str1.size() << std::endl;
	std::cout << "str1 capacity = " << str1.capacity() << "\n\n";

	// Method 'reserve' expanses memeory for string to storegw more characters.
	std::cout << "Method 'reserve':\n";
	std::string str3;
	std::cout << "str3 length = " << str3.length() << std::endl;
	std::cout << "str3 capacity = " << str3.capacity() << std::endl;
	str3 = "Hello";
	std::cout << "str3 length = " << str3.length() << std::endl;
	std::cout << "str3 capacity = " << str3.capacity() << std::endl;
	str3.reserve(100);
	std::cout << "str3 length = " << str3.length() << std::endl;
	std::cout << "str3 capacity = " << str3.capacity() << "\n\n";

	// Method 'shrink_to_fit' try to shink all extra memory for string
	std::cout << "Method 'shrink_to_fit':\n";
	std::string str4 = "Hello";
	str4.reserve(500);
	std::cout << "str4 length = " << str4.length() << std::endl;
	std::cout << "str4 capacity = " << str4.capacity() << std::endl;
	str4.shrink_to_fit();
	std::cout << "str4 length = " << str4.length() << std::endl;
	std::cout << "str4 capacity = " << str4.capacity() << std::endl;

	system("pause");
	system("cls");
}
void Operations()
{
	std::cout << "---------------- Operations ----------------\n\n";
	// Method 'clear' removes all characters from string.
	// But allocated memory still exists.
	std::cout << "Method 'clear':\n";
	std::string str1 = "Hello World";
	std::cout << "str1 =	" << str1 << "\n";
	std::cout << "str1 length = " << str1.length() << "\n";
	std::cout << "str1 capacity = " << str1.capacity() << "\n";

	str1.clear();
	std::cout << "str1 =	" << str1 << "\n";
	std::cout << "str1 length = " << str1.length() << "\n";
	std::cout << "str1 capacity = " << str1.capacity() << "\n\n";

	// Method 'insert' inserts characters into string.
	// May throw 'std::out_of_range' or 'std::length_error' exceptions.
	// some cases (if index is incorrect and ect.).
	// Method has 9 overloads. 4 of them work with iterators.
	std::cout << "Method 'insert':\n";
	str1 = "Hello World";					
	str1.insert(6, 3, '!');								// 1. insert(offset, count, character)
	std::cout << "str1 = [" << str1 << "]\n";
	str1.insert(2, "NNN");								// 2. insert(offset, C-string)
	std::cout << "str1 = [" << str1 << "]\n";
	str1.insert(8, "abcdef", 2);						// 3. insert(offset, C-string, count)
	std::cout << "str1 = [" << str1 << "]\n";
	str1.insert(15, std::string("Some string"), 5, 6);	// 4. insert(offset, std::string, offset, count)
	std::cout << "str1 = [" << str1 << "]\n";
	str1.insert(3,std::string("GOOD WORK"));				// 5. insert(iterator, std::string)
	std::cout << "str1 = [" << str1 << "]\n\n";

	// Method 'erase' removes specified characters from the string.
	// Method has 4 overloads. 2 of them work with iterators.
	// Other 2 work with simplier parameters, so let`s examine them
	std::cout << "Method 'erase':\n";
	std::string str2 = "My name is Demien";
	str2.erase(10);									// 1. erase(offset)
	std::cout << "str2 = [" << str2 << "]\n\n";
	str2.erase(0,3);								// 2. erase(offset, count)
	std::cout << "str2 = [" << str2 << "]\n\n";
	
	// Method 'push_back' appends character to the end of the string.
	std::cout << "Method 'push_back':\n";
	std::string str3 = "abc";
	str3.push_back('!');
	std::cout << "str3 = [" << str3 << "]\n\n";

	// Method 'pop_back' removes character from the end of string.
	std::cout << "Method 'pop_back':\n";
	str3.pop_back();
	std::cout << "str3 = [" << str3 << "]\n+\n";

	// Operator += append additional characters to the end of string.
	std::cout << "Operator +=:\n";
	std::string str4 = "My";
	str4 += " string";								// const char*
	str4 += ' ';									// char
	str4 += std::string(" with additional");		// std::string
	str4 += {'c', 'h', 'a', 'r', 's'};				// std::initializer_list
	std::cout << "str4 = [" << str4 << "]\n\n";

	// Operator += has only 1 parameter. Dut method 'append' is more complex.
	// It has 8 overloads.
	std::cout << "Method 'append':\n";
	std::string str5;
	str5.append(3, '!');							// count, char
	str5.append("Hello");							// const char*
	str5.append(" World", 5);						// const char*, count
	str5.append(std::string(" with append"));		// std::string
	str5.append(std::string(" and more"), 4, 4);	// std::string, offset, count
	str5.append({ 'c', 'h', 'a', 'r', 's' });			// std::initializer_list
	std::cout << "str5 = [" << str5 << "]\n\n";

	//Method 'compare' compares two character sequences.
	std::cout << "Method 'compare':\n";
	std::string str6 = "hello", str7 = "HELLO";
	int compareResult = str6.compare(str7);
	std::cout << "Compare Result = " << compareResult << "\n\n";

	// Method 'replace' replased the part of string. Has 11 overloads.
	std::cout << "Method 'replace':\n";
	std::string str8 = "Hello World";
	str8.replace(6, 5, "Universe");						// offset, count, const char*
	std::cout << "str8 = [" << str8 << "]\n";

	// Method 'substr' returns substring of the string.
	std::cout << "Method 'substr':\n";
	std::string str9 = str8.substr(6, 8);					// offset, count
	std::cout << "str9 = [" << str9 << "]\n\n";

	// Method 'cope' returns copies a substring to character string pointed to by dest
	std::cout << "Method 'copy':\n";
	std::string str10 = "abcdef";
	char str11[100] = "";
	str10.copy(str11, 3, 2);								// dest, count, offset
	std::cout << "str11 = [" << str11 << "]\n\n";

	//Method 'resize' resizes the string to contain count characters.
	std::cout << "Method 'resize':\n";
	std::string str12 = "abcdefg";
	std::cout << "str12 = [" << str12 << "]\n";
	std::cout << "str12 size = " << str12.size() << "\n";
	str12.resize(20);
	std::cout << "str12 = [" << str12 << "]\n";
	std::cout << "str12 size = " << str12.size() << "\n";
	str12.resize(3);
	std::cout << "str12 = [" << str12 << "]\n";
	std::cout << "str12 size = " << str12.size() << "\n\n";
	str12.resize(25, '!');
	std::cout << "str12 = [" << str12 << "]\n";
	std::cout << "str12 size = " << str12.size() << "\n\n";

	// Method 'swap' exchanges the contents of the string with those of other.
	std::cout << "Method 'swap':\n";
	std::string str13 = "Text #1", str14 = "Text #2";
	std::cout << "str13 = [" << str13 << "]\n";
	std::cout << "str14 = [" << str14 << "]\n";
	str13.swap(str14);
	std::cout << "str13 = [" << str13 << "]\n";
	std::cout << "str14 = [" << str14 << "]\n\n";

	system("pause");
	system("cls");
}
void Search()
{
	std::cout << "---------------- Search ----------------\n\n";
	// std::string has 6 methods for searching characters in string.
	// All methods return position to the first found character.
	// 
	// 1. Method 'find' - find character or substring in the string.
	// 
	// 2. Method 'rfind' - does the same as 'find', but serches from 
	//						the end  to the biginning of the string.
	//
	// 3. find_first_of() - finds the first character equal to one 
	//			  of the characters in the given character sequence.
	//
	// 4. find_first_not_of() - finds the first character equal to 
	//	   	none of the characters in the given character sequence.
	//
	// 5. find_last_of() - finds the last character equal to one of 
	// characters in the given character sequence.
	// 
	// 6. find_last_not_of() - finds the last character equal to none
	//							of the characters
	
	std::string str = "Here is some text with different letters. Let's work with it";
	size_t foundPosition;

	foundPosition = str.find("text");

	if (foundPosition != std::string::npos)
		std::cout << "Our string has word 'text' in position" << foundPosition << std::endl; 
	
	foundPosition = str.rfind('w');

	if (foundPosition != std::string::npos)
		std::cout << "Our string has a letter 'w' in LAST position" << foundPosition << std::endl;

	foundPosition = str.find_first_of("qyzt");
	if (foundPosition != std::string::npos)
	{
		std::cout << "From sequence 'qyzt' our text has first letter" << str[foundPosition];
		std::cout << " in position" << foundPosition << std::endl;
	}

	foundPosition = str.find_first_not_of("abcdef");
	if (foundPosition != std::string::npos)
	{
		std::cout << "From sequence 'abcdef our text has non of its characters ";
		std::cout << " first letter " << str[foundPosition]; 
		std::cout << " in position " << foundPosition << std::endl;
	}

	foundPosition = str.find_last_of("qyzt");
	if (foundPosition != std::string::npos)
	{
		std::cout << "From sequence 'qyzt' our text has last letter " << str[foundPosition];
		std::cout << " in position " << foundPosition << std::endl;
	}

	foundPosition = str.find_last_not_of("abcdef");
	if (foundPosition != std::string::npos)
	{
		std::cout << "From sequence 'abcdef our text has non of its characters ";
		std::cout << " last letter " << str[foundPosition];
		std::cout << " in position " << foundPosition << std::endl;
	}

	system("pause");
	system("cls");
}
void NonMemberFunctions()
{
	std::cout << "------------------------ NonMemberFunctions ------------------------\n\n";
	
	// There is a lot of global overloading operators for worl with string.
	
	// operator + combines two strings and return new sring.

	std::cout << "operator+:" << "\n";
	std::string name = "Demien", surname = "Blogan";
	std::string fullname = name + surname;
	std::cout << "My full name is " << fullname << "\n\n";

	// There's a lot of comparison operators. Almost all of them are removed 
	// in C++20. So I'll show you the only one operator==. 
	// C++20 adds new <=> operator, but I'll explain you this operator in another lesson. 
	std::cout << "operator==:" << "\n";
	if (name == surname)
		std::cout << "Hey, my name and surname are equal!\n";
	else
			std::cout << "I am a normal person!\n";
	// For writing template code there is std::swap function specialization for std::string. 
	std::cout << "Function 'swap()':" << "\n";
	std::swap(name, surname);
	std::cout << "Oops! Now I'm " << name << " " << surname << "\n\n";

	// All this time I've been using operator<< to show string's content. 
	// But how to enter content into string from keybord? Use operator>>. 
	// WARNING: operator>> reads while sees character. If you enter space-character (whitespace, tab, enter).
	//			input will be interupt.
	std::cout << "operator>>:" << "\n";
	std::string str1 = "I am alive!";
	std::cout << "Enter something: ";
	std::cin >> str1;
	std::cout << "str1 = " << str1 << "\n\n";

	// But how to enter more than one word? Use function std::getline(). 
	// It has 4 overloads. 
	// 1. std::getline(input_object&, string_object) 
	// 2. std::getline(input_object&, string_object, delimeter) 
	// 3. std::getline(input_object&&, string_object) 
	// 4. template std::getline(input_object&, string_object, delimeter) 
	//If you use version without delimter, getline will read characters untill reaches An. 
	// Otherwise until reaches delimeter. 
	// WARNING: Last operation with operator>> left '\n' character in the input buffer.
	//			If you don't remove this character, std::getline() will stop immediately! 
	// So I use special method of std::cin object to remove it. 
	std::cout << "Function 'getline()':" << "\n";
	std::cin.ignore();
	std::cout << "Now enter everything and hit <Enter>: ";
	std::getline(std::cin, str1);
	std::cout << "str1 = " << str1 << std::endl;
	std::cout << "Now enter everything (Stop character #): ";
	std::getline(std::cin, str1, '#');
	std::cout << "str1 = " << str1 << "\n\n";
	// WARNING: std::getline() removes in character from the input buffer.

	//Class std::istream has its own 'getline' method to work with C-strings. But C-strings 
	// can't resize itself, so we need to use 'size' parameter to enter something in this stirng. 
	std::cout << "Method 'getline()':" << "\n";
	char cString[100];
	std::cout << "Enter something in C-string: ";
	std::cin.getline(cString, 100); // Read all characters until reach '\n' character or 99 characters 
	std::cout << "cString = " << cString << "\n\n";
	// More carefully we'll examine class std::istream in future lessons.

	// You can convert string into numeric values using special functions: 
	// stoi string to int type 
	// stol string to long type 
	// stoll string to long long type 
	// stoul string to unsigned long type 
	// stoull-string to unsigned long long type 
	// stof string to float type 
	// stod string to double type 
	// stold string to long double type 
	// A lot of these functions have overloads but I'll show you common example. 
	// Integer conversions have second parameter basement. Default value for it is 18. 
	// // If function can't convert string it throws std::invalid_argument or std::out_of_range. 
	std::cout << "Function 'stox()':" << "\n";
	std::string strNumber = "123";
	int number = std::stoi(strNumber);
	std::cout << "Here's my number:" << number << "\n\n"; 

	// To convert all these types into string, you can use only one function 'to_string". 
	// This function has 9 overloads. I'll show only one. 
	std::cout << "Function 'to_string()':" << "\n";
	long number2 = 93L;
	std::string strNumber2 = std::to_string(93L);
	std::cout << "Here's my string: " << strNumber2 << "\n\n";

	system("pause");
	system("cls");
}
