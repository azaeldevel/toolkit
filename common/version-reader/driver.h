#ifndef VERSION_READER_DRIVER_H
#define VERSION_READER_DRIVER_H

#include <common.h>

struct Tray
{
	struct octetos_toolkit_Version version;
    int dysplay_erro;
};

#ifdef __cplusplus  
extern "C" { 
#endif 
    /* Declarations of this file */
    int parse_string(struct Tray* ty,const char* in);
#ifdef __cplusplus 
} 
#endif
//

#endif

 
