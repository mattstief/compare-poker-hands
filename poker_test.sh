#!/bin/bash
> temp
echo "running program with inputs tests/*.txt"
for line in `ls tests/ | grep .txt`
do
	echo `build/poker.exe tests/$line` >> temp
done
cat temp > output.txt
rm temp
echo "done! results stored in output.txt"