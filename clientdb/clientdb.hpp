#ifndef TOOLKIT_CLIENTDB_HPP
#define TOOLKIT_CLIENTDB_HPP

#include <common.hpp>
#include <vector>

namespace toolkit
{
namespace clientdb
{
	toolkit::Version getPakageVersion();
	std::string getPakageName();	
	typedef unsigned int ID;
        
    class SQLException : public std::exception
    {
    public:
        virtual ~SQLException() throw();
        virtual const char* what() const throw();
        SQLException(const std::string &description) throw();
	private:
        std::string description;
    };
    class SQLExceptionConnection : public SQLException
    {
    public:
        virtual ~SQLExceptionConnection() throw();
        SQLExceptionConnection(const std::string &description) throw();
    };
    class SQLExceptionQuery : public SQLException
    {
    public:
        virtual ~SQLExceptionQuery() throw();
        SQLExceptionQuery(const std::string &description) throw();
    };
    class NotSupportedExcetion  : public SQLException
    {
        virtual ~NotSupportedExcetion() throw();
        NotSupportedExcetion(const std::string &description) throw();		
	};
    
	class Datasource
	{
	public:
            enum ServerType
            {
                MySQL,
                PostgreSQL
            };            
            Datasource(const Datasource&);
            const Datasource& operator=(const Datasource& obj);
            void set(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            
            virtual std::string toString() const;
            const std::string& getHost()const;
            const std::string& getUser()const;
            const std::string& getPassword()const;
            const std::string& getDatabase()const;
            ServerType getServerType()const;		
            unsigned int getPort()const;
	protected:
            Datasource(ServerType serverType,const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            
	private:
            ServerType serverType;
            std::string host;
            std::string user;
            std::string password;
            std::string database;
            unsigned int port;        
	};	
	
	class Connector
	{
        protected:
            void* serverConnector;
            const Datasource* datconection;
            bool is_ipv4_address(const std::string& str);
            bool is_ipv6_address(const std::string& str);
            bool is_valid_domain_name(const std::string& str);
            
        public:
            virtual ~Connector();
            Connector();
            virtual bool connect(const Datasource& connector) = 0;            
            virtual bool query(const std::string&) = 0;
            virtual bool query(const std::string&, std::vector<std::vector<const char*>>&) = 0;
            virtual ID insert(const std::string&) = 0;
            virtual bool commit() = 0;
            virtual bool begin() = 0;
            virtual bool rollback() = 0;
            virtual void close() = 0;
            void* getServerConnector();
            const Datasource& getDatconection() const;  
	};
}
}

#endif
