#!/bin/bash
R="\033[31m"
G="\033[32m"
NC="\033[0m"

make

if file -f $1 | grep -q "shared library" || otool -L -f $1 | grep -q "libSystem.B.dylib"
then
	printf "${G}[OK] $1 is a shared library${NC}";
else
	printf "${R}[KO] Error: $1 isn't a shared library ${NC}";
fi

make fclean
