#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

qmake TARGET="$APP" app.pro
make
echo "*** BUILD OK ***"
