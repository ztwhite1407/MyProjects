//jshin esversion:6

const mongoose = require('mongoose');

mongoose.connect("mongodb://localhost:27017/fruitsDB", { useNewUrlParser: true});


const fruitSchema = new mongoose.Schema ({
  name: {
    type: String,
    require: [true, "Please check your data entry, no name specified!"]
  },
  rating: {
    type: Number,
    min: 1,
    max: 10
  },
  review: String
});

const Fruit = mongoose.model("Fruit", fruitSchema);

const fruit = new Fruit ({
  rating: 10,
  review: "Peaches are so yummy!"
});

//fruit.save();

const personSchema = new mongoose.Schema({
  name: String,
  age: Number,
  favoriteFruit: fruitSchema
});

const Person = mongoose.model("Person", personSchema);

const mango = new Fruit ({
  name: "Mango",
  rating: 6,
  review: "Decent fruit."
});

mango.save();

Person.updateOne({name: "John"}, {favoriteFruit: mango}, function(err) {
  if (err) {
    console.log(err);
  } else {
    console.log("Successfully updated the document");
  }
})
// const person = new Person({
//   name: "Amy",
//   age: 12,
//   favoriteFruit: pineapple
// });

//person.save();



Fruit.find(function(err, fruits){
  if (err) {
    console.log(err);
  } else {


    fruits.forEach(function(fruit){
      console.log(fruit.name);
    });
  }
});

// Fruit.updateOne({_id: "5e89c2d65086d000604c1823" }, {name: "Peach"}, function(err) {
//   if (err) {
//     console.log(err);
//   } else {
//     console.log("Succesfully updated the document");
//   }
// });

// Fruit.deleteOne({name: "Pinapple"}, function(err) {
//   if (err) {
//     console.log(err);
//   } else {
//     console.log("Succesfully deleted the document");
//   }
// });

// Person.deleteMany({name: "John"}, function(err) {
//   if (err) {
//     console.log(err);
//   } else {
//     console.log("Successfully deleted the entire document");
//   }
// });
