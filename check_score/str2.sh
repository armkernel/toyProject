#!/bin/bash
# {}

#���ڿ� ���� ���ϱ� 
# ${#���� } 


str="hello"

echo ${#str}

# substr
# expr substring "hello" 1 2
# bash�� ������� ������ 
# �������� 0���� index! 

# ${���� :���� index:���� }
echo ${str:0:2}
echo ${str:1}

#�κ� ���ڿ��� �����ϴ� ����� �������� 


str="ABCDEFABCDEFABCDEFABCDEF123"
#	|-----------------------|

#echo ${str#pattern}

echo ${str##A*F}


str="hellohello"

echo ${str//llo/???}

