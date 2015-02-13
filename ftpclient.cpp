#include "ftpclient.h"
#include "ftpclientimpl.h"

FTPClient::FTPClient(const char *hostname, const char* user, const char* pwd)
	:m_Impl(new FTPClientImpl(hostname))
	,m_user(user)
	,m_pwd(pwd)
{

}

FTPClient::~FTPClient()
{
	delete m_Impl;
}

void FTPClient::LogIn()
{
	m_Impl->LogIn(m_user.data(), m_pwd.data());
}

void FTPClient::Close()
{
	m_Impl->CloseConnection();
}

int FTPClient::Upload(const char *remote_path, const char *local_path)
{
	return m_Impl->UploadFile(remote_path,local_path);
}
