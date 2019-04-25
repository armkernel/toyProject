#!/bin/bash
# {}

#문자열 길이 구하기 
# ${#변수 } 


str="hello"

echo ${#str}

# substr
# expr substring "hello" 1 2
# bash는 여기까지 지원함 
# 시작점이 0부터 index! 

# ${변수 :시작 index:길이 }
echo ${str:0:2}
echo ${str:1}

#부분 문자열을 삭제하는 기능을 제공해줌 


str="ABCDEFABCDEFABCDEFABCDEF123"
#	|-----------------------|

#echo ${str#pattern}

echo ${str##A*F}


str="hellohello"

echo ${str//llo/???}

