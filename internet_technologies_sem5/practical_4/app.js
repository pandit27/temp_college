const express = require('express');
const app = express();
const path = require('path');
const port = process.env.PORT || 4000;

app.set('view engine', 'ejs');
app.use(express.static('public'));

const pathfile = path.join(__dirname, 'public');

app.get('/', (req, res) => {
    res.sendFile(`${pathfile}/index.ejs`);
});

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});