#!/bin/bash
echo -n '输入10个数：'
read -a a
max=${a[0]};
for i in {1..10}
do 
    if [ ${a[$i]} > $max ]
    then
        max=${a[$i]}
    fi
done
echo"最大值为：${max}"
