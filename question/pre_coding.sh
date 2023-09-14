#!/bin/bash

#!/bin/bash

name=$1
echo "touch $name"

if [ ! -d "dynamic_programming" ]
then
    mkdir "dynamic_programming"
else
    if [ ! -d "dynamic_programming"/src ]
    then
      mkdir "dynamic_programming"/src
    fi

    if [ ! -d "dynamic_programming"/script ]
    then
      mkdir "dynamic_programming"/script
    fi
fi


if [ ! -e "dynamic_programming/src/${name}.cpp" ]
then
  cp demo/src/demo.cpp  dynamic_programming/src/${name}.cpp
fi

if [ ! -e "dynamic_programming/script/${name}.py" ]
then
  cp demo/script/demo.py  dynamic_programming/script/${name}.py
fi