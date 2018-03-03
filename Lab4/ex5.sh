echo "File name-"
read b
echo "1.Search \n 2.Delete \n 3.Exit"
read a
case $a in
1)echo $*
for i in $@;do
grep $i $b
done
;;

2)echo $*
for i in $@;do
sed -i -e "s/$i//g" $b
done
;;

3)exit;;
esac


