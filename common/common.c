//to fix:   warning: implicit declaration of function ‘asprintf’; did you mean ‘vsprintf’....
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "common.h"
#include "config.h"

struct Version Version(short major,short minor,short patch,enum Stage stage)
{
	struct Version version;
	version.major = major;
	version.minor = minor;
	version.patch = patch;
	version.stage = stage;
	
	return version;	
}
const char* toString(const struct Version* version)
{
	char* verstr = NULL;
	if(version->major > -1)
	{
		char* verstrMa;
		asprintf(&verstrMa, "%i", version->major);
		verstr = verstrMa;
	}
	else
	{//falla devido a que no esta inicializado
		return NULL;
	}
	if(version->minor > -1)
	{
		char* verstrMi;
		asprintf(&verstrMi, "%i", version->minor);
		if(verstr != NULL) 
		{
			verstr = strcat(verstr,".");
			verstr = strcat(verstr,verstrMi);
		}
	}
	else
	{//falla devido a que no esta inicializado
		return NULL;
	}
	if(version->patch > -1)
	{
		char* verstrPa;
		asprintf(&verstrPa, "%i", version->patch);
		if(verstr != NULL) 
		{
			verstr = strcat(verstr,".");
			verstr = strcat(verstr,verstrPa);
		}
	}
	else
	{//falla devido a que no esta inicializado
		return NULL;
	}
	
	if(version->stage == unknown)
	{//falla devido a que no esta inicializado
		return NULL;
	}
	else if(version->stage == alpha)
	{
		verstr = strcat(verstr,"-alpha");		
	}
	else if(version->stage == beta)
	{
		verstr = strcat(verstr,"-beta");
	}
	else if(version->stage == release)
	{
		verstr = strcat(verstr,"-release");
	}
	
	
	return verstr;
}	

struct Version getPakageVersionTC()
{
	struct Version version;
	version.major = MAJOR;
	version.minor = MINOR;
	version.patch = PATCH;
	version.stage = STAGE;
	
	return version;		
}
