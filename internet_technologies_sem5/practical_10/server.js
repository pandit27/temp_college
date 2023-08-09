/*
    Create a HTTP server using Node.js which handles requests on port 10000 or a free port beyound 10000. Modify the server in such a way that opening localhost:10000 will display "Hello world, This is my Node.js server" on browser.
*/
const http = require('http');
const port = 10000 || process.env.PORT;

http.createServer((req, res) => {
    res.write('Hello World');
    console.log(`Server is running on port ${port}`);
    res.end();
}).listen(port);