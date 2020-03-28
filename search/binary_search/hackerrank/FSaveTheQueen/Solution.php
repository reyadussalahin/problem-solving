<?php
// problem name: Save The Queen
// problem link: https://www.hackerrank.com/contests/hourrank-31/challenges/save-the-queen/problem
// contest link: https://www.hackerrank.com/contests/hourrank-31/challenges
// time: (?)
// author: reyad

// other tags: (?)


// difficulty level: medium


namespace io {
    $input_file_content = file_get_contents("php://stdin");
    $input_buf = explode("\n", $input_file_content);
    unset($input_file_content);
}

namespace main {
    error_reporting(E_ALL);
    ini_set('display_errors', true);
    ini_set('html_errors', false);

    use function io\next_line as next_line;
    use function io\next_ as next;
    use function io\next_int as next_int;
    use function io\next_double as next_double;

    $n = next_int();
    $k = next_int();
    for($i=0; $i<$k; $i++) $a[] = next_int();

    sort($a);

    $s = 0; $e = (int)1e12; $x = -1;
    while(abs($s - $e) > 1e-5) {
        $m = ($s + $e) / 2;
        $t = 0;
        $c = 0;
        foreach($a as $v) {
            if($v + 1e-5 < $m) {
                $t += $v;
                $c++;
            }
            else break;
        }
        $d = $n - $k + $c;
        if($d < 1 || (($t / $d) + 1e-5 > $m)) {
            $s = $m;
            $x = $m;
        }
        else $e = $m;
    }
    printf("%f\n", $x);
}


namespace io {
    function next_line() {
        static $cnt = 0;
        global $input_buf;
        return $input_buf[$cnt++];
    }
    function next_() {
        static $tk = [];
        static $tk_cnt = 0;
        if($tk_cnt == count($tk)) {
            $tk = explode(" ", next_line());
            $tk_cnt = 0;
        }
        return $tk[$tk_cnt++];
    }
    function next_int() {
        return (int)next_();
    }
    function next_double() {
        return (double)next_();
    }
}

?>