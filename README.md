# utils
## rand
Example 1: randomly choose two lines with fixed seed, `-r` is the reverse flag
```
$ cat test1.txt | ./rand -n 2 -seed 1006
3
1
```
```
$ cat test1.txt | ./rand -n 2 -seed 1006 -r
2
```

Example 2: when n is larger than the line number of file.
```
$ cat test1.txt | ./rand -n 4 -seed 1006
3
1
2
```
```
$ cat test1.txt | ./rand -n 4 -seed 1006 -r
```
## solve_dup
solve duplicate key in the first column
```
$ cat test2.txt | solve_dup -n 3 -d .
line1.001 #########
line1.002 *********
line2.001 @@@@@@@@@
line3.001 &&&&&&&&&
line3.002 /////////
line3.003 \\\\\\\\\
```
```
$ cat test2.txt | solve_dup -n 7 -d '!!'
line1!!0000001 #########
line1!!0000002 *********
line2!!0000001 @@@@@@@@@
line3!!0000001 &&&&&&&&&
line3!!0000002 /////////
line3!!0000003 \\\\\\\\\
```