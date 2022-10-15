const {Genre, validate} = require('../models/genre');
const mongoose = require('mongoose');
const express = require('express');
const router = express.Router();

router.get('/', async (req, res) => {   //will return all genres
  const genres = await Genre.find().sort('name');
  res.send(genres);
});

router.post('/', async (req, res) => {    //will create new genre
  const { error } = validate(req.body); 
  if (error) return res.status(400).send(error.details[0].message); //log err msg if any validation err

  let genre = new Genre({ name: req.body.name });
  genre = await genre.save(); //saving genre
  
  res.send(genre);  //sending genre info back
});

router.put('/:id', async (req, res) => {  //updating genre info
  const { error } = validate(req.body); 
  if (error) return res.status(400).send(error.details[0].message);

  const genre = await Genre.findByIdAndUpdate(req.params.id, { name: req.body.name }, {
    new: true
  });

  if (!genre) return res.status(404).send('The genre with the given ID was not found.');
  
  res.send(genre);
});

router.delete('/:id', async (req, res) => { //deleting genre
  const genre = await Genre.findByIdAndRemove(req.params.id);

  if (!genre) return res.status(404).send('The genre with the given ID was not found.');

  res.send(genre);
});

router.get('/:id', async (req, res) => {  //accessing genre by genre id
  const genre = await Genre.findById(req.params.id);

  if (!genre) return res.status(404).send('The genre with the given ID was not found.');

  res.send(genre);
});

module.exports = router;