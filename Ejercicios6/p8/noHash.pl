my @ages = ();

for ($i = 0; $i < 10000; ++$i) {
    my $name = random_name();
    my $age = random_age();
    my $seen = 0;
    foreach my $tuple (@ages) {
        if ($name eq $tuple->[0]) {
            $tuple->[1] = $age;
            $seen = 1;
            break;
        }
    }
    if ($seen == 0) {
        push @ages, [$name, $age];
    }
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
