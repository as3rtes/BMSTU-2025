#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Введите ваше имя"
    exit 1
fi

echo "Привет, $1!"
