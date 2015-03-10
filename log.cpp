#include "log.h"
//sets up three basic logs.. More can be added here aslong as the externs for them are added to log.h

OutputLog debug_log("debug.txt", false);
OutputLog warning_log("warning.txt", false);
OutputLog error_log("error.txt", false);
