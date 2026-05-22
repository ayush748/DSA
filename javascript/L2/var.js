// var Creates Problems?
// Because:
// 	• no block scope
// 	• allows redeclaration
//  • confusing hoisting behavior


if(true) {
    var a = 10;
}
console.log(a); // 10 - var has function scope, not block scope

function test(){
    var a = 20;
    console.log(a); // 20
}
console.log(a); // 10 - var is function scoped, so it does not affect the global variable 'a'

var a = 30; // redeclaration is allowed
console.log(a); // 30

// Hoisting: var declarations are hoisted to the top of their scope, but not their assignments
console.log(b); // undefined - 'b' is hoisted but not assigned
var b = 40;
console.log(b); // 40

function solve(){
    console.log(c); // undefined - 'c' is hoisted but not assigned
    var c = 50;
    console.log(c); // 50
}
solve();
// console.log(c);  ReferenceError: c is not defined - 'c' is function scoped and not accessible outside the function solve()

var x = 100;
var x = 200; // redeclaration is allowed
console.log(x); // 200 - the last assignment takes precedence