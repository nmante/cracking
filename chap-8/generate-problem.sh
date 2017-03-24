#!/bin/sh
problem=$1

if (( $# != 1 ))
then
	echo "Usage: generate-problem.sh <PROBLEM_NUMBER>"
	exit 1
fi

cd cpp
touch $problem.cpp
# Main file
echo "#include <iostream>" >> $problem.cpp
echo "" >> $problem.cpp
echo '/*' >> $problem.cpp
echo " * Problem $problem" >> $problem.cpp 
echo " */" >> $problem.cpp
echo "" >> $problem.cpp
echo "" >> $problem.cpp
echo "int main(int argc, char *argv[]){" >> $problem.cpp
echo "\treturn 0;" >> $problem.cpp
echo "}" >> $problem.cpp

cd ../python

touch $problem.py 
# Main file
echo "#!/usr/bin/env python" >> $problem.py
echo "from __future__ import print_function" >> $problem.py
echo "import argparse" >> $problem.py
echo "" >> $problem.py
echo '"""' >> $problem.py
echo "    $dir example" >> $problem.py 
echo '"""' >> $problem.py
echo "" >> $problem.py
echo "def create_parser():" >> $problem.py
echo "    parser = argparse.ArgumentParser()" >> $problem.py
echo "    return parser" >> $problem.py
echo "" >> $problem.py
echo "def $problem():" >> $problem.py
echo "    pass" >> $problem.py
echo "" >> $problem.py
echo "def main():" >> $problem.py
echo "    parser = create_parser()" >> $problem.py
echo "    args = parser.parse_args()" >> $problem.py
echo "" >> $problem.py
echo 'if __name__ == "__main__":' >> $problem.py
echo "    main()" >> $problem.py
chmod a+x $problem.py

