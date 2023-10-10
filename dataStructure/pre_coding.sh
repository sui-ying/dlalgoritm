#!/bin/bash

#!/bin/bash

dirname=$1
filename=$2
echo "./pre_coding.sh $dirname $filename"

if [ ! -d "$dirname" ]
then
    mkdir "$dirname"
    mkdir "$dirname"/src
    mkdir "$dirname"/script
else
    if [ ! -d "$dirname"/src ]
    then
      mkdir "$dirname"/src
    fi

    if [ ! -d "$dirname"/script ]
    then
      mkdir "$dirname"/script
    fi
fi


if [ ! -e "$dirname/src/${filename}.cpp" ]
then
  cp ../demo/src/demo.cpp  $dirname/src/${filename}.cpp
fi

if [ ! -e "$dirname/script/${filename}.py" ]
then
  cp ../demo/script/demo.py  $dirname/script/${filename}.py
fi