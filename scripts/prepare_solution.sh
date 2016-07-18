#!/bin/bash -e
if [ "$#" -ne 3 ]; then
  echo "$0 requres exactly tree arguments: path to sources, one solution file and --[no-]release"
  echo "$# given: $@"
  exit 1
fi
p=$1
s=$2
r=$3

files=`grep -e '#include  *"lib/' $s | sed -e 's#^[^"]*"##; s#"$##'`
out=${s}_prepared
cp $s $out
for i in $files; do
  j=$i
  if [ "$r" = "--release" ]; then
    j=${i}_prepared
  fi
  sed -i -e "\|#include  *\"$i\"| { s/^.*$//; r $p/$j
  }" $out
done
