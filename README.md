
# PHP Lambert W Function
Implementation of Lambert W function in PHP.

# Installation
```
git clone https://github.com/ammarfaizi2/php_lambertw;
cd php_lambertw;
phpize;
./configure;
make -j2;
```

# Run The Test
```
php -dextension=$(pwd)/modules/lambertw.so test.php
```

# Thanks to
- https://arxiv.org/abs/1003.1628
- https://arxiv.org/abs/1209.0735
- (Lambert W function for applications in physics)[https://dx.doi.org/10.1016/j.cpc.2012.07.008]
- https://github.com/DarkoVeberic/LambertW