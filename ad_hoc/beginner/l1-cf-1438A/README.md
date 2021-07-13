## Solutions
```php
<?php
// problem name: Specific Tastes of Andre
// problem link: https://codeforces.com/contest/1438/problem/A
// contest link: https://codeforces.com/contest/1438
// time: (?)
// author: reyad


// other_tags: (?)
// difficulty_level: easy


ob_start(null, 65536);

$__ln = explode("\n", file_get_contents("php://stdin"));
$__lc = 0;

function nl() {
    global $__ln, $__lc;
    return $__ln[$__lc++];
}

function nla() {
    global $__ln, $__lc;
    return explode(" ", $__ln[$__lc++]);
}

function asInt($x) {
    return (int)$x;
}

function asDouble($x) {
    return (double)$x;
}


$tc = asInt(nl());
for($cc=0; $cc<$tc; $cc++) {
    $n = asInt(nl());
    for($i=0; $i<$n; $i++) {
        echo 1 . " ";
    }
    echo "\n";
}

```
