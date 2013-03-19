PHP_ARG_ENABLE(procps, whether to enable procps support,
[ --enable-procps   Enable procps support])

if test "$PHP_PROCPS" = "yes"; then
  PHP_ADD_LIBPATH(/usr/local/lib)
  AC_DEFINE(HAVE_PROCPS, 1, [Whether you have procps])
  PHP_NEW_EXTENSION(procps, procps.c, $ext_shared)
  PHP_SUBST(PROCPS_SHARED_LIBADD)
  PHP_ADD_LIBRARY(procps, 1, PROCPS_SHARED_LIBADD)
fi
