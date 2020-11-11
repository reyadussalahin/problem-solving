<?php
// problem name: Chef Monocarp
// problem link: https://codeforces.com/contest/1437/problem/C
// contest link: https://codeforces.com/contest/1437
// time: (?)
// author: reyad


// other_tags: greedy, sortings, math, graph matchings, flows
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
    sort($buf);
    $m = $n * 2;
    $a = new SplFixedArray($n+2);
    $dp = new SplFixedArray($n+2);
    $x = 1;
    foreach($buf as $v) {
        $dp[$x] = new SplFixedArray($m+2);
        $a[$x++] = $v;
    }
    $dp[0] = new SplFixedArray($m+2);
    $inf = 1000000007;
    for($i=0; $i<=$n; $i++) {
        $dp[$i][0] = $inf;
        $dp[0][$i] = 0;
    }
    for($i=1; $i<=$n; $i++) {
        for($j=1; $j<=$m; $j++) {
            $dp[$i][$j] = min($dp[$i-1][$j-1] + abs($a[$i]-$j), $dp[$i][$j-1]);
        }
    }
    echo $dp[$n][$m] . "\n";
}
