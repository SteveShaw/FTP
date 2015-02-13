#include "ftpclientimpl.h"
#include <Poco/StreamCopier.h>
#include <fstream>

FTPClientImpl::FTPClientImpl(const char* hostname)
	:m_ftp(new Poco::Net::FTPClientSession(hostname))
{

}

FTPClientImpl::~FTPClientImpl()
{
	delete m_ftp;
}

void FTPClientImpl::LogIn(const char* user, const char* pwd)
{
	m_ftp->login(user, pwd);
}

int FTPClientImpl::UploadFile(const char *remote_path, const char *local_path)
{
	if(m_ftp->isLoggedIn())
	{
		std::ostream &ostr = m_ftp->beginUpload(remote_path);

		std::ifstream local_istr(local_path, std::ifstream::in | std::ifstream::binary);

		int numBytes = (int)Poco::StreamCopier::copyStream(local_istr, ostr);

		m_ftp->endUpload();

		return numBytes;
	}

	return 0;
}

void FTPClientImpl::CloseConnection()
{
	m_ftp->close();
}

