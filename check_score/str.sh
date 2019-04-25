#!/bin/bash

# 문자열을 사용할 때는 expr를 사용할 수 있다.
# expr 산술연산 뿐만아니라 문자열을 처리할 때도 사용가능

# 길이
expr length "hello"

# 문자열 안에서 특정 패턴의 index를 구할 때도 사용할 수 있다.
# index 가 1부터 시작

expr index "hello" "el"

# 2 번째 인덱스 부터 길이가 3만큼 추출 
expr substr "hello" 2 3



