// declare variables
const para = document.querySelector('.para');
const red = document.querySelector('.red');
const green = document.querySelector('.green');
const blue = document.querySelector('.blue');
const ten = document.querySelector('.ten');
const twenty = document.querySelector('.twenty');
const thirty = document.querySelector('.thirty');
const cursive = document.querySelector('.cursive');
const cnew = document.querySelector('.cnew');
const tnr = document.querySelector('.tnr');

red.addEventListener('click', (e) => {
    para.style.color = 'red';
});

blue.addEventListener('click', (e) => {
    para.style.color = 'blue';
});

green.addEventListener('click', (e) => {
    para.style.color = 'green';
});

ten.addEventListener('click', (e) => {
    para.style.fontSize = '10px';
});

twenty.addEventListener('click', (e) => {
    para.style.fontSize = '20px';
});

thirty.addEventListener('click', (e) => {
    para.style.fontSize = '30px';
});

cursive.addEventListener('click', (e) => {
    para.style.fontFamily = 'cursive';
});

cnew.addEventListener('click', (e) => {
    para.style.fontFamily = 'Courier New';
});

tnr.addEventListener('click', (e) => {
    para.style.fontFamily = 'Times New Roman';
});
