
#include "php_lambertw.hpp"
#include <LambertW.h>
#include <FukushimaLambertW.h>

ZEND_DECLARE_MODULE_GLOBALS(lambertw);

#ifdef COMPILE_DL_LAMBERTW
ZEND_GET_MODULE(lambertw)
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_lambertw, 0, 0, 1)
  ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

PHP_FUNCTION(lambertw_fukushima)
{
  double n, ret;

  ZEND_PARSE_PARAMETERS_START(1, 1)
    Z_PARAM_DOUBLE(n);
  ZEND_PARSE_PARAMETERS_END();

  ret = Fukushima::LambertW(0, n);

  RETURN_DOUBLE(ret);
}

PHP_FUNCTION(lambertw)
{
  double n, ret;

  ZEND_PARSE_PARAMETERS_START(1, 1)
    Z_PARAM_DOUBLE(n);
  ZEND_PARSE_PARAMETERS_END();

  ret = utl::LambertW(0, n);

  RETURN_DOUBLE(ret);
}

static const zend_function_entry module_functions[] = {
  PHP_FE(lambertw, arginfo_lambertw)
  PHP_FE(lambertw_fukushima, arginfo_lambertw)
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
