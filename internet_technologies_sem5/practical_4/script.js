// variables
const list = document.querySelector('#multiplication_list');

// function to create a random color
let randomColor = () => {
    const colors = ['#ff5733', '#33ff77', '#3377ff', '#ff33cc', '#ffff33'];
    return colors[Math.floor(Math.random() * colors.length)];
};

// function to create a random font size
let randomFontSize = () => {
    return Math.floor(Math.random() * 10) * 16;
};

// function to create multiplication row
let createListItem = (content) => {
    const li = document.createElement('li');
    li.textContent = content;
    li.style.color = randomColor();
    li.style.fontSize = randomFontSize();
    return li;
};

// function to update multiplication table
let updateMultiplicationTable = () => {
    list.innerHTML = '';

    for (let i = 2; i <= 10; i++) {
        const listItemContent = [];

        for (let j = 1; j <= 10; j++) {
            listItemContent.push(`${i} x ${j} = ${i * j}`);
        }

        const listItem = createListItem(listItemContent.join(', '));
        list.appendChild(listItem);
    }
};

// setInterval function
updateMultiplicationTable();
// setInterval(updateMultiplicationTable, 1000);