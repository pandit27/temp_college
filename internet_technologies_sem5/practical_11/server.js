const express = require('express')
const app = express()
const path = require('path')

app.use(express.static('public'))
app.set('view engine', 'ejs')

const pathfile = path.join(__dirname, 'public');

app.get('/', (req, res) => {
    res.sendFile(`${pathfile}/index.html`);
})

const port = process.env.PORT || 4000;

app.listen(port, () => {
    console.log(`server is running on port ${port}`);
})