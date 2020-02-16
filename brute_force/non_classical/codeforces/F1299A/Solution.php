<?php
// problem name: Anu Has a Function
// problem link: https://codeforces.com/contest/1299/problem/A
// contest link: https://codeforces.com/contest/1299
// time: (?)
// author: reyad

// other_tags: greedy

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
	for($i=0; $i<$n; $i++) {
		$a[] = next_int();
	}

	$front[] = $a[0];
	$back[$n-1] = $a[$n-1];
	for($i=1; $i<$n; $i++) {
		$front[] = $front[$i-1] | $a[$i];
		$back[$n-$i-1] = $back[$n-$i] | $a[$n-$i-1];
	}

	$ans = -1;
	$idx = -1;
	for($i=0; $i<$n; $i++) {
		$l = ($i > 0) ? $front[$i-1] : 0;
		$r = ($i < $n-1) ? $back[$i+1] : 0;
		$y = ($l | $r);
		$temp = ($a[$i] | $y) - $y;
		if($temp > $ans) {
			$ans = $temp;
			$idx = $i;
		}
	}
	
	$first = $a[$idx];
	unset($a[$idx]);

	printf("%d %s\n", $first, implode(" ", $a));
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
