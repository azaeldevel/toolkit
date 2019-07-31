//#include <iostream>
//#include <iostream>
//#include <cstdlib>
//#include <cstring>
//#include <string.h>
#include <string>

#include "Version.hpp"

namespace octetos
{
namespace toolkit
{

        bool Version::operator >(const Version& v)
        {
                if(major > v.major)
                {
                        return true;
                }
                else  if(minor > v.minor)
                {
                        return false;
                }
                else  if(minor > v.minor)
                {
                        return true;
                }
                else  if(patch > v.patch)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        bool Version::operator >=(const Version& v)
        {
                if(major >= v.major)
                {
                        return true;
                }
                else  if(minor >= v.minor)
                {
                        return false;
                }
                else  if(minor >= v.minor)
                {
                        return true;
                }
                else  if(patch >= v.patch)
                {
                        return true;
                }
                else
                {
                        return false;
                }
        }
        const std::string& Version::getName() const
        {
                return name;
        }
        void Version::setName(const std::string& name)
        {
                this->name = name;
        }
        void Version::set(short major,short minor,short patch,Stage stage,unsigned long build, const std::string& name)
        {                
                this->major = major;
                this->minor = minor;
                this->patch = patch;
                this->stage = stage;
                this->build = build;
                this->name = name;
        }
	unsigned long Version::getBuild() const
	{
                return build;
        }
        Version::Stage Version::getStage() const
        {
                return stage;
        }                
        void Version::setNumbers(short major,short minor,short patch)
        {
                this->major = major;
                this->minor = minor;
                this->patch = patch;
        }
        void Version::setNumbers(short major,short minor)
        {
                this->major = major;
                this->minor = minor;
        }
        void Version::setNumbers(short major)
        {
                this->major = major;
        }
        void Version::setStage(Stage stage)
        {
                this->stage = stage;
        }
        void Version::setBuild(unsigned long build)
        {
                this->build = build;
        }
	short Version::getMajor() const
	{
		return this->major;		
	}

	short Version::getMinor() const
	{
		return this->minor;
	}

	short Version::getPatch() const
	{
		return this->patch;
	}

	Version::Version(short major,short minor)
        {
		this->major = major;
		this->minor = minor;
		patch = -1;
		stage = unknown;
                build = 0;
                name = "";
        }
	Version::Version()
	{
		major = -1;
		minor = -1;
		patch = -1;
		stage = unknown;
                build = 0;
                name = "";
	}

	std::string Version::toString() const
	{		
		std::string ver = "";
                if(major >= 0)
                {
                        ver += std::to_string(major);
                }
                if(minor >= 0)
                {
                        ver += ".";
                        ver += std::to_string(minor);
                }
                if(patch >= 0)
                {
                        ver += ".";
                        ver += std::to_string(patch);		
                }
                
		switch(stage)
                {
                        case snapshot:
                                ver += "-snapshot";
                                break;
                        case alpha:
                                ver += "-alpha";
                                break;
                        case beta:
                                ver += "-beta";
                                break;
                        case rc:
                                ver += "-rc";
                                break;
                        case release:
                                ver += "-release";
                                break;
                        case unknown:
                                ;
                }

		if(build > 0)
                {
                        ver += " ";
                        ver += std::to_string(build);	
                }
                
                if(name.size() > 0)
                {
                        ver += " ";
                        ver += name;
                }
                
		return ver;
	}
	
}
}
