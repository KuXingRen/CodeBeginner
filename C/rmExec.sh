#!/bin/bash
for file in *; do
    if [[ ! $file == *.c ]] && [[ ! -d $file ]] && [[ ! $file == *sh ]]; then
        rm "$file"
    fi
done
