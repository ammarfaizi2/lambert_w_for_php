
#include "php_lambertw.hpp"

ZEND_DECLARE_MODULE_GLOBALS(lambertw);

#ifdef COMPILE_DL_LAMBERTW
ZEND_GET_MODULE(lambertw)
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_lambertw, 0, 0, 1)
  ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

PHP_FUNCTION(lambertw)
{
  double n;

  ZEND_PARSE_PARAMETERS_START(1, 1)
    Z_PARAM_DOUBLE(n);
  ZEND_PARSE_PARAMETERS_END();

  RETURN_DOUBLE(n + 1);
}

static const zend_function_entry module_functions[] = {
  PHP_FE(lambertw, arginfo_lambertw)
  PHP_FE_END
};

static PHP_MINIT_FUNCTION(lambertw)
{
  REGISTER_INI_ENTRIES();
  return SUCCESS;
}

static PHP_MSHUTDOWN_FUNCTION(lambertw)
{
  UNREGISTER_INI_ENTRIES();
  return SUCCESS;
}


static PHP_GINIT_FUNCTION(lambertw)
{
#if defined(COMPILE_DL_ASTKIT) && defined(ZTS)
  ZEND_TSRMLS_CACHE_UPDATE();
#endif
}

zend_module_entry lambertw_module_entry = {
  STANDARD_MODULE_HEADER,
  "lambertw",
  module_functions, /* functions */
  PHP_MINIT(lambertw),
  PHP_MSHUTDOWN(lambertw),
  NULL, /* RINIT */
  NULL, /* RSHUTDOWN */
  NULL, /* MINFO */
  "0.0.1",
  PHP_MODULE_GLOBALS(lambertw),
  PHP_GINIT(lambertw),
  NULL, /* GSHUTDOWN */
  NULL, /* RPOSTSHUTDOWN */
  STANDARD_MODULE_PROPERTIES_EX
};
