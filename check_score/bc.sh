#!/bin/bash

echo $(echo "scale=4; 3.14 / 3" | bc)

val1=3.14
val2=3

echo $(echo "scale=4; $val1 / $val2" | bc)

echo "scale=4; $val1 / $val2" | bc

ls

# Here Document 
# Redirection 입력 특정한 토큰이 도착할 경우 EOF처리 

bc << END

scale=4
3.14 / 3
END
