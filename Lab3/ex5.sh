echo "Input extension"
read ext
echo "Input folder name"
read fol
mkdir $fol
x=$(find . -maxdepth 1 -name "*$ext")
for i in $x; do
mv $i $fol
echo $i
done