document.addEventListener('DOMContentLoaded', () => {
    const form = document.querySelector('#petForm');

    form.addEventListener('submit', (e) => {
        e.preventDefault();

        const name = document.querySelector('#name').value;
        const age = parseInt(document.querySelector('#age').value);
        const weight = parseFloat(document.querySelector('#weight').value);
        const type = document.querySelector('#type').value;
        const description = document.querySelector('#description').value;

        const pet = {
            name: name,
            age: age,
            weight: weight,
            type: type,
            description: description
        };

        console.log('Pet Object:', pet);
        console.log('Pet JSON:', JSON.stringify(pet));
    });
});