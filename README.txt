Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Exceptions Tutorial!
Prerequesites: Assert

An exception is just like an assert, but the opposite.
If an assert condition returns false, it stops the debugger and
shows the error. An exception happens inside an actual if-statement.
Inside the "assert" function, it uses exception, so this is how 
"assert" works.

Reminder, when you run this example, it is supposed to crash,
and the debugger shows you why it crashes, that's why exceptions are useful,
they help you fix buggy code.

To throw an exception, you simply type this code:
	throw "error message";
This will stop the debugger, and print the error message

Here is an example:

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
