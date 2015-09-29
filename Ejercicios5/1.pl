$alego = "detesto perl";
$futuro = "jamas programare en perl";

sub odioPerl()
{
  my $alego = "odio mucho perl";
  local $futuro = "nunca más programare en perl";

  print "Alego dentro: $alego\n";
  print "Futuro dentro: $futuro\n";
}

odioPerl();

print "Alego afuera: $alego\n";
print "Futuro afuera: $futuro\n";

