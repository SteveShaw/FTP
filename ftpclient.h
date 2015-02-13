#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <QByteArray>
#include "ftpclient_global.h"

class FTPClientImpl;

class FTPCLIENTSHARED_EXPORT FTPClient
{

public:
	FTPClient(const char* hostname, const char *user, const char *pwd);
	virtual ~FTPClient();

	void LogIn();

	void Close();

	int Upload(const char* remote_path, const char* local_path);

private:
	FTPClientImpl* m_Impl;
	QByteArray m_host;
	QByteArray m_user;
	QByteArray m_pwd;

};

#endif // FTPCLIENT_H
