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
Referencing the ./test.sh as an example:

``` bash
make
./main < input-file > output-file
cat input1-file input2-file | ./verify > output-file
```


# Assumptipons
This was developed with the shell.nix file using an isolated nix shell enviroment,
where all program dependencies are list out.
``` bash
nix-shell
```

Follows the input and output format as shown on canvas.

Additionally, 
- the main may send error codes such as 

INVALID (unequal student and hospital)

INVALID (no stable matching)

- the verify's should first get the original main's input and then main's output as an input

# TODO Part C Graph

# Tasks
## Dao
- TODO Time testing outputs
- TODO Randomly generate inputs and outputs
## Kim
- ~~TODO Reading files~~
- ~~TODO Verify inputs are valid (eg: equal number of hospital and student)~~
- ~~TODO Matching engine~~
