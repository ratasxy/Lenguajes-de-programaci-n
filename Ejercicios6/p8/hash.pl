my $ages = {};

for ($i = 0; $i < 10000; ++$i) {
    my $name = random_name();
    my $age = random_age();
    $ages{$name} = $age;
    print "$name: $age\n";
}

sub random_name {
    my $name = '';
    for (my $i = 0; $i < 3; ++$i) {
        $name .= chr(97 + int(rand(26)));
    }
    return $name;
}

sub random_age {
    return int(rand(80));
}
