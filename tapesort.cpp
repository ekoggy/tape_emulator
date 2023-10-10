#include "TapeSort.h"

TapeSort::TapeSort() {

}
/*

#include "my_string.h"


//CONSTRUCTORS
MyString::MyString()
{
	this->len_ = 0;
	this->volume_ = 0;
	this->string_ = nullptr;
}

MyString::MyString(const char* str) :MyString(str,strlen(str))
{ }

MyString::MyString(const char* str, int size) :MyString(size,'\0')
{
	strncpy(this->string_, str, size);
}

MyString::MyString(int amount,char symbol)
{

	this->len_ = amount;
	this->volume_ = amount + 1;
	this->string_ = new char[amount + 1];
	for (int i = 0; i < amount; i++)
		this->string_[i] = symbol;
	this->string_[amount] = '\0';
}

MyString::MyString(const  MyString& other) :MyString(other.string_, strlen(other.string_))
{ }

MyString::MyString(std::string str) :MyString(str.data(),str.length())
{
}

MyString::MyString(MyString&& other)
{
	this->len_ = other.len_;
	this->volume_ = other.volume_;
	this->string_ = other.string_;
	other.string_ = nullptr;
}

//OPERATOR+
MyString MyString::operator+(const MyString& other) const
{
	MyString temp(this->len_ + other.len_, '\0');
	strncpy(temp.string_, this->string_, this->len_);
	strncat(temp.string_, other.string_, other.len_);
	return temp;
}

MyString MyString::operator+(const char*str)const
{
	MyString temp(str,strlen(str));

	return this->operator+(temp);
}

MyString MyString::operator+(const std::string str)const
{
	MyString temp(str);
	return this->operator+(temp);
}

//OPERATOR=
void MyString::operator=(const MyString& other)
{
	this->operator=(other.c_str());
}

void MyString::operator=(const char* str)
{
	int l = strlen(str);
	this->len_ = l;
	if (this->volume_ < l+1)
		this->enlarge_to_fit();
	this->string_[0] = '\0';
	strncpy(this->string_, str, l);
}

void MyString::operator=(const std::string str)
{
this->operator=(str.c_str());
}

void MyString::operator=(char symbol)
{
	char temp[2] = { '\0' };
	temp[0] = symbol;
	this->operator=(temp);
}

//OPERATOR+=
void MyString::operator+=(const MyString& other)
{
	this->len_ += other.len_;
	this->enlarge_to_fit();
	if (this->empty() == 0)
		strncat(this->string_, other.string_, other.len_);
	else
		strncpy(this->string_, other.string_, other.len_);
}

void MyString::operator+=(const char* str)
{
	MyString temp(str, strlen(str));

	return this->operator+=(temp);
}

void MyString::operator+=(const std::string str)
{
	MyString temp(str);
	return this->operator+=(temp);
}

void MyString::operator+=(const char symbol)
{
	MyString temp(1, symbol);
	return this->operator+=(temp);
}

//OPERATOR [](int)
char MyString::operator[](int position)const
{
	if (position < this->len_ && position >= 0)
		return this->string_[position];
	else
		return '\0';
}

//LOGICAL OPERATORS (==,<=,>=,!=,>,<)
bool MyString::operator==(const MyString& other) const
{
	if (!strcmp(this->string_, other.string_))
		return true;
	return false;
}

bool MyString::operator<=(const MyString& other) const
{
	if (strcmp(this->string_, other.string_)<=0)
		return true;
	return false;
}

bool MyString::operator>=(const MyString& other) const
{
	if (strcmp(this->string_, other.string_)>=0)
		return true;
	return false;
}

bool MyString::operator!=(const MyString& other) const
{
	if (strcmp(this->string_, other.string_))
		return true;
	return false;
}

bool MyString::operator>(const MyString& other) const
{
	if (strcmp(this->string_, other.string_)>0)
		return true;
	return false;
}

bool MyString::operator<(const MyString& other) const
{
	if (strcmp(this->string_, other.string_)<0)
		return true;
	return false;
}

//OTHER OPERATORS
const char* MyString::c_str()const
{
	return this->string_;
}

const char* MyString::data()const
{

	return this->c_str();
}

int MyString::lenght()const
{
	return this->size();
}
int MyString::size()const
{
	return this->len_;
}

bool MyString::empty()const
{
	if (this->string_ == nullptr|| this->string_[0] == '\0')
		return true;
	else
		return false;
}

int MyString::capacity()const
{
	return this->volume_;
}
void MyString::shrink_to_fit()
{
	if (this->volume_ == this->len_ + 1)
		return;
	char* temp = nullptr;
	temp = new char[this->len_ + 1];
	memset(temp, '\0', this->len_ + 1);

	if (this->volume_!=0)
	{
		strncpy(temp, this->string_, this->len_);
		temp[this->len_] = '\0';
		delete[] this->string_;
	}

	this->volume_ = this->len_ + 1;
	this->string_ = temp;

	delete[] temp;
}
void MyString::enlarge_to_fit()
{
	if (this->volume_ >= this->len_ + 1)
		return;
	char* temp = nullptr;
	temp = new char[this->len_ + 1];
	memset(temp, '\0', this->len_ + 1);

	if (this->volume_ != 0)
	{
		strncpy(temp, this->string_, this->len_);
		temp[this->len_] = '\0';
		delete[] this->string_;
	}

	this->volume_ = this->len_ + 1;
	this->string_ = temp;
	delete[] temp;
}

void MyString::clear()
{
	if (this->len_ != 0)
	{
		this[0] = '\0';
		this->len_ = 0;
	}
}

//OPERATORS >>,<<
std::ostream& operator<< (std::ostream& out, const MyString& mystring)
{
	if (mystring.string_ != nullptr)
		out << mystring.string_ \*<< " " << mystring.len << " " << mystring.volume*\;
	else
		out << '\0';
		return out;
}

std::istream& operator>> (std::istream& in, MyString& mystring)
{
	char temp;
	bool key = false;
	mystring = '\0';
	temp = in.get();
	while (in && temp != '\n')
	{
		mystring += temp;
		temp = in.get();
	}
	return in;
}

//INSERT
void MyString::insert(int index, int count, char symbol)
{
	char* str = new char[count + 1];
	for (int i = 0; i < count; ++i)
		str[i] = symbol;
	str[count] = '\0';

	this->insert(index, str, count);

	delete[] str;
}

void MyString::insert(int index, const char* str)
{
	this->insert(index, str, strlen(str));
}

void MyString::insert(int index, const char* str, int count)
{
	this->len_ += count;
	this->enlarge_to_fit();
	char* temp = new char[this->len_ - index + 1];
	strncpy(temp, this->string_ + index, this->len_ - index);
	temp[this->len_ - index + 1] = '\0';
	this->string_[index] = '\0';
	strncat(this->string_, str, count);
	this->string_[index + count] = '\0';
	strncat(this->string_, temp, strlen(temp));
	delete[] temp;
}

void MyString::insert(int index, std::string str)
{
	this->insert(index, str.data(), str.size());
}

void MyString::insert(int index, std::string str, int count)
{
	this->insert(index, str.data(), count);
}

//ERASE
void MyString::erase(int index, int count)
{
	if (count < 1 || index < 0 || index > this->len_)
		return;

	char* temp = this->string_ + index + count;

	this->string_[index] = '\0';
	this->len_ -= count;
	strncat(this->string_, temp, strlen(temp));
}

//APPEND
void MyString::append(int amount, char symbol)
{
	MyString temp(amount, symbol);
	*this += temp;
}

void MyString::append(const char* str)
{
	this->append(str, 0, strlen(str));
}

void MyString::append(const char* str, int index, int amount)
{
	MyString temp(str + index, amount);
	*this += temp;
}

void MyString::append(std::string str)
{
	this->append(str.data(), 0, str.length());
}

void MyString::append(std::string str, int index, int amount)
{
	this->append(str.data(), index, amount);
}

//REPLACE
void MyString::replace(int index, int count, const char* str)
{
	this->erase(index, count);
	this->insert(index, str, strlen(str));
}

void MyString::replace(int index, int count, std::string str)
{
	this->replace(index, count, str.data());
}

//SUBSTR
MyString MyString::substr(int index)const
{
	return this->substr(index, this->len_ - index);
}

MyString MyString::substr(int index, int count)const
{
	if (this->empty())
		return "nullstr";
	MyString a(this->string_ + index, count);
	return a;
}

//FIND
int MyString::find(const char* str)const
{
	return this->find(str, 0);
}

int MyString::find(const char* str, int index)const
{
	int count = strlen(str);
	for (int i = index; i < this->len_; ++i)
	{
		if (this->string_[i] == str[0])
		{
			int j = i, k = 0;
			for (; j - i < count; ++j)
			{
				if (this->string_[j] == str[k])
					k++;
				else
					break;
			}
			if (j - i == count)
				return i;
		}
	}
	return -1;
}

int MyString::find(std::string str)const
{
	return this->find(str.data(), 0);
}

int MyString::find(std::string str, int index)const
{
	return this->find(str.data(), index);
}

*/