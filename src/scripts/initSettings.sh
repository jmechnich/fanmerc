#!/bin/bash
#
#  Automatic Compilation and Installation script
#

set -e

TARGET="$HOME/.config/mechnich/fanmerc.conf"
mkdir -p `dirname "$TARGET"`
echo "[General]" > "$TARGET"
echo "imageDir=$BUILDDIR/share/fanmerc/images" >> "$TARGET"
echo "soundDir=$BUILDDIR/share/fanmerc/sounds" >> "$TARGET"
echo "" >> "$TARGET"
