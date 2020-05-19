file=$1

rm -f *.o test.out

cp ../$file.h ./

gcc -o test.out ../$file.c test_$file.c test.c assertions.c

if [ $? == 0 ]
then
  ./test.out
else
  echo "complitation or linking failed"
fi

rm -f *.o test.out
rm -f $file.h
