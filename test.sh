make
./main <./main-test/input.txt >./main-test/output.txt
diff ./main-test/output.txt ./main-test/expected.txt

./verify <./verify-test/input.txt >./verify-test/output.txt
diff ./verify-test/output.txt ./verify-test/expected.txt
