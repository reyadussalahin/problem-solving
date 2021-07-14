## Solutions
#### 1
##### Source Code
```php
<?php
// problem name: Path Queries
// problem link: https://codeforces.com/contest/1213/problem/G
// contest link: https://codeforces.com/contest/1213
// time: (?)
// author: reyad


// other_tags: divide and conquer, graphs, sortings, trees
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
 
 
list($n, $m) = array_map(asInt::class, nla());
 
for($i=1; $i<$n; $i++) {
    $g[] = array_map(asInt::class, nla());
}
 
if($n > 1) {
    usort($g, function(&$x, &$y) {
        return $x[2] - $y[2];
    });
}
 
$p = new SplFixedArray($n+1);
$c = new SplFixedArray($n+1);
$x = new SplFixedArray($n+1);
for($i=0; $i<=$n; $i++) {
    $p[$i] = $i;
    $c[$i] = 1;
    $wx[$i] = 0;
}
 
function find($i) {
    global $p;
    return ($i === $p[$i]) ? $i : ($p[$i] = find($p[$i]));
}
 
$mw = ($n === 1) ? 0 : $g[$n-2][2];
$ans = new SplFixedArray($mw+1);
for($i=0; $i<=$mw; $i++) {
    $ans[$i] = 0;
}
 
foreach($g as $e) {
    list($u, $v, $w) = $e;
    $pu = find($u);
    $pv = find($v);
    $ans[$w] = bcadd($ans[$w], bcmul($c[$pu], $c[$pv]));
    $c[$pu] += $c[$pv];
    $p[$pv] = $pu;
    $wx[$pu] = $w;
}
 
for($i=1; $i<=$mw; $i++) {
    $ans[$i] = bcadd($ans[$i], $ans[$i-1]);
}
 
$q = array_map(asInt::class, nla());
foreach($q as $x) {
    echo (($x < $mw) ? $ans[$x] : $ans[$mw]) . " ";
}
echo "\n";

```
