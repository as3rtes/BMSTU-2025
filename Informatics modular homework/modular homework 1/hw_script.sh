#!/bin/bash

filename=$1

if [ -f "$filename" ]; then
    count=$(grep -c "error" "$filename")
    echo "Number of lines with 'error': $count"
else
    echo "File does not exist. Creating new file..."
    cat > "$filename" << EOF
Hello bmstu
Here is the word error
Another line
My life is error
Normal message
Last line with error
EOF
    echo "File created with test data"
fi

while IFS= read -r line; do
    echo "$line" | nc -q 0 localhost 8080
    sleep 0.1
done < "$filename"
