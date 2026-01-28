make
./main <./main-test/input.txt >./main-test/output.txt
diff ./main-test/output.txt ./main-test/expected.txt

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
