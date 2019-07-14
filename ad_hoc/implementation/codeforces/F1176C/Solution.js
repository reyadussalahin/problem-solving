// problem name: Lose it!
// problem link: https://codeforces.com/problemset/problem/1176/C
// contest link: https://codeforces.com/contest/1176
// author: reyad
// time: (?)

'use strict';

function main() {
	let n = nextInt();
	let count = [0, 0, 0, 0, 0, 0];
	// 4,8,15,16,23,42 
	let pos = {
		4  : 0,
		8  : 1,
		15 : 2,
		16 : 3,
		23 : 4,
		42 : 5
	};

	let ans = 0;
	for(let i=0; i<n; i++) {
		let a = nextInt();
		let at = pos[a];
		if(at == 0) count[at]++;
		else {
			if(count[at-1] > 0) {
				count[at-1]--;
				count[at]++;
			}
			else ans++;
		}
	}

	for(let i=0; i<5; i++) {
		ans += (i+1) * count[i];
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
