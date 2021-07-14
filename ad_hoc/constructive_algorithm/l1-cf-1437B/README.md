## Solutions
#### 1
##### Source Code
```php
<?php
// problem name: Reverse Binary Strings
// problem link: https://codeforces.com/contest/1437/problem/B
// contest link: https://codeforces.com/contest/1437
// time: (?)
// author: reyad


// other_tags: greedy
// difficulty_level: beginner


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
    $o = 0; $to = 0;
    $z = 0; $tz = 0;
    foreach(str_split(nl()) as $ch) {
        if($ch == "1") {
            $o++;
            $tz += $z ? $z-1 : 0;
            $z = 0;
        } else {
            $z++;
            $to += $o ? $o-1 : 0;
            $o = 0;
        }
    }
    echo max($tz, $to) . "\n";
}

```
