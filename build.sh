#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

qmake TARGET="$APP" qmake-project-file.pro
make
echo "*** BUILD OK ***"
