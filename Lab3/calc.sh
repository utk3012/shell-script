echo "Enter the two values"
read a b
echo "enter operator(+,-,*,/,%)"
read op
((a++))
result=$((a $op b))
echo "result of performing $a $op $b is $result"
