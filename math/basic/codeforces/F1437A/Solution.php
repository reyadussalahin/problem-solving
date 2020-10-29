<?php
// problem name: Marketing Scheme
// problem link: https://codeforces.com/contest/1437/problem/A
// contest link: https://codeforces.com/contest/1437
// time: (?)
// author: reyad

// other_tags: brute force, constructive algorithms, greedy
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
    list($l, $r) = array_map(asInt::class, nla());
    if($r >= 2 * $l) {
        echo "NO\n";
    } else {
        echo "YES\n";
    }
}