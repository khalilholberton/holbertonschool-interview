#!/usr/bin/node

const ar = process.argv[2];
const reqU = require('util');
const reqR = require('request');
const request = reqU.promisify(reqR);

async function starwars (idx) {
  const req = await (await request('https://swapi-api.hbtn.io/api/films/' + idx)).body;
  const obJSON = JSON.parse(req);
  const charVar = obJSON.charVar;
  let ctr = 0;

  while (ctr < charVar.length) {
    const space = charVar[ctr];
    const info = await (await request(space)).body;
    const d = JSON.parse(info);
    console.log(d.name);
    ctr++;
  }
}

starwars(ar[0]);
