#include "stdafx.h"
#include "CFile.h"


CCFile::CCFile()
{
	m_file = NULL;
	m_positionOnFile = 0;
}


CCFile::~CCFile()
{
	if (IsOpened())
	{
		fclose(m_file);
		m_file = NULL;
	}
}

bool CCFile::Open(char *fileName, char *type)
{
	if (IsOpened())
	{
		Close();
	}
	fopen_s(&m_file, fileName, type);
	if (m_file == NULL)
	{
		return false;
	}
	return true;
}

void CCFile::Close()
{
	if (IsOpened())
	{
		fclose(m_file);
		m_file = NULL;
	}
}

bool CCFile::IsOpened() const
{
	return (!(m_file == NULL));
}

bool CCFile::IsEndOfFile()
{
	return (m_positionOnFile == GetLenght());
}

int CCFile::GetChar()
{
	if (!(IsOpened()))
	{
		return FILE_ERROR;
	}
	if (IsEndOfFile())
	{
		return EOF;
	}
	m_symbol = fgetc(m_file);
	m_positionOnFile++;
	if (m_symbol == EOF)
	{
		m_positionOnFile--;
		return FILE_ERROR;
	}
	return m_symbol;
}

bool CCFile::PutChar(char symbol)
{
	if (!(IsOpened()))
	{
		return false;
	}
	int checkVal = fprintf(m_file, "%c", symbol);
	if (checkVal < 0)
	{
		return false;
	}
	return true;
}

size_t CCFile::GetLenght()
{
	if (IsOpened())
	{
		fseek(m_file, 0, SEEK_END);
		size_t sizeFile = ftell(m_file);
		fseek(m_file, m_positionOnFile, SEEK_SET);
		return sizeFile;
	}
	return EOF;
}

bool CCFile::Seek(long int &numbOfByte)
{
	if (!IsOpened())
	{
		return false;
	}
	
	return fseek(m_file, numbOfByte, SEEK_SET) == 0;
}

long int CCFile::GetPosition() const
{
	if (!IsOpened())
	{
		return EOF;
	}
	return m_positionOnFile;
}

size_t CCFile::Write(char const *str)
{
	if (!IsOpened())
	{
		return EOF;
	}
	size_t comparValue1 = strlen(str);
	size_t comparValue2 = fwrite(str, 1, comparValue1, m_file);
	if (comparValue1 != comparValue2 || IsEndOfFile())
	{
		return EOF;
	}
	return comparValue1;
}

size_t CCFile::Read(char *str)
{
	if (!IsOpened())
	{
		return EOF;
	}
	size_t compareValue1 = strlen(str);
	size_t compareValue2 = 0;
	compareValue2 = fread(str, compareValue1, 1, m_file);
	if (compareValue1 != compareValue2)
	{
		return EOF;
	}
	return compareValue1;
}