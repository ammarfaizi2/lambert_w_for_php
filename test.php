<?php

for ($i = 1; $i <= 100000; $i++) {
  $x = exp(lambertw(log($i)));
  $epsilon = ($x ** $x) - $i;
  assert($epsilon < 0.000000001) or exit(1);;
}

for ($i = 1; $i <= 100000; $i++) {
  $x = exp(lambertw_fukushima(log($i)));
  $epsilon = ($x ** $x) - $i;
  assert($epsilon < 0.000000001) or exit(1);;
}

for ($i = 1; $i <= 100000; $i++) {
  $x = exp(lambertw(log($i) * exp(log($i))));
  $epsilon = $x - $i;
  assert($epsilon < 0.000000001) or exit(1);;
}

for ($i = 1; $i <= 100000; $i++) {
  $x = exp(lambertw_fukushima(log($i) * exp(log($i))));
  $epsilon = $x - $i;
  assert($epsilon < 0.000000001) or exit(1);;
}

echo "All green!\n";
