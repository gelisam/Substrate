#!/bin/bash
set -e

APP="$(basename "$(pwd)")"

# make sure the app is up-to-date
./build.sh

EXE="$APP.app/Contents/MacOS/$APP"
if [ ! -x "$EXE" ]; then
  EXE="substrate"
fi

if [ "$1" == "--debug" ]; then
  gdb ./"$EXE"
else
  ./"$EXE"
fi
