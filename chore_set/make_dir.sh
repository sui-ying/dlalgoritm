#!/bin/bash

name=$1
echo "mkdir $name"

if [ ! -d ${name} ]
then
    mkdir $name
    if [ ! -d ${name}/src ]
    then
      mkdir ${name}/src
    fi

    if [ ! -d ${name}/srcipt ]
    then
      mkdir ${name}/srcipt
    fi
else
    if [ ! -d ${name}/src ]
      then
        mkdir ${name}/src
        touch ${name}/src/${name}.cpp
      fi

      if [ ! -d ${name}/srcipt ]
      then
        mkdir ${name}/srcipt
        touch ${name}/srcipt/${name}.py
      fi
fi