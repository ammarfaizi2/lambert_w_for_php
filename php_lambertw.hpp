
#ifndef __LAMBERTW_H
#define __LAMBERTW_H

#ifdef HAVE_CONFIG_H
  #include "config.h"
#endif

#include <php.h>

extern zend_module_entry lambertw_module_entry;

PHP_INI_BEGIN()
PHP_INI_END()

ZEND_BEGIN_MODULE_GLOBALS(lambertw)
ZEND_END_MODULE_GLOBALS(lambertw)

ZEND_EXTERN_MODULE_GLOBALS(lambertw)

#define LAMBERTWG(v) ZEND_MODULE_GLOBALS_ACCCESSOR(lambertw, v)

#define phpext_lambertw_ptr (&lambertw_module_entry)

#endif
