const Joi = require('joi');
const mongoose = require('mongoose');

const genreSchema = new mongoose.Schema({   //genre DB schema
  name: {
    type: String,
    required: true,
    minlength: 5,
    maxlength: 50
  }
});

const Genre = mongoose.model('Genre', genreSchema);

function validateGenre(genre) {   //validate genre
  const schema = {
    name: Joi.string().min(3).required()
  };

  return Joi.validate(genre, schema);
}

exports.genreSchema = genreSchema;
exports.Genre = Genre; 
exports.validate = validateGenre;