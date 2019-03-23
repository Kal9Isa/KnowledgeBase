
/**
 * This function should calculate the total amount of pet food that should be
 * ordered for the upcoming week.
 * @param numAnimals the number of animals in the store
 * @param avgFood the average amount of food (in kilograms) eaten by the animals
 * 				each week
 * @return the total amount of pet food that should be ordered for the upcoming
 * 				 week, or -1 if the numAnimals or avgFood are less than 0 or non-numeric
 */
function calculateFoodOrder(numAnimals, avgFood) {
    // IMPLEMENT THIS FUNCTION!
    if ((numAnimals < 0 || typeof numAnimals != "number") || (avgFood < 0 || typeof avgFood != "number")) {
        return -1;
    }
    else {
        return numAnimals * avgFood;
    }

}

/**
 * Determines which day of the week had the most nnumber of people visiting the
 * pet store. If more than one day of the week has the same, highest amount of
 * traffic, an array containing the days (in any order) should be returned.
 * (ex. ["Wednesday", "Thursday"]). If the input is null or an empty array, the function
 * should return null.
 * @param week an array of Weekday objects
 * @return a string containing the name of the most popular day of the week if there is only one most popular day, and an array of the strings containing the names of the most popular days if there are more than one that are most popular
 */
function mostPopularDays(week) {
    // IMPLEMENT THIS FUNCTION!
    if (!week.length  === 0 || week === null) {
        return null;
    }
    else {
       var tmpstck = [];
       tmpstck.push(week[0]);
       for (var i = 1; i < week.length; i++) {
          if (week[i].traffic > tmpstck[0].traffic) {
              for (var item of tmpstck) {
                  tmpstck.pop();
              }
              tmpstck.push(week[i]);
          }
          else if (week[i].traffic === tmpstck[0].traffic) {
              tmpstck.push(week[i]);
          }
          else {
              continue;
          }
       }
    }
    if (tmpstck.length === 1) {
        return tmpstck[0].name;
    }
    else {
        return (tmpstck);
    }
}


/**
 * Given three arrays of equal length containing information about a list of
 * animals - where names[i], types[i], and breeds[i] all relate to a single
 * animal - return an array of Animal objects constructed from the provided
 * info.
 * @param names the array of animal names
 * @param types the array of animal types (ex. "Dog", "Cat", "Bird")
 * @param breeds the array of animal breeds
 * @return an array of Animal objects containing the animals' information, or an
 *         empty array if the array's lengths are unequal or zero, or if any array is null.
 */
 function dataValidation (array1, array2, array3) {
     if (!array1.length === 0 || !array2.length === 0, !array3.length === 0) {
         return null;
     }
     else if (array1.length !== array2.length || array2.length !== array3.length || array1.length !== array3.length) {
         return emptyArray;
     }
     else if (array1 === null || array2 === null || array3 === null) {
         return null;
     }
     else {
       return true;
     }
 }

function createAnimalObjects(names, types, breeds) {
    // IMPLEMENT THIS FUNCTION!
    if (dataValidation === null) {
        return [];
    }
    else {
        var outputArray = [];
        for (var i = 0; i < names.length; i++) {
            var animalInstc = new Animal (names[i], types[i], breeds[i]);
            outputArray.push(animalInstc);
        }
        return outputArray;
    }
}

/////////////////////////////////////////////////////////////////
//
//  Do not change any code below here!
//
/////////////////////////////////////////////////////////////////


/**
 * A prototype to create Weekday objects
 */
function Weekday (name, traffic) {
    this.name = name;
    this.traffic = traffic;
}

/**
 * A prototype to create Item objects
 */
function Item (name, barcode, sellingPrice, buyingPrice) {
     this.name = name;
     this.barcode = barcode;
     this.sellingPrice = sellingPrice;
     this.buyingPrice = buyingPrice;
}
 /**
  * A prototype to create Animal objects
  */
function Animal (name, type, breed) {
    this.name = name;
     this.type = type;
     this.breed = breed;
}


/**
 * Use this function to test whether you are able to run JavaScript
 * from your browser's console.
 */
function helloworld() {
    return 'hello world!';
}
