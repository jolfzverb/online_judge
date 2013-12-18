#!/usr/bin/perl
# as arguments we want binary and directory with tests, from which we
# take all .in files, feed it to binary and compare with corresponding
# .out file


if ($#ARGV < 1) {
  print "\n\t2 arguments required.\n\n";
}
my $result = 0;
my $binary = $ARGV[0];
my $test_dir = $ARGV[1];

opendir $dir, $test_dir or die "cannot open dir '$test_dir': $!";
while(readdir $dir){
  if (/(.*)\.in$/){
    $in_file = "$test_dir/$_";
    $out_file = "$test_dir/$1.out";
    `$binary < $in_file > $in_file.out`;
    $diff = `diff $in_file.out $out_file`;
    if(not $diff eq ""){
      print "test $_ for binary $binary failed\n";
      $result = 1;
    }
    `rm $in_file.out`;
  }
}


closedir $dir;
exit $result;
