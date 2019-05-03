//*****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();

	friend ostream & operator << (ostream & out, const Student & stu);

	bool operator < (const Student & rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student & rhs) const;
	bool operator > (int value) const;
	bool operator == (const Student & rhs) const;
	bool operator == (int value) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (int value) const;
	bool operator != (const Student & rhs) const;
	bool operator != (int value) const;

	int operator % (int value) const;

	Student & operator = (int value);
};

//****************************************************************************************************

Student::Student()
{
	id = 0;
}

//****************************************************************************************************

ostream & operator <<(ostream & out, const Student & stu)
{
	out << stu.id << "\t"
		<< stu.name << "\t"
		<< stu.citystate << "\t"
		<< stu.phone << "\t"
		<< stu.gender << "\t"
		<< stu.year << "\t"
		<< stu.credits << "\t"
		<< stu.gpa << "\t"
		<< stu.major << "\t"
		<< endl;

	return out;
}

//****************************************************************************************************

bool Student ::operator < (const Student & rhs) const
{
	return (this->id < rhs.id);
}

//****************************************************************************************************

bool Student ::operator < (int value) const
{
	return (this->id < value);
}

//****************************************************************************************************

bool Student ::operator > (const Student & rhs) const
{
	return (this->id > rhs.id);
}

//****************************************************************************************************

bool Student ::operator > (int value) const
{
	return (this->id > value);
}

//****************************************************************************************************

bool Student ::operator == (const Student & rhs) const
{
	return (this->id == rhs.id);
}

//****************************************************************************************************

bool Student ::operator == (int value) const
{
	return (this->id == value);
}

//****************************************************************************************************

bool Student ::operator <= (const Student & rhs) const
{
	return (this->id <= rhs.id);
}

//****************************************************************************************************

bool Student ::operator <= (int value) const
{
	return (this->id <= value);
}

//****************************************************************************************************

bool Student ::operator >= (const Student & rhs) const
{
	return (this->id >= rhs.id);
}

//****************************************************************************************************

bool Student ::operator >= (int value) const
{
	return (this->id >= value);
}

//****************************************************************************************************

bool Student ::operator != (const Student & rhs) const
{
	return (this->id != rhs.id);
}

//****************************************************************************************************

bool Student ::operator != (int value) const
{
	return (this->id != value);
}

//****************************************************************************************************

int Student ::operator % (int value) const
{
	return (this->id % value);
}

//****************************************************************************************************

Student & Student ::operator = (int value)
{
	this->id = value;
	return *this;
}

//****************************************************************************************************

#endif
