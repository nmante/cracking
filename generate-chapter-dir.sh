#!/bin/sh
dir=$1
problem=$2

if (( $# < 1 ))
then
	echo "Usage: generate-chapter-dir.sh <DIR> [PROBLEM_NUMBER]"
	exit 1
fi

mkdir $dir
cp generate-problem.sh.temp $dir/generate-problem.sh
chmod a+x $dir/generate-problem.sh

cd $dir
touch README.md 
mkdir python
mkdir images
mkdir cpp
cp ../Makefile.temp cpp/Makefile


if (( $# == 2 ))
then
	#cd $dir
	./generate-problem.sh $problem
	
fi

