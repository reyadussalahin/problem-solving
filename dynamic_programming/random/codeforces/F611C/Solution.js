// problem name: New Year and Domino
// problem link: https://codeforces.com/problemset/problem/611/C
// contest link: https://codeforces.com/contest/611
// author: reyad
// time: (?)

'use strict';

function main() {
	let h = nextInt();
	let w = nextInt();
	let a = [];
	let u = [];
	let l = [];
	for(let i=0; i<h; i++) {
		a.push([]);
		u.push([]);
		l.push([]);
		let b = nextLine().split('');
		for(let j=0; j<w; j++) {
			let x = (b[j] === '.') ? 0 : 1;
			a[i].push(x);
			u[i].push(0);
			l[i].push(0);
		}
	}

	for(let i=0; i<h; i++) {
		for(let j=1; j<w; j++) {
			if(a[i][j] == 0 && a[i][j-1] == 0) l[i][j] = l[i][j-1] + 1;
			else l[i][j] = l[i][j-1];
		}
	}
	for(let i=1; i<h; i++) {
		for(let j=0; j<w; j++) {
			if(a[i][j] == 0 && a[i-1][j] == 0) u[i][j] = u[i-1][j] + 1;
			else u[i][j] = u[i-1][j];
		}
	}

	let n = nextInt();
	for(let i=0; i<n; i++) {
		let x = nextInt() - 1;
		let y = nextInt() - 1;
		let x2 = nextInt() - 1;
		let y2 = nextInt() - 1;

		let ans = 0;
		for(let i=y; i<=y2; i++) {
			ans += u[x2][i] - u[x][i];
		}
		for(let i=x; i<=x2; i++) {
			ans += l[i][y2] - l[i][y];
		}
		console.log(ans);
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
