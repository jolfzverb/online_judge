#!/bin/bash -e
if [ "$#" -ne 1 ]; then
  echo "$0 requres exactly one argument"
  exit 1
fi
g++ -E -DRELEASE $1 | sed -e "/^#/d" > ${1}_prepared
