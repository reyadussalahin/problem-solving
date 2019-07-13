// problem name: Routine Problem
// problem link: https://codeforces.com/problemset/problem/337/B
// contest link: https://codeforces.com/contest/337
// author: reyad
// time: (?)

'use strict';

function gcd(a, b) {
	while(b != 0) {
		let t = b;
		b = a % b;
		a = t;
	}
	return a;
}

function main() {
	let a = nextInt();
	let b = nextInt();
	let c = nextInt();
	let d = nextInt();

	if(c * b > a * d) { // h/v of image is greater than screen, so horizontal fitting
		let x = b * c - d * a;
		let y = b * c;
		let g = gcd(x, y);
		console.log((x / g) + '/' + (y / g));
	}
	else { // vertical fitting
		let x = d * a - b * c;
		let y = d * a;
		let g = gcd(x, y);
		console.log((x / g) + '/' + (y / g));
	}
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
