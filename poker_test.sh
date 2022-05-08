#!/bin/bash
> temp
for line in `ls tests/ | grep .txt`
do
	echo $line
	echo `cat tests/$line`
	echo `build/poker.exe tests/$line` >> temp
	for nested_line in temp
	do
		echo $nested_line
	done
done
cat temp > output.txt
rm temp
