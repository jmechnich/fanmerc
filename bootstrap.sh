#!/bin/bash
echo "Bootstrapping liblmbcam"

echo -n "Running aclocal... "
aclocal
echo "done"

echo -n "Installing libtool components... "
libtoolize --force --copy
echo "done"

echo -n "Running automake... "
automake  --gnu --add-missing --copy
echo "done"

echo -n "Running autoconf... "
autoconf
echo "done"

echo "Running configure script with arguments '$@'"
./configure $@
