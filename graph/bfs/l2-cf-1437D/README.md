## Solutions
```php
<?php
// problem name: Minimal Height Tree
// problem link: https://codeforces.com/contest/1437/problem/D
// contest link: https://codeforces.com/contest/1437
// time: (?)
// author: reyad


// other_tags: greedy, shortest paths, trees
// difficulty_level: medium


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
    $buf = array_map(asInt::class, nla());
    $a = new SplFixedArray($n+2);
    $x = 0;
    foreach($buf as $v) {
        $a[$x++] = $v;
    }
    $q = new SplFixedArray($n+2);
    $s = 0; $e = 0;
    $q[$e++] = 0;
    for($i=1; $i<$n; $i++) {
        if($a[$i-1] < $a[$i]) {
            $q[$e++] = $q[$s]+1;
        } else {
            $s++;
            $q[$e++] = $q[$s]+1;
        }
    }
    echo $q[$n-1] . "\n";
}
```
