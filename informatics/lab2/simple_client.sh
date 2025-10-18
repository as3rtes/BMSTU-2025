#!/bin/bash

read message
echo "$message" | nc localhost 9999

echo "Сообщение отправлено!"
