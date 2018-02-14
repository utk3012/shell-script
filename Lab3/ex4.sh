echo "Input Basic Salary"
read bs
echo "Input TA"
read ta
gs=$(echo "$bs+$ta+0.1*$bs" | bc -l)
echo "Gross Salary = $gs"