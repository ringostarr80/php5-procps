/*
 * File:   php_procps.hpp
 * Author: Ringo Leese
 *
 * Created on 14. März 2013, 18:00
 */

#ifndef PHP_PROCPS_H
#define PHP_PROCPS_H 1

#define PHP_PROCPS_VERSION "3.3.3"
#define PHP_PROCPS_EXTNAME "procps"

#define PHP_PROCPS_RES_NAME "procps"

#ifdef ZTS
#include <php5/TSRM/TSRM.h>
#endif

ZEND_MINIT_FUNCTION(procps);
ZEND_MSHUTDOWN_FUNCTION(procps);
ZEND_RINIT_FUNCTION(procps);
ZEND_MINFO_FUNCTION(procps);

ZEND_FUNCTION(readproctab);

extern zend_module_entry procps_module_entry;
#define phpext_procps_ptr &procps_module_entry

#endif
