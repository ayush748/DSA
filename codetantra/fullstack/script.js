// Initial data
let users = [
    { name: "Alice", age: 25 },
    { name: "Bob", age: 30 },
    { name: "Charlie", age: 22 }
];
let dashboard = document.getElementById('dashboard');
// Function to render all users
function renderUsers() {
    // Clear previous content
    dashboard.innerHTML = "";

    // Loop through users array and create cards
    users.forEach(user => {
        let card = document.createElement('div');
        card.className = "card";
        card.innerHTML = `
            <h3>${user.name}</h3>
            <p>Age: ${user.age}</p>
        `;
        dashboard.appendChild(card);
    });
}
// Initial render
renderUsers();
// Add new user dynamically
document.getElementById('addUserBtn').addEventListener('click', () => {
    let name = document.getElementById('nameInput').value.trim();
    let age = parseInt(document.getElementById('ageInput').value);
    if(name && !isNaN(age)) {
        // Add to data array
        users.push({ name, age });
        // Render updated dashboard
        renderUsers();
        // Clear input fields
        document.getElementById('nameInput').value = "";
        document.getElementById('ageInput').value = "";
    } else {
        alert("Please enter valid name and age");
    }
});