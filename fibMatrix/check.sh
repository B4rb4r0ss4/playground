for((i=1000000000; ; i++)) do 
    echo "PROCESSING $i"
    echo "$i" > inp
    time ./fibBigNum < inp > out1
    time ./fibDp < inp > out2
    diff -w out1 out2 || break
    echo "PASSED!"
done
