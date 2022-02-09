#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

class String
{
private:
	int size;
	char* str;

public:
	
	String()
	{
		this->size = 0;
		this->str = new char[this->size + 1];
		this->str[0] = '\0';
	}

	String(const char* str)
	{
		this->size = strlen(str);
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++)
			this->str[i] = str[i];

		this->str[this->size] = '\0';
	}

	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++)
			this->str[i] = other.str[i];

		this->str[this->size] = '\0';
	}

	const String& operator = (const String& other)
	{
		if (this->str != nullptr)
			delete[] this->str;

		this->size = other.size;
		this->str = new char[this->size + 1];

		for (int i = 0; i < this->size; i++)
			this->str[i] = other.str[i];

		this->str[this->size] = '\0';

		return *this;
	}

	bool operator == (const String& other)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->str[i] != other.str[i])
				return false;
		}

		return true;
	}

	bool operator != (const String& other)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->str[i] != other.str[i])
				return true;
		}

		return false;
	}

	String operator + (const String& other)
	{
		String string;

		string.size = this->size + other.size + 1;
		string.str = new char[string.size];
		
		for (int i = 0; i < this->size; i++)
		{
			string.str[i] = this->str[i];
		}

		int j = 0;
		for (int i = this->size; i < other.size + this->size; i++)
		{
			string.str[i] = other.str[j];
			j++;
		}

		string.str[other.size + this->size] = '\0';

		return string;
	}

	~String()
	{
		delete[] this->str;
	}

	void print()
	{
		std::cout << this->str << std::endl;
	}
};

#endif
