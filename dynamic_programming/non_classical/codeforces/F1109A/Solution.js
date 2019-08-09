// problem name: Sasha and a Bit of Relax
// problem link: https://codeforces.com/problemset/problem/1109/A
// contest link: https://codeforces.com/contest/1109
// author: reyad
// time: (?)

'use strict';

function main() {
	let m = 1<<20;
	let n = nextInt();

	let count_odd = [];
	let count_even = [];
	for(let i=0; i<=m; i++) {
		count_odd.push(0);
		count_even.push(0);
	}

	let ans = 0;

	let xor = 0;
	count_even[xor]++;
	
	for(let i=1; i<=n; i++) {
		xor = nextInt() ^ xor;
		if((i&1) == 1) {
			ans = ans + count_odd[xor];
			count_odd[xor]++;
		}
		else {
			ans = ans + count_even[xor];
			count_even[xor]++;
		}
	}
	console.log(ans);
}



// reader and main caller

let readline = require('readline');

let rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
	terminal: false
});

let inputBuf = [];
let inputBufCnt = 0;
let tk = []
let tkCnt = 0;

function nextLine() {
	return inputBuf[inputBufCnt++];
}
function next() {
	if(tkCnt == tk.length) {
		tk = inputBuf[inputBufCnt++].split(' ');
		tkCnt = 0;
	}
	return tk[tkCnt++];
}
function nextInt() {
	return parseInt(next());
}
function nextDouble() {
	return parseFloat(next());
}

rl.on('line', (line) => {
	inputBuf.push(line);
}).on('close', () => {
	main();
});
