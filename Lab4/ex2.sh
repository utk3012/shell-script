for i in "$@"; do
echo "Do you want to delete" $i "(y/n)"
read ch
if [ $ch = 'y' ]; then
rm -rf $i
fi
done


