// problem name: Sorted Adjacent Differences
// problem link: http://codeforces.com/contest/1339/problem/B
// contest link: http://codeforces.com/contest/1339/
// time: (?)
// author : aman


// other_tags: sortings
// difficulty_level: beginner


//Input Template
//==================================================
const readline = require('readline');
const fs = require('fs');
var bufInd=0,buffer = new Array();


function createReadObject() {
	read = readline.createInterface( {
    	//input: process.stdin,
    	input: fs.createReadStream('input.txt'),
    	output: process.stdout,
    	terminal: false
	} );
}

function loadBuffer(inpLine) {
	var t = inpLine.split(" ");
	for(var i of t)
		buffer.push(i);
}

function getString() {
	try {
		return buffer[bufInd++];
	} catch(e) {
		console.log(e);
	}	
}


function inpNumber() {
	var integer = +getString();
	return integer;
}

function inpString() {
	var string = getString();
	return string;
}


//================================================


//Main Function containing solution
function main() {
	var t;
	t = inpNumber();
	//console.log(t);

	while (t>0) {
		let n;
		let ar = new Array();
		n = inpNumber();

		for (let i = 0; i<n; i++) {
			ar.push(inpNumber());
		}

		ar.sort( (a,b) => {
			return a-b;
		});

		let pivot = Math.floor((n+1)/2) - 1;
		let res = ar[pivot].toString();
		for(let i=1; i<n/2+1; i++) {
			if (pivot+i < n)
				res += " "+ar[pivot+i].toString();
			if (pivot-i > -1)
				res += " "+ar[pivot-i].toString();
		}

		console.log(res);
		t--;
	}
}


//take whole input at once and call solution function
createReadObject();
read.on('line',(inp) => {
	loadBuffer(inp);
});
read.on('close',() => {
	main();
});