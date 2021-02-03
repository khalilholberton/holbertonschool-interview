#!/usr/bin/node
const request = require('request');
const arg = process.argv[2];
const U = 'https://swapi-api.hbtn.io/api/films/' + arg;
request(U, (e, tot, body) => {
  if (!e) { charac(JSON.parse(body).characters, 0); }
});
function charac (path, i) {
  request(path[i], (e, tot, body) => {
    if (!e) {
      console.log(JSON.parse(body).name);
      if (i + 1 < path.length) charac(path, ++i);
    }
  });
}
