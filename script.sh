# script to run the prime program several times, in order not to run too long.
for i in `seq 1 50`; do
	./prime 10
done
cp Data startData ../save/
