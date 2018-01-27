echo "Input name"
read inp
if [ -f $inp ]; then
echo "This is a file"
elif [ -d $inp ]; then
echo "This is a directory"
fi
