#pragma once

#include <string>

class CStudent
{
public:
	CStudent(std::string const &name, std::string const &surname, std::string const &patronymic, int const &age);

	std::string GetName() const;
	std::string GetSurname() const;
	std::string GetPatronymic() const;
	int GetAge() const;

	void Rename(std::string const &name, std::string const &surname, std::string const &patronymic);
	void SetAge(int const &age);

private:
	std::string m_name, m_surname, m_patronymic;
	int m_age;
};

