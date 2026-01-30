# Names
Alexander Dao (UFID: 45705087)

Alexander Kim (UFID: 71075724)

# Compilation

``` bash
cmake .
```


# Testing / Basic Running
1) Paste inputs into input. (for the main or verify program)
2) Paste expected output into expected.txt
3) Run ./test.sh
4) This will output any differences between expected and actual output

# Advanced Running
If you want to run the program yourself, use the ./test.sh as a reference:

``` bash
make
# For main matching program
./main < input-file > output-file
# For verify solution program
cat input1-file input2-file | ./verify > output-file
# For generating random preference list and every program
./test $n >input

time ./main <input >output
cat input output | ./verify
```


# Assumptipons
This was developed with the shell.nix file using an isolated nix shell enviroment,
where all program dependencies are list out.
``` bash
nix-shell
```

You probably don't need to run nixOS as long as you have a unix system with all the listed dependecies
listed out in the shell.nix file.

Follows the input and output format as shown on canvas.

Additionally, 
- the main may send error codes such as 

INVALID (unequal student and hospital)

INVALID (no stable matching)

- the verify's should first get the original main's input and then main's output as an input

# TODO Part C Graph
The data was generated using test.cpp and test.sh but the graph was made using google sheets.
![](./graph.png)
As n doubles, the time it takes to for main and verify to complete the task quadruples, suggesting the running time isolated
0(n^2).
