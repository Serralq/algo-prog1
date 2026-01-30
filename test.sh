# make the program
cmake .
make

# Basic testing for main
./main <./main-test/input.txt >./main-test/output.txt
diff ./main-test/output.txt ./main-test/expected.txt

# Advance testing for verify
for dir in ./verify-test/*/; do
  dirname=$(basename "$dir")
  echo "Testing folder: $dirname"

  cat "${dir}input1.txt" "${dir}input2.txt" | ./verify >"${dir}output.txt"

  if diff -q "${dir}output.txt" "${dir}expected.txt" >/dev/null; then
    echo "PASS"
  else
    echo "FAIL"
  fi
done

MIN_EXP=5
MAX_EXP=13
# Basic testing to combine main and verify
for ((exp = MIN_EXP; exp <= MAX_EXP; exp++)); do
  n=$((2 ** exp))

  echo "n=$n: "
  echo ""
  ./test $n >input.txt

  echo "Running main..."
  time ./main <input.txt >output.txt
  echo ""

  cat input.txt output.txt >verify_input.txt

  echo "Verifying..."
  time ./verify <verify_input.txt >/dev/null
  echo ""

  rm input.txt output.txt verify_input.txt
done
