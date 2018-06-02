# BSQ

The aim of this project is to find the biggest square on a map, avoiding obstacles.

# The biggest square :
* A file containing the map will be provided. It’ll have to be passed as an argument for your program.
* The first line of the map contains information on how to read the map: The number of lines on the map; The "empty" character; The "obstacle" character; The "full" character.
* The map is made up of ’"empty" characters’, lines and ’"obstacle" characters’.
* The aim of the program is to replace ’"empty" characters’ by ’"full"
characters’ in order to represent the biggest square possible.
* In the case that more than one solution exists, we’ll choose to represent the square that’s closest to the top of the map, then the one that’s most to the left.

# Definition of a valid map :
* All lines must have the same length.
* There’s at least one line of at least one box.
* At each end of line, there’s a line break.
* The characters on the map can only be those introduced in the first line.
* In case of an invalid map, your program should display map error on the error output followed by a line break. Your program will then move on to the next map.

# Instructions :
* When your program receives more than one map in argument, each solution or error
must be followed by a line break.
* Should there be no passed arguments, your program must be able to read on the standard input.
* You should have a valid Makefile that’ll compile your project.
* You may only use the following functions : exit, open, close, write, read, malloc
and free.

# Perl map generator :

```
#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my ($x, $y, $density) = @ARGV;
print "$y.ox\n";
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
if (int(rand($y) * 2) < $density) {
    print "o";
}
else {
print "."; }
}
print "\n"; }
```
