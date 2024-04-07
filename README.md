# Sign-Up Application

we're going to be writing a user registration application. This will allow users to register with the system, providing both their name and age, and we'll store this information in our own custom type. We'll also provide the ability for a user to be looked up by an ID, retrieving their information.
## Features

Figure : Our application allows the user to add records and then recall them via an ID

This activity will put everything you've learned in this chapter to the test, extending the exercise we did when looking at containers. You'll also lean on skills learned previously, such as looping, branching, and reading user input. Let's get started.

Here are the steps to complete the activity:

- Start by including the various headers that the application will need.
- Next, define the class that will represent a record in the system. This is going to be a person, containing both a name and an age. Also, declare a array of this type to store these records. A vector is used for the flexibility it gives in not having to declare an array size upfront.
- Now, you can start adding some functions to add and fetch records; first, add. A record consists of a name and age, so write a function that will accept those two as parameters, create a record object, and add it to our record vector. Name this function Add Record.
- Add a function to fetch a record. This function should accept one parameter (a user ID) and return the record for that user. Name this function Fetch Record.
- Enter the main function and start the body of the application. Start with an outer main loop, as you used in the last chapter, and output some options to the user. You will give them three options: Add Record, Fetch Record, and Quit.
- Present these options to the user and then capture their input.
- There are three possible branches now, depending on user input, which we'll handle with a switch statement. Case 1 is adding a record, and to do so, you'll get the user's name and age from the user and then make a call to our AddRecord function.
- The next case is the user wanting to fetch a record. For this, you need to get a user ID from the user and then make a call to FetchRecord, outputting its result.
