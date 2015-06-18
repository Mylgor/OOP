#include "stdafx.h"
#include "Student.h"

bool IsName(std::string const &name)
{
	for each (char elem in name)
	{
		if (!((elem >= 'a' && elem <= 'z') || (elem >= 'A' && elem <= 'Z')))
		{
			return false;
		}
	}
	return true;
}

bool CheckNames(std::string const &name, std::string const &surname, std::string const &patronymic)
{
	if (name == "" || surname == "")
		return false;
	if (!IsName(name) || !IsName(surname) || !IsName(patronymic))
		return false;
	return true;
}

bool CheckAge(int const &age)
{
	if (age < 14 || age > 60)
		return false;
	return true;
}

CStudent::CStudent(std::string const &name, std::string const &surname, std::string const &patronymic, int const &age)
	: m_name(name), m_surname(surname), m_patronymic(patronymic), m_age(age)
{
	if (!CheckNames(name, surname, patronymic))
	{
		throw std::invalid_argument("incorrect data (name, surname or patronymic)");
	}
	if (!CheckAge(age))
	{
		throw std::out_of_range("incorrect age (must be >= 14 and <= 60)");
	}
}

int CStudent::GetAge() const
{
	return m_age;
}

std::string CStudent::GetName() const
{
	return m_name;
}

std::string CStudent::GetSurname() const
{
	return m_surname;
}

std::string CStudent::GetPatronymic() const
{
	return m_patronymic;
}

void CStudent::Rename(std::string const &name, std::string const &surname, std::string const &patronymic)
{
	if (!CheckNames(name, surname, patronymic))
	{
		throw std::invalid_argument("incorrect data (name, surname or patronymic)");
	}
	m_name = name; m_surname = surname, m_patronymic = patronymic;
}

void CStudent::SetAge(int const &age)
{
	if (!CheckAge(age))
	{
		throw std::out_of_range("incorrect age (must be >= 14 and <= 60)");
	}
	if (age < m_age)
	{
		throw std::domain_error("age must be equally or great that previous age");
	}
	m_age = age;
}