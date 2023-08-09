document.addEventListener('DOMContentLoaded', () => {
    const petList = document.querySelector('.pet_list');

    // load pet data using AJAX
    const request = new XMLHttpRequest();
    request.open('GET', 'petData.json', true);
    request.onload = () => {
        if (request.status === 200) {
            const pets = JSON.parse(request.responseText);
            displayData(pets);
        }
    }
    request.send();

    // fucntion to display data
    const displayData = (pets) => {
        let json = '';

        pets.forEach(pet => {
            json += `
                <div class = 'pet'>
                    <h3>${pet.name}</h3>
                    <p>Age: ${pet.age}</p>
                    <p>Weight: ${pet.weight}</p>
                    <p>Type: ${pet.type}</p>
                    <p>Description: ${pet.description}</p>
                </div>
            `;
        })

        petList.innerHTML = json;
    }
});
