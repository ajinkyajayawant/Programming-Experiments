python3.6 -c 'from table_generation_for_latex import argmax_max_two_tables; argmax_max_two_tables("/tmp/pandastry/sz_alg_snrs.dat","/tmp/pandastry/alg_times_iter.dat",[3,4,5,6,7],"/tmp/pandastry/output.dat")'

echo "1 2 3\n2 3 1\n3 1 2" > /tmp/a1.txt
echo "0.1 0.2 0.3\n0.1 0.2 0.3\n0.1 0.2 0.3" > /tmp/a2.txt

python3.6 -c 'from table_generation_for_latex import argmax_max_two_tables; argmax_max_two_tables("/tmp/a1.txt","/tmp/a2.txt",[0,1,2],"/tmp/a3.txt")'

cat /tmp/a1.txt
cat /tmp/a2.txt
cat /tmp/a3.txt
