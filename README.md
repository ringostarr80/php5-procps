php5-procps
===========

A php extension for procps

How to install php5-procps extension
------------------------------------

make sure one of the following packages is installed: `libproc-dev`, `libprocps3-dev`

1. change to php5-procps source directory
2. execute `phpize`
3. execute `./configure`
4. execute `make`
5. optional execute `make test`
6. execute `sudo make install` /* this copies the procps.so file to the php5-library directory eg.: /usr/lib/php5/20100525 or /usr/lib/php5/20121212 */
7. create the file 'procps.ini' in '/etc/php5/conf.d' or '/etc/php5/mods-available' with the following content: 'extension=procps.so'
8. restart your webserver or php5-fpm.

that should it be.
