#pragma once

class BackUp
{
public:

	void Save(const char * sFileName, void * pData, int nBytes, int * ErrCode);
	void Read(const char * sFileName, int * pReadedBytes, int * ErrCode);

private:


};
