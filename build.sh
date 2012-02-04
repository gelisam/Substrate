#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

qmake TARGET="$APP" src/app.pro
make
echo "*** BUILD OK ***"
