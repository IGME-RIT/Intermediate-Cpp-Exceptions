/*
Exceptions
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



// Include iostream for output during the program.
#include <iostream>
using namespace std;



// Exceptions give you a way have your program react to unexpected circumstances.
// Under those circumstances, an exception can be thrown.
// This will send the computer backwards through the stack, ignoring everything until it is caught and handled.

// The standard library provides some basic exception types, but really, an object of any type can be thrown, including primitives.


// A function that throws an exception may look like something like this:
float divide(float top, float bottom)
{
    if (bottom == 0)                    // The bottom number can't be zero.
    {
        throw "Can't divide by zero!";  // Throw an exception, the object being thrown is a string. 
        cout << "this won't happen";    // This stops executing the rest of the function and exits the stack frame immediately.
    }
    else
    {
        return top / bottom;    // If the bottom number isn't zero, we can just divide and return the result.
    }
}



// It's a little weird to throw a string though, so the standard library has a base exception class that we can use.
#include <exception>

class DivideByZeroException : public exception  // Create our own exception class that inherits from the base exception class.
{
    virtual const char* what() const throw()    // This overrides the base exceptions what function, which returns a string
    {
        return "Don't divide by zero!";
    }
};



// Now, a better implementation of our divide function:
float betterDivide(float top, float bottom)
{
    if (bottom == 0)
    {
        throw DivideByZeroException();  // Throw our new dividebyzero exception type object.
    }
    else
    {
        return top / bottom;    // Same as before.
    }
}


// Now we need to write code that handles the exceptions.

int main() 
{
    // Now, if we just call divide, we should get a result.

    // This is a try-catch block. It has two parts:
    cout << "string throw test:" << endl;
    try // First comes the try block. Any code inside the try will be run normally, unless an exception is thrown.
    {
        cout << "divide(1, 2): " << divide(1, 2) << endl;   // This line will run.
        cout << "divide(1, 0): " << divide(1, 0) << endl;   // This line will throw an exception before printing, which skips directly to the catch block.
        cout << "divide(1, 3): " << divide(1, 3) << endl;   // This line will not run.
    }
    catch (char* message)           // The catch block can have an exception object type to handle.
    {                               // If the an object matching this type is thrown, this code will be run with that object.
        
        cout << message << endl;    // Here we print out the string that was thrown (if one is thrown)
    }
    cin.get();





    // It's possible to nest try catch blocks like so:
    try
    {
        cout << "nested try-catch test:" << endl;
        try
        {
            cout << "divide(1, 2): " << divide(1, 2) << endl;   // This line will run.
            cout << "divide(1, 0): " << divide(1, 0) << endl;   // This line will throw.
            cout << "divide(1, 3): " << divide(1, 3) << endl;   // This line will not run.
        }
        catch (int pretendErrorCode)    // If the catch doesn't have the correct type, it will throw the exception up to the next scope.
        {                               // This will repeat until the program catches the exception, or crashes.
            cout << "errorCode: " << pretendErrorCode << endl;
        }
    }
    catch (char* message)   // Here we catch the exception.
    {
        cout << message << endl;
    }
    cin.get();



    cout << "simpler multiple catch statement:" << endl;

    // If all of the code is going to be inside the same try block anyway you can chain catch blocks like this:
    try
    {
        cout << "betterDivide(1, 2): " << betterDivide(1, 2) << endl;   // This line will run.
        cout << "betterDivide(1, 0): " << betterDivide(1, 0) << endl;   // This line will throw.
        cout << "betterDivide(1, 3): " << betterDivide(1, 3) << endl;   // This line will not run.
    }
    catch(char* message)
    {
        cout << message << endl;
    }
    catch (exception& ex)   // Since our DivideByZero exception inherits from exception, we can catch it like this.
    {
        cout << ex.what() << endl;  // Call our overriden what function to get the exception message.
    }
    cin.get();


    // There is some conroversy over wether exceptions should be used or not.
    // On one hand, they allow us to avoid certain unavoidable problems.
    // On the other hand, they can be slow, and make following programs extremely difficult when overused.
    // Generally, you should not use exceptions unless there is no alternative ie when using code that already uses them, or in constructors.
    // Deciding if you should or shouldn't use exceptions is a decision that should be made on a per-project basis, and knowing what to do comes with experience.

    return 0;
}