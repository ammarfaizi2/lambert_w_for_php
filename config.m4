
dnl config.m4

PHP_ARG_ENABLE(teabot8, for teabot8 support,
[  --enable-php-lambertw            Include lambertw support])

if test "$PHP_LAMBERTW" != "no"; then
  PHP_REQUIRE_CXX()
  PHP_NEW_EXTENSION(lambertw, php_lambertw.cpp, $ext_shared)
  PHP_SUBST(LAMBERTW_SHARED_LIBADD)
fi
