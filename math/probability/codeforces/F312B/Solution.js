// problem name: Archer
// problem link: https://codeforces.com/problemset/problem/312/B
// contest link: https://codeforces.com/contest/312
// author: reyad
// time: (?)

'use strict';

function main() {
	let a = nextInt();
	let b = nextInt();
	let c = nextInt();
	let d = nextInt();

	let p = a / b; // probability that SmallR wins in the first round
	let q = c / d; // probability that Zanoes wins in the first round
	
	let r = (1 - p) * (1 - q);
	let ans = p / (1 - r);
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
