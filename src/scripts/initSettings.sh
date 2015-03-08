#!/bin/bash
#
#  Automatic Compilation and Installation script
#

touch $HOME/.qt/fanmercrc \
&& echo "[General]" > $HOME/.qt/fanmercrc \
&& echo "imageDir=$BUILDDIR/share/fanmerc/images" >> $HOME/.qt/fanmercrc \
&& echo "soundDir=$BUILDDIR/share/fanmerc/sounds" >> $HOME/.qt/fanmercrc \
&& echo "" >> $HOME/.qt/fanmercrc
