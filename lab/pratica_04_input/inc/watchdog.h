#ifndef WATCHDOG_H
#define WATCHDOG_H

#define WTD_WSPR                                            (0x48)
#define WTD_WWPS                                            (0x34)
#define W_PEND_WSPR                                         (0x00000010u)
#define NO_PENDING                                          (0x0)
#include "hw_types.h"
#include "soc_AM335x.h"

#define WTD_DISABLE_FIRST_SEQ                            (0x0000AAAA);
#define WTD_DISABLE_SECOND_SEQ                           (0x00005555);


void disableWtd();

#endif