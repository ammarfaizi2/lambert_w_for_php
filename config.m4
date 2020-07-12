
dnl config.m4

PHP_ARG_ENABLE(teabot8, for teabot8 support,
[  --enable-php-lambertw            Include lambertw support])

if test "$PHP_LAMBERTW" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(lambertw, php_lambertw.cpp lambertw_ext/FukushimaLambertW.cc lambertw_ext/LambertW.cc, $ext_shared)
  PHP_ADD_INCLUDE(lambertw_ext)
  PHP_SUBST(LAMBERTW_SHARED_LIBADD)
fi
