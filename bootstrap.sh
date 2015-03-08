#!/bin/bash
echo "Bootstrapping liblmbcam"

autoreconf -fiv
echo "done"

echo "Running configure script with arguments '$@'"
./configure $@
