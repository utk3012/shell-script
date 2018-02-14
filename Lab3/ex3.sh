x=$(find . -name "*.txt")
for i in $x; do
mv "$i" "${i%.txt}.text"
done
