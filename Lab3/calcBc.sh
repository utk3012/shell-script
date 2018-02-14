echo "Enter two values"
read a b
echo "Enter operator(+,-,*,/,%)"
read op
result=$(echo "$a $op $b" | bc -l)
echo "Result of operation is $result"