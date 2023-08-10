const { response } = require("express");


// declare variables
const signinForm = document.querySelector('#signinForm');
const signupForm = document.querySelector('#signupForm');


// signIn function
let signIn = () => {
    const formData = new FormData(signinForm);

    fetch('/sigin', {
        method: 'POST',
        body: formData
    })
        .then(response => response.json())
        .then(data => {
            if (data.success) {
                window.location.href = '/welcome.html';
            }
            else {
                alert('Sign In Failed. Please check your credentials again');
            }
        })
        .catch(error => {
            console.log(`Error: ${error}`);
        });
};


// signUp function
let signUp = () => {
    const formData = new FormData(signupForm);

    fetch('/sigup', {
        method: 'POST',
        body: formData
    })
        .then(response => response.json())
        .then(data => {
            if (data.success) {
                window.location.href = '/index.html';
            }
            else {
                alert('Sign Up Failed. Please check your credentials again');
            }
        })
        .catch(error => {
            console.log(`Error: ${error}`);
        });
};