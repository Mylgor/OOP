#pragma once
class CCFile
{
public:
	CCFile();
	~CCFile();

	bool Open(char *fileName, char *type); 
	void Close();
	bool IsOpened() const;
	bool IsEndOfFile();
	int GetChar();
	bool PutChar(char symbol);
	size_t GetLenght();
	bool Seek(long int &numbOfByte);
	long int GetPosition() const;
	size_t Write(char const *str);
	size_t Read(char *str);

private:
	enum returnValues { FILE_ERROR };
	
	FILE *m_file;
	int m_symbol;
	
	long int m_positionOnFile;
};

