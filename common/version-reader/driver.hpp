#ifndef OCTETOS_TOOLKIT_DRIVER_HPP
#define OCTETOS_TOOLKIT_DRIVER_HPP

#include <string>
#include <cstddef>
#include <istream>

#include "../Version.hpp"
#include "scanner.hpp"
#include "parser.tab.hh"

namespace octetos
{
namespace toolkit
{
	class Driver
	{
	public:
		Driver();
		Driver(Version& version);
		Driver(Version& version, bool announce_error);
		Version& getVersion();
		virtual ~Driver();
		bool getAnnounceError();
		/** 
		* parse - parse from a file
		* @param filename - valid string with input file
		*/
		bool parse( const char * const str );
		bool parse(const std::string& str);
		/** 
		* parse - parse from a c++ input stream
		* @param is - std::istream&, valid input stream
		*/
		bool parse( std::istream &iss );
	private:
		bool parse_helper(std::istream& stream );
		Parser  *parser  = nullptr;
		Scanner *scanner = nullptr;
		Version* version;
		bool announce_error;
	};
}
} 
#endif
