echo "Input extension"
read ext
echo "Input folder name"
read fol
mkdir $fol
for i in "*$ext"; do
mv $i $fol
done