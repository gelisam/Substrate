#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

if [ ! -d "$APP.app" ]; then
  ./build.sh
fi
if [ "$1" == "--debug" ]; then
  gdb ./$APP.app/Contents/MacOS/$APP
else
  ./$APP.app/Contents/MacOS/$APP
fi
