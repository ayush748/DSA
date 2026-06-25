// Used for variables whose value changes.
if(true){
    let a=10;
    console.log(a);
}
// console.log(a); ReferenceError: a is not defined - let has block scope

let b = 20;
b = 30; // reassignment is allowed
console.log(b); // 30

let a = 40; // redeclaration in the same scope is not allowed, but this is a new block scope
console.log(a); // 40

// What is Temporal Dead Zone (TDZ)?
// The time between:
// 	• variable hoisting
// 	• variable initialization
// During this period variable cannot be accessed.

// Layman Example of TDZ
// Imagine food ordered in restaurant:
// 	• order placed
// 	• food not delivered yet
// You cannot eat it yet.
// Similarly variable exists internally but cannot be used until initialized.
console.log(c); // ReferenceError: Cannot access 'c' before initialization - 'c' is in TDZ
let c = 50;
console.log(c); // 50 - now 'c' is initialized and can be accessed


let user;
console.log(user); // undefined - variable is declared but not initialized
