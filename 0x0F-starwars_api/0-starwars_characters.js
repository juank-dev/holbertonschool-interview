#!/usr/bin/node
/* Star Wars Characters */
const request = require('request');
const api = 'https://swapi-api.hbtn.io/api/films/';
const movieId = process.argv[2];
// query API
request(api + movieId, (error, response, body) => {
  if (error) throw error;
  const characters = JSON.parse(body).characters;
  viewNames(characters);
});
// view results
const viewNames = (names, i = 0) => {
  if (i === names.length) return;
  request(names[i], (error, response, body) => {
    if (error) throw error;
    console.log(JSON.parse(body).name);
    viewNames(names, i + 1);
  });
};
