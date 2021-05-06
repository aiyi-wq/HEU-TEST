#!/bin/bash
i=2
while ((i<100));do
    j=2
    while ((j<=i/2));do
        if ((i%j==0));then
            break
        fi
        let j++
    done
    if ((j>i/2));then
        echo $i
    fi
    let i++
done
