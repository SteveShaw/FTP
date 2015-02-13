#ifndef FTPCLIENTIMPL_H
#define FTPCLIENTIMPL_H

#include <Poco/Net/FTPClientSession.h>


class FTPClientImpl
{
public:
	explicit FTPClientImpl(const char *hostname);
	~FTPClientImpl();

	void LogIn(const char* user, const char* pwd);
	int UploadFile(const char* remote_path, const char* local_path);
	void CloseConnection();

private:
	Poco::Net::FTPClientSession* m_ftp;
};

#endif // FTPCLIENTIMPL_H
