# cpp-json-library
C++ library dedicated to handling JSON data

## Current Method
Each key in a json file can correspond to 3 different types in typescript: `number`, `string` and `Object`. As such, this library allows a user to add new elements to a json object by use of polymorphism rather than templates. The main reason for this is that a template would imply a much greater degree of flexibility than polymorphism, as one could infer that any type should be allowed. Similarly, templates would likely result in more runtime errors which are harder to debug than compilation errors.
This then means that the supported C++ types for this library are:
- `std::string`
- `char*`
- `double`
- `int`
- `JSONObject` (defined as part of this library)
Later down the line I may choose to make my own custom types with the `JSON` namespace called `string` and `number` to match the already present `JSONObject` class.
