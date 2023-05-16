#!/bin/bash
R="\033[31m"
G="\033[32m"
NC="\033[0m"

make clean
make fclean
make

# Check if ".so" exist in current directory
SO_FILE=$(ls -1 *.so 2>/dev/null)
# Set file path to ".so" file in current directory
if [ "$#" -eq 0 ]; then
	FILE_PATH="$SO_FILE"
else
	for ARG in "$@"; do
		# Check if argument is ".so" file
		if [ "$ARG##*." = ".so" ]; then
			FILE_PATH="$ARG"
			break
		fi
	done
	# Check if path file is set
	if [ -z "$FILE_PATH" ]; then
		printf "${R}[KO] Error: .so file don't exist ${NC}" >&2
		exit 1
	fi
fi

# Check if path file exist
if ! [ -e "$FILE_PATH" ];then
	printf "${R}[KO] Error: $FILE_PATH don't exist ${NC}" >&2
	exit 1

# Check if path file is a file
elif ! [ -f "$FILE_PATH" ];then
	printf "${R}[KO] Error: $FILE_PATH isn't a file ${NC}" >&2
	exit 1
# Check if path file is a dynamic library
elif ! file -f "$FILE_PATH" | grep -q "shared library" && ! otool -L -f "$FILE_PATH" | grep -q "libSystem.B.dylib"; then
    printf "${R}[KO] Error: $FILE_PATH is not a shared library${NC}" >&2
    exit 1
else
    printf "${G}$FILE_PATH is a shared library${NC}"
fi

make fclean
