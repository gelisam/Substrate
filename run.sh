#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

# make sure the app is up-to-date
./build.sh

if [ "$1" == "--debug" ]; then
  gdb ./$APP.app/Contents/MacOS/$APP
else
  ./$APP.app/Contents/MacOS/$APP
fi
